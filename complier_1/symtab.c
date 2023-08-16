/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the TINY compiler*/
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* SIZE is the size of the hash table */
#define SIZE 211 //长度为211的哈希表

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash ( char * key ) //哈希函数
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* the list of line numbers of the source 
 * code in which a variable is referenced
 */
typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;

/* The record in the bucket lists for
 * each variable, including name, 
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec //符号表条目结构
   { char * name;//名字
     LineList lines;//行链
     int memloc ; /* memory location for variable */
     struct BucketListRec * next;//下一个条目
   } * BucketList;//指向条目的指针

/* the hash table */
static BucketList hashTable[SIZE];//指针连城链结构

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * name, int lineno, int loc )
{ //插入某个id
  int memloc = st_lookup(name);//查看位置
  if(memloc==-1){//没找到，定义新名字
      int h = hash(name);//哈希到位置
      BucketList l =  hashTable[h];//找到哈希表头


      struct BucketListRec * bnode = (struct BucketListRec*)malloc(sizeof(struct BucketListRec));//新定义节点
      bnode->name = name;
      bnode->next = NULL;
      hashTable[h] = bnode;

      struct LineListRec * lnode = (struct LineListRec*)malloc(sizeof(struct LineListRec));//新定义行节点
      lnode ->lineno = lineno;
      lnode->next = NULL;
      bnode->lines = lnode;
      bnode->memloc = loc;//位置是传进来的不用自己处理



  }
  else{//找到
      int h = hash(name);//哈希到位置
      BucketList l =  hashTable[h];
      while ((l != NULL) && (strcmp(name,l->name) != 0))
        l = l->next;
      struct LineListRec * lnode = (struct LineListRec*)malloc(sizeof(struct LineListRec));
      lnode ->lineno = lineno;
      lnode->next = l->lines;
      l->lines = lnode;//加入新的行
  }

  
  
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name )
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) return -1;
  else return l->memloc;
}

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing)//打印符号表
{ int i;
  fprintf(listing,"Variable Name  Location   Line Numbers\n");
  fprintf(listing,"-------------  --------   ------------\n");
  for (i=0;i<SIZE;++i)
  { if (hashTable[i] != NULL)
    { BucketList l = hashTable[i];
      while (l != NULL)
      { LineList t = l->lines;
        fprintf(listing,"%-14s ",l->name);
        fprintf(listing,"%-8d  ",l->memloc);
        while (t != NULL)
        { fprintf(listing,"%4d ",t->lineno);
          t = t->next;
        }
        fprintf(listing,"\n");
        l = l->next;
      }
    }
  }
} /* printSymTab */
