//ջ��˳��洢
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
//��ʽ�洢
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
   p->next=S->top;//�ѵ�ǰջ��Ԫ�ظ�ֵ���½ڵ��ֱ�Ӻ��
   S->top=p;//���½ڵ�p��ֵ��ջ��ָ��
   S->count++;
   return 1;
}
int Pop(LinkStack *S,Selemtype *e)
{
    LinkStackPtr p;
    if(S->count==0)
        return 0;
    *e=S->top->data;
    p=S->top;//ջ���ڵ㸳ֵ��p
    S->top=S->top->next;//ջ��ָ�����һλ��ָ����һ���ڵ�
    free(p);//�ͷŽڵ�p
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
