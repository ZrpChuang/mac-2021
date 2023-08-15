/****************************************************/
/* File: scan.c                                     */
/* The scanner implementation for the TINY compiler */
/****************************************************/
#include "globals.h"
#include "util.h"
#include "scan.h"

/* states in scanner DFA */
typedef enum
   { START,INASSIGN,INCOMMENT,INNUM,INID,DONE }
   StateType;//暂时不知道是干什么的

/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];

/* BUFLEN = length of the input buffer for
   source code lines */
#define BUFLEN 256

static char lineBuf[BUFLEN]; /* holds the current line */   //保存当前行的内容
static int linepos = 0; /* current position in LineBuf */   //现在的位置
static int bufsize = 0; /* current size of buffer string */
static int EOF_flag = FALSE; /* corrects ungetNextChar behavior on EOF */

/* getNextChar fetches the next non-blank character
   from lineBuf, reading in a new line if lineBuf is
   exhausted */
static int getNextChar(void)   //获得下一字符
{ if (!(linepos < bufsize))
  { lineno++;
    if (fgets(lineBuf,BUFLEN-1,source))
    { if (EchoSource) fprintf(listing,"%4d: %s",lineno,lineBuf);
      bufsize = strlen(lineBuf);
      linepos = 0;
      return lineBuf[linepos++];
    }
    else
    { EOF_flag = TRUE;
      return EOF;
    }
  }
  else return lineBuf[linepos++];
}

/* ungetNextChar backtracks one character
   in lineBuf */
static void ungetNextChar(void)  //用于回吐字符
{ if (!EOF_flag) linepos-- ;}

/* lookup table of reserved words */
static struct
    { char* str;
      TokenType tok;
    } reservedWords[MAXRESERVED]
   = {{"if",IF},{"then",THEN},{"else",ELSE},{"end",END},
      {"repeat",REPEAT},{"until",UNTIL},{"read",READ},
      {"write",WRITE}};//一共7个保留字

/* lookup an identifier to see if it is a reserved word */
/* uses linear search */
static TokenType reservedLookup (char * s)
{ int i;
  for (i=0;i<MAXRESERVED;i++)
    if (!strcmp(s,reservedWords[i].str))
      return reservedWords[i].tok;
  return ID;//相当于是给标识符进行一个分流
}

/****************************************/
/* the primary function of the scanner  */
/****************************************/
/* function getToken returns the 
 * next token in source file
 */

TokenType getToken(void)
{  /* index for storing into tokenString */
   int tokenStringIndex = 0;

   /* holds current token to be returned */
   TokenType currentToken ;//表示的是类型

   /* current state - always begins at START */
   StateType state = START;//状态

   /* flag to indicate save to tokenString */
   int save;

   while (state != DONE)
   { int c = getNextChar();//一次就一个字符，结束了就退出while了
     if(EOF_flag) return ENDFILE;
     printf("%c",c);
     save = TRUE;//初始化
     TraceScan = TRUE;

     switch (state)//一开始是开始状态
     { case START:
          // printf("start!");
         if (isdigit(c)){
           state = INNUM;
           currentToken = NUM;
           save = TRUE;
         }
         //此处请自己填写（字符、:、空格/tab/换行、{、算符及界符等）
         //ASSIGN,EQ,  LT,PLUS,MINUS,TIMES,OVER,LPAREN,RPAREN,SEMI
         //赋值    等于    +   -       *     >
         else if(c == '+' )  {
             state = DONE;
             currentToken = PLUS;
             save = TRUE;
         }
         else if(c == '-' )  {
             state = DONE;
             currentToken = MINUS;
             save = TRUE;
         }
         else if(c == '*' )  {
             state = DONE;
             currentToken = TIMES;
         }
         else if(c == '/' )  {
             state = DONE;
             currentToken = OVER;
         }
         else if(c == '=' )  {
             state = DONE;
             currentToken = EQ;
         }
         else if(c == ';' )  {
             state = DONE;
             currentToken = SEMI;
         }//部分运算符
         else if(isspace(c)){//如果是空白的处理方式就是继续设置为开始
             save = FALSE;
             state = START;
             currentToken = ID;
         }
         else if(isalpha(c)){
             state = INID;//如果是字母开头直接识别为ID
         }
         else if(c == '{'){
             save = FALSE;
             state = INCOMMENT;
         }
         else if(c == ':'){
             state = INASSIGN;
             save = TRUE;
             currentToken = ASSIGN;

         }
         break;
       case INCOMMENT://这个似乎是注释
            if(c == '}'){
                 save = FALSE;
                 state = DONE;
                 TraceScan = FALSE;
            }
            else if(c != '}'){
                 save = FALSE;
                 state = INCOMMENT;
                 TraceScan = FALSE;                 
            }
            //此处请自己填写，仅出现‘}’或EOF（注释未完结束程序）时才改变状态。
         break;
       case INASSIGN:
           if(c == '='){
               save = TRUE;
               state = DONE;
               currentToken = ASSIGN;
           }
           else {
               state = DONE;
               save = FALSE;
               printf("somethings wrong");
           }
           //此处请自己填写，‘=’或其它（出现错误）
         break;
       case INNUM:
         if (!isdigit(c))//进入了读取num状态，如果读取的不是num吐出去
         { /* backup in the input */
           ungetNextChar();
           save = FALSE;
           state = DONE;
           currentToken = NUM;
         }
         else{
          save = TRUE;
          state = INNUM;
          currentToken = NUM;
         }
         break;
       case INID:
           if(!isalpha(c)){
               ungetNextChar();
               save = FALSE;
               state = DONE;
               currentToken = ID;
           }
           else{
            save = TRUE;
            state = INID;
            currentToken = ID;
           }
           //此处请自己填写，不是字符则回吐，并进入DONE，且识别出一个ID
         break;
       case DONE:
            printf("done!");
       default: /* should never happen */
         fprintf(listing,"Scanner Bug: state= %d\n",state);
         state = DONE;
         currentToken = ERROR;
         break;
     }
     if ((save) && (tokenStringIndex <= MAXTOKENLEN))
       tokenString[tokenStringIndex++] = (char) c;
     if (state == DONE)
     { tokenString[tokenStringIndex] = '\0';
       if (currentToken == ID)//
         currentToken = reservedLookup(tokenString);//保留字匹配
     }
   }
   if (TraceScan) {
     fprintf(listing,"\t%d: ",lineno);
     printToken(currentToken,tokenString);
   }
   return currentToken;
} /* end getToken */

