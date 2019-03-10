//顺序循环队列
/*
#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10
typedef int Qelemtype;
typedef struct
{
    Qelemtype data[Maxsize];
    int front;//队首指针，也就是数组下标
    int rear;//队尾指针，队尾不空，指向队末下一个空元素
}SqQueue;
int InitQueue(SqQueue *Q)
{
    Q->front=0;
    Q->rear=0;
    return 1;
}
int LengthQueue(SqQueue Q)
{
    return(Q.rear-Q.front+Maxsize)%Maxsize;
}
//队尾人，队首出
int EnQueue(SqQueue *Q,Qelemtype e)
{
    if((Q->rear+1)%Maxsize==Q->front)
        exit(0);//队列满
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%Maxsize;
    return 1;
}
int DeQueue(SqQueue *Q,Qelemtype *e)
{
   if(Q->rear==Q->front)
        exit(0);//队列空
   *e=Q->data[Q->front];
   Q->front=(Q->front+1)%Maxsize;//front后移一位，到数组尾则转入数组头
   return 1;
}
int Print(SqQueue Q)//从队首到队尾输出
{
    if(Q.front==Q.rear)
        exit(0);
    int m=Q.front;
    while(m!=Q.rear)
    {
        printf("%d",Q.data[m]);
        m=(m+1)%Maxsize;
    }
    return 1;
}
int main()
{
    int i,m;
    SqQueue Q;
    InitQueue(&Q);
    for(i=0;i<5;i++)
        EnQueue(&Q,i);
    DeQueue(&Q,&m);
    Print(Q);
}
*/
//链式循环队列
#include<stdio.h>
#include<stdlib.h>
typedef int Qelemtype;
typedef struct Qnode//结点结构
{
    Qelemtype data;
    struct Qnode *next;
}Qnode,*Queueptr;
typedef struct //队列结构
{
  Queueptr front,rear;
}LinkQueue;
int EnQueue(LinkQueue *Q,Qelemtype e)
{
   Queueptr p=(Queueptr)malloc(sizeof(Qnode));
   if(!p)//分配内存失败
    exit(0);
    p->data=e;
    p->next=NULL;
    Q->rear->next=p;//新节点赋值给队列尾的直接后继
    Q->rear=p;
    return 1;
}
int DeQueue(LinkQueue *Q,Qelemtype *e)
{
    if(Q->front==Q->rear)
        return 0;//队头节点不存放数据，只存放指针
   Queueptr p=Q->front->next; //将欲删除节点暂存p
   *e=p->data;
   Q->front->next=p->next;//将原队头结点后继p->next赋值给头结点后继
   if(Q->rear==p)//当队列除了队头只有一个元素的时候，将队尾指针指向队首
    Q->rear=Q->front;
   free(p);
   return 1;
}
int InitQueue(LinkQueue *Q)
{
    Q->front=(Queueptr)malloc(sizeof(Qnode));
    Q->front->next = NULL;
    Q->rear=Q->front;
    return 1;
}
int EmptyQueue(LinkQueue Q)
{
    if(Q.rear==Q.front)
        return 1;
    else
        return 0;
}
int Print(LinkQueue Q)
{
    Qelemtype m;
    Queueptr p;
    if(Q.front==Q.rear)
        exit(0);
    p=Q.front->next;
    while(p)
    {
        m=p->data;
        printf("%d",m);
        p=p->next;
    }
    return 1;
}
/*
int main()
{
    int i;
    Qelemtype e;
    LinkQueue Q;
    InitQueue(&Q);
    for(i=0;i<5;i++)
        EnQueue(&Q,i);
    DeQueue(&Q,&e);
    printf("%d\n",e);
    Print(Q);
}

//杨辉三角输出
#include<stdio.h>
*/
