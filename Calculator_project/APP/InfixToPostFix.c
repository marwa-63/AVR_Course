#include "InfixToPostFix.h"
#include "Stack.h"

int Precedent(char op1,char op2)
{
    if(op1 =='$') return 1;
    if( (op1=='*') || (op1=='/') ) return (op2 != '$');
     if( (op1=='+') || (op1=='-') ) return ( (op2 != '$') && (op2 != '*') && (op2 != '/') );
     return 0;
}
int IsDigit(char c)
{
    return (c>='0' && c<='9');
}

void InfixToPostFix(char Infix[],char Postfix[])
{
    int i,j;
    char op,c;
    Stack s;
    CreateStack(&s);
    for(i=0,j=0;Infix[i] != '\0';i++)
    {
        c=Infix[i];
        if( IsDigit(c) ){
            Postfix[j++]=c;
            }
        else{
                Postfix[j++]=',';
            if(!StackEmpty(&s)) {
            StackTop(&op,&s,sizeof(op));

            while(!StackEmpty(&s) && Precedent(op,c))
            {
                 Pop(&op,&s,sizeof(op));
                 Postfix[j++]=op;

                 if(!StackEmpty(&s)) StackTop(&op,&s,sizeof(op));
            }
            }
            Push(&c,&s,sizeof(c));
    }
    }
    while(!StackEmpty(&s))
    {
        Pop(&op,&s,sizeof(op));
        Postfix[j++]=op;
    }
    Postfix[j]='\0';
}
