//栈的顺序存储
/*
#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
typedef int Selemtype;
typedef struct
{
   Selemtype data[maxsize];
   int top;
}SqStack;
SqStack InitSqStack()
{
    SqStack S;
    S.top=-1;
    return S;
}
int Push(SqStack *S,Selemtype e)
{
   if(S->top==maxsize-1)
    return 0;
   S->data[++S->top]=e;
   return 1;
}
int Pop(SqStack *S,Selemtype *e)
{
    if(S->top==-1)
        return 0;
    *e=S->data[S->top--];
    return 1;
}
int Print(SqStack *S)
{
    while(S->top!=-1)
    {
       printf("%d ",S->data[S->top--]);
    }
    printf("\n");
       return 1;
}
int main()
{
   SqStack S;
   int i;
   Selemtype e;
   S=InitSqStack();
   for(i=0;i<4;i++)
   Push(&S,i);
   Pop(&S,&e);
   Print(&S);
   printf("%d ",e);
}
*/
//链式存储
#include<stdio.h>
#include<stdlib.h>
typedef int Selemtype;
typedef struct StackNode
{
    Selemtype data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;
typedef struct
{
   LinkStackPtr top;
   int count;
}LinkStack;
int Push(LinkStack *S,Selemtype e)
{
   LinkStackPtr p;
   p=(LinkStackPtr)malloc(sizeof(StackNode));
   p->data=e;
   p->next=S->top;//把当前栈顶元素赋值给新节点的直接后继
   S->top=p;//将新节点p赋值给栈顶指针
   S->count++;
   return 1;
}
int Pop(LinkStack *S,Selemtype *e)
{
    LinkStackPtr p;
    if(S->count==0)
        return 0;
    *e=S->top->data;
    p=S->top;//栈顶节点赋值给p
    S->top=S->top->next;//栈顶指针后移一位，指向下一个节点
    free(p);//释放节点p
    S->count--;
    return 1;
}
int Print(LinkStack S)
{
    if(S.count==0||S.top==NULL)
        return 0;
    LinkStackPtr p;
    p=S.top;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 1;
}
LinkStack InitLinkStack()
{
    LinkStack S;
    S.count=0;
    S.top = NULL;
   return S;
}
int main()
{
   int i;
   LinkStack S;
   S=InitLinkStack();
   for(i=0;i<5;i++)
    Push(&S,i);
    Pop(&S,&i);
    Print(S);
}
