/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"

/* counter for variable memory locations */
static int location = 0;

/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ 
  if (t != NULL)//首先不能是空节点
  { 
    preProc(t);//先
    { 
      int i;
      for (i=0; i < MAXCHILDREN; i++)  //3
        traverse(t->child[i],preProc,postProc);
    }//后
    postProc(t);

    traverse(t->sibling,preProc,postProc);//下一句话
  }
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t)
{ if (t==NULL) return;
  else return;
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode( TreeNode * t)//节点插入 先根遍历调用的函数
{ switch (t->nodekind)//根据节点类型分类
  { case StmtK://语句类型的节点
      switch (t->kind.stmt)//什么类型的语句
      { case AssignK://为什么这里空了
        case ReadK:
          if (st_lookup(t->attr.name) == -1)
          /* not yet in table, so treat as new definition */
            st_insert(t->attr.name,t->lineno,location++);//是不是没有给行号码
          else
          /* already in table, so ignore location, 
             add line number of use only */ 
            st_insert(t->attr.name,t->lineno,0);//
          break;
        default:
          break;
      }
      break;
    case ExpK:
      switch (t->kind.exp)
      { case IdK:
          if (st_lookup(t->attr.name) == -1)
          /* not yet in table, so treat as new definition */
            st_insert(t->attr.name,t->lineno,location++);//id的名字
          else
          /* already in table, so ignore location, 
             add line number of use only */ 
            st_insert(t->attr.name,t->lineno,0);
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree)//构造符号表，传入参数是一整个语法树
{ traverse(syntaxTree,insertNode,nullProc);//先根遍历
  if (TraceAnalyze)
  { fprintf(listing,"\nSymbol table:\n\n");
    printSymTab(listing);
  }
}

static void typeError(TreeNode * t, char * message)
{ fprintf(listing,"Type error at line %d: %s\n",t->lineno,message);
  Error = TRUE;
}

/* Procedure checkNode performs
 * type checking at a single tree node  typedef enum {IfK,RepeatK,AssignK,ReadK,WriteK} StmtKind;//
 OpK,ConstK,IdK
 */


static void checkNode(TreeNode * t)
{ switch (t->nodekind)
  { case ExpK:                                            //表达式节点
      switch (t->kind.exp)
      { case OpK:
          if ((t->child[0]->type != Integer) ||
              (t->child[1]->type != Integer))
            typeError(t,"Op applied to non-integer");     //确定是否出现了类型错误
          if ((t->attr.op == EQ) || (t->attr.op == LT))   //分配一个新的字段，确定类型
            t->type = Boolean;                            //boolean
          else
            t->type = Integer;                            //Integer
          break;
        case ConstK:                                      
        case IdK:
          t->type = Integer;                              //ConstK和IdK类型默认是Integer
          break;
        default:
          break;
      }
      break;
    case StmtK:                                           //语句节点
      switch (t->kind.stmt)
      { case IfK:                                         //确定是否出现了类型错误
          if (t->child[0]->type == Integer)
            typeError(t->child[0],"if test is not Boolean");
          break;
        case AssignK:                                     
          if (t->child[0]->type != Integer)
            typeError(t->child[0],"assignment of non-integer value");
          break;
        case WriteK:
          if (t->child[0]->type != Integer)
            typeError(t->child[0],"write of non-integer value");
          break;
        case RepeatK:
          if (t->child[1]->type == Integer)
            typeError(t->child[1],"repeat test is not Boolean");
          break;
        default:
          break;
      }
      break;
    default:
      break;

  }
}












// static void checkNode(TreeNode * t)//节点检查
// { switch (t->nodekind)
//   { 
//     case ExpK:    //表达式
//       switch (t->kind.exp)
//       {
//       case OpK:
//         if(t->attr.op == EQ || t->attr.op == LT){
//           if(t->child[0]->type != Integer || t->child[1]->type != Integer) typeError(t,"比较非整型的数");
//           t->type = Boolean;
//         }
//         else{
//           t->type = Integer;
//         }
//         break;
      
//       case ConstK://不用操作？
//         break;

//       case IdK:
//         t->type = Integer;
//         break;

//       default:
//         break;
//       }
    
//       break;


//     case StmtK://语句类型
//       switch (t->kind.stmt)
//       {
//       case IfK:
        
//         if(t->child[0]->type != Boolean) typeError(t,"if语句中的表达式值不是布尔类型");
//         break;
      
//       case RepeatK:
        
//         if(t->child[1]->type != Boolean) typeError(t,"repeat语句中的表达式值不是布尔类型");
//         break;

//       case AssignK:
//         if(t->child[0]->type != Integer) typeError(t,"assign语句中的赋值不是整型");
//         break;

//       case WriteK:
//         if(t->child[0]->type != Integer) typeError(t,"write语句中的写的值不是整型");
//         break;

//       default:
//         break;
//       }
//       break;         

//     default:
//     break;

//   }
// }












/* Procedure typeCheck performs type checking 
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode * syntaxTree)//语义检查
{ 
  traverse(syntaxTree,nullProc,checkNode);
}
