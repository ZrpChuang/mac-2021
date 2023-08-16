/****************************************************/
/* File: parse.c                                    */
/* The parser implementation for the TINY compiler  */
/****************************************************/

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

static TokenType token; /* holds current token */
//外部变量


/* function prototypes for recursive calls */

static TreeNode * stmt_sequence(void);//语句序列
static TreeNode * statement(void);//单个语句
static TreeNode * if_stmt(void);//条件语句
static TreeNode * repeat_stmt(void);//重复语句
static TreeNode * assign_stmt(void);//赋值语句
static TreeNode * read_stmt(void);//读取
static TreeNode * write_stmt(void);//写语句
static TreeNode * exp(void);//复杂表达式
static TreeNode * simple_exp(void);//简单表达式
static TreeNode * term(void);
static TreeNode * factor(void);

static void syntaxError(char * message)
{ fprintf(listing,"\n>>> ");
  fprintf(listing,"Syntax error at line %d: %s",lineno,message);//多少行吗？
  Error = TRUE;
}

static void match(TokenType expected)
{ if (token == expected) token = getToken();//获取下一个token
  else {
    syntaxError("unexpected token -> ");
    printToken(token,tokenString);
    fprintf(listing,"      ");
  }
}

TreeNode * stmt_sequence(void)
{ 
  TreeNode * t = statement();
  TreeNode * p = t;

  while ((token!=ENDFILE) && (token!=END) &&
         (token!=ELSE) && (token!=UNTIL))
         //这几个else，end，until是因为stmt_不
         //是一开始被调用的，是临时被调用的
         //因此遇到这些就要结束
  { TreeNode * q; 
    match(SEMI);//分号
    q = statement();
    if (q!=NULL) {//如果q==NULL语句序列结束
      if (t==NULL) t = p = q;
      else /* now p cannot be NULL either */
      { 
        p->sibling = q;
        p = q;
      }
    }
  }
  return t;
}

TreeNode * statement(void)//这一层什么也不干，做一个分支
{ TreeNode * t = NULL;
  switch (token) {
    case IF : t = if_stmt(); break;
    case REPEAT : t = repeat_stmt(); break;
    case ID : t = assign_stmt(); break;
    case READ : t = read_stmt(); break;
    case WRITE : t = write_stmt(); break;
    default : syntaxError("unexpected token -> ");
              printToken(token,tokenString);
              token = getToken();
              break;
  } /* end case */
  return t;
}

TreeNode * if_stmt(void)
{          
  TreeNode * t = newStmtNode(IfK);//新建一个if语句节点
  if (t!=NULL) {
    match(IF);//匹配掉IF并且，获取多一个token
    TreeNode * p = exp();//递归下降
    if(p!=NULL) t->child[0] = p;//exp
    //token = getToken();不需要写获取下一个token，因为exp读多了一个token
    if(token == THEN){
      match(THEN);
      p = stmt_sequence();//递归下降
      if(p!=NULL) t -> child[1] = p;//第二个孩子
    }
    //token = getToken();这里是不用写getToken的，因为
    if(token == ELSE){
        match(ELSE);
        p = stmt_sequence();//递归下降
        if(p!=NULL) t -> child[2] = p;//第三个孩子
    }
  }
  match(END);//多读一个符号
  return t;
}

TreeNode * repeat_stmt(void)
{
  TreeNode * t = newStmtNode(RepeatK);//新建一个rp
  if(t != NULL){
    match(token);//进入之前先match
    TreeNode * p = stmt_sequence();
    if(p != NULL) t -> child[0] = p;
    //token = getToken();不用额外写，因为stmt_sequence还是需要的
    match(UNTIL);
    p = exp();
    if(p != NULL) t -> child[1] = p;//第二个孩子
  }
  return t;
}

TreeNode * assign_stmt(void)
{ 
  TreeNode * t = newStmtNode(AssignK);
  if(t != NULL) {
    t -> attr.name = copyString(tokenString);
    match(ID);//匹配掉ID
    match(ASSIGN);//匹配掉ASSIGN
    TreeNode * p = exp();
    if(p != NULL) t -> child[0] = p;//孩子
  }
  return t;
}

TreeNode * read_stmt(void)
{
  TreeNode * t = newStmtNode(ReadK);//构建节点
  if(t != NULL){
      match(READ);
      t -> attr.name = copyString(tokenString);//直接给的
      match(ID);
  }
  return t;
}

TreeNode * write_stmt(void)
{
  TreeNode * t = newStmtNode(WriteK);//构建节点
  if(t != NULL) {
    match(WRITE);
    TreeNode * p = exp();
    if(p != NULL) {
      t -> child[0] = p;//孩子
    }
  }
  return t;
}

TreeNode * exp(void)//会多读一个token
{ TreeNode * t = simple_exp();
  //回来的时候读多了一个token，自己写simple-exp的时候需要注意
  if ((token==LT)||(token==EQ)) {
    
    TreeNode * p = newExpNode(OpK);//构造新的节点
    if (p!=NULL) {
      p->child[0] = t;
      p->lineno = lineno;
      p->attr.op = token;
      t = p;
    }
    match(token);//等价于直接获取下一个token
    if (t!=NULL)
      t->child[1] = simple_exp();//孩子
  }
  return t;
}

TreeNode * simple_exp(void)//这个函数应该是不可避免的多读一个
{
  TreeNode * t = term();//先获取一个term
  //term也要读多一个token
  if((token == PLUS)||(token == MINUS)){
    TreeNode * p = newExpNode(OpK);
    if(p != NULL){
      p->child[0] = t;
      p->attr.op = token;// '+' || '-'
      t = p;
    }
    match(token);
    if(t != NULL) t ->child[1] = term();
  }
  return t;
}

TreeNode * term(void)
{
  TreeNode * t = factor();
  if((token == TIMES) || (token == OVER)){
    TreeNode * p = newExpNode(OpK);
    if(p != NULL){
      p->child[0] = t;
      p->attr.op = token;
      t = p;
    }
    match(token);
    if(t != NULL) t -> child[1] = factor();
  }  
  return t;
}

TreeNode * factor(void)
{
  TreeNode * t  = NULL;
  
  if(token == ID){
      TreeNode * t = newExpNode(IdK);
      t -> attr.name = copyString(tokenString);
      match(token);
      return t;
  }
  else if(token == NUM){
      TreeNode * t = newExpNode(ConstK);
      t->attr.val = atoi(tokenString);
      match(token);
      return t;
  }
  else if(token == LPAREN){
      match(token);
      TreeNode * t = simple_exp();
      match(RPAREN);//匹配掉右括号
      //match(token);
    return t;
  }
  return t;
}

/****************************************/
/* the primary function of the parser   */
/****************************************/
/* Function parse returns the newly 
 * constructed syntax tree
 */


TreeNode * parse(void)
{ 
  TreeNode * t; //定义根节点

  token = getToken(); //进入每个子程序前已读入一个新的token，该例子是READ
  t = stmt_sequence();

  if (token!=ENDFILE)
    syntaxError("Code ends before file\n");

  return t;
}
