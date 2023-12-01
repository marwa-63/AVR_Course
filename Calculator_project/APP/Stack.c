#include "Stack.h"

#define Limited_Memory

#ifdef Limited_Memory  /***Linked***/

void CreateStack(Stack *ps)
{
    ps->top=NULL;
    ps->size=0;
}

void Push(void *pe,Stack *ps,int z)
{
    void *ptr=malloc(z);
    memcpy(ptr,pe,z);
    StackNode *pn=(StackNode*)malloc(sizeof(StackNode));
    pn->entry=ptr;
    pn->next=ps->top;
    ps->top=pn;
    ps->size++;
}

void Pop(void *pe ,Stack *ps,int z)
{
    memcpy(pe,ps->top->entry,z);
    StackNode *pn;
    pn=ps->top;
    ps->top=ps->top->next;
    ps->size--;
    free(pn);
}
int StackFull(Stack *ps) {return 0;}

int StackEmpty(Stack *ps){ return ps->top==NULL; }

void ClearStack(Stack *ps)
{
    StackNode *pn=ps->top;
    while(pn){
        pn=pn->next;
        free(ps->top);
        ps->top=pn;
    }
}

void StackTop(void *pe,Stack *ps,int z)
{
     memcpy(pe,ps->top->entry,z);

}

void TraverseStack(Stack *ps,void (*pf) (void *pe) )
{

    for(StackNode *pn=ps->top;pn;pn=pn->next)
        (*pf)(pn->entry);
}

int StackSize(Stack *ps) { return ps->size; }

#else /****array based*****/

void CreateStack(Stack *ps)
{
    ps->top=0;
}
int StackFull(Stack *ps)
{
    return ps->top >= MaxStack;
}
void Push(void *pe , Stack *ps,int z)
{
    void *ptr=malloc(z);
    memcpy(ptr,pe,z);
    ps->entry[ps->top]=ptr;
    ps->top++;

}
void Pop(void *pe , Stack *ps,int z)
{
    memcpy(pe,ps->entry[--ps->top],z);

}

int StackEmpty(Stack *ps)
{
    return !ps->top;
}

void StackTop(void *pe,Stack *ps,int z)
{
     memcpy(pe,ps->entry[ps->top - 1],z);

}

int StackSize(Stack *ps)
{
    return ps->top;
}

void ClearStack(Stack *ps)
{
    ps->top=0;
}

void TraverseStack(Stack *ps,void (*pf) (void *))
{
    for(int i=ps->top;i>0;i--)
    {
        (*pf)((ps->entry[i-1]));
    }
}
#endif // Limited_Memory
