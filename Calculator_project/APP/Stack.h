#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define Limited_Memory  /*****linked*****/


#ifdef Limited_Memory

typedef struct stacknode{
 void *entry;
 struct stacknode *next;
}StackNode;

typedef struct stack{
    StackNode *top;
    int size;
}Stack;
#else

typedef struct stack{
    int top;
    void* entry[MaxStack];

}Stack;

#endif // Limited_Memory




void CreateStack(Stack*);
int StackFull(Stack *ps);
void Push(void *pe , Stack *ps, int z);
void Pop(void *pe , Stack *ps, int z);
int StackEmpty(Stack *ps);
void StackTop(void *pe,Stack *ps,int z);
int StackSize(Stack *ps);
void ClearStack(Stack *ps);
void TraverseStack(Stack *ps,void (*pf) (void *));


#endif // STACK_H_INCLUDED
