//˳��ѭ������
/*
#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10
typedef int Qelemtype;
typedef struct
{
    Qelemtype data[Maxsize];
    int front;//����ָ�룬Ҳ���������±�
    int rear;//��βָ�룬��β���գ�ָ���ĩ��һ����Ԫ��
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
//��β�ˣ����׳�
int EnQueue(SqQueue *Q,Qelemtype e)
{
    if((Q->rear+1)%Maxsize==Q->front)
        exit(0);//������
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%Maxsize;
    return 1;
}
int DeQueue(SqQueue *Q,Qelemtype *e)
{
   if(Q->rear==Q->front)
        exit(0);//���п�
   *e=Q->data[Q->front];
   Q->front=(Q->front+1)%Maxsize;//front����һλ��������β��ת������ͷ
   return 1;
}
int Print(SqQueue Q)//�Ӷ��׵���β���
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
//��ʽѭ������
#include<stdio.h>
#include<stdlib.h>
typedef int Qelemtype;
typedef struct Qnode//���ṹ
{
    Qelemtype data;
    struct Qnode *next;
}Qnode,*Queueptr;
typedef struct //���нṹ
{
  Queueptr front,rear;
}LinkQueue;
int EnQueue(LinkQueue *Q,Qelemtype e)
{
   Queueptr p=(Queueptr)malloc(sizeof(Qnode));
   if(!p)//�����ڴ�ʧ��
    exit(0);
    p->data=e;
    p->next=NULL;
    Q->rear->next=p;//�½ڵ㸳ֵ������β��ֱ�Ӻ��
    Q->rear=p;
    return 1;
}
int DeQueue(LinkQueue *Q,Qelemtype *e)
{
    if(Q->front==Q->rear)
        return 0;//��ͷ�ڵ㲻������ݣ�ֻ���ָ��
   Queueptr p=Q->front->next; //����ɾ���ڵ��ݴ�p
   *e=p->data;
   Q->front->next=p->next;//��ԭ��ͷ�����p->next��ֵ��ͷ�����
   if(Q->rear==p)//�����г��˶�ͷֻ��һ��Ԫ�ص�ʱ�򣬽���βָ��ָ�����
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

//����������
#include<stdio.h>
*/
