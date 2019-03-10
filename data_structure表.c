//���Ա�
/*
#include<stdio.h>
#define maxsize 10
typedef int elemtype;
typedef struct
{
    int length;
    elemtype data[maxsize];
}Lnode;
Lnode InitList()
{
    Lnode L;//����һ�����Ա�
    L.length=0;//��ʼ����Ϊ0
    return L;//����1���Ա��ַ
}
int InsertList(Lnode *L,int i,elemtype e)
{//��i��λ�ò���e
    int j;
    if(L->length==maxsize)
    {
        printf("���Ա�����\n");
        return 0;
    }
    if(i<1||i>L->length+1)
    {
       printf("����λ�÷Ƿ�\n");
        return 0;
    }
    if(i<L->length+1)//�Ǳ�βԪ��
    {
        for(j=L->length-1;j>=i-1;j--)
            L->data[j+1]=L->data[j];
    }
    L->data[i-1]=e;
    L->length++;
    return 0;

}
int DeleteList(Lnode *L,int i,elemtype *e)
{
    int j;
    if(L->length==0)
    {
        printf("���Ա�����\n");
        return 0;
    }
    if(i<1||i>L->length)
    {
       printf("ɾ��λ�÷Ƿ�\n");
        return 0;
    }
    *e=L->data[i-1];
    if(i<L->length)//�Ǳ�βԪ��
    {
        for(j=i-1;j<L->length-1;j++)
            L->data[j]=L->data[j+1];
    }
    L->length--;
    return 1;
}
int PrintList(Lnode L)
{
    int k;
    for(k=0;k<L.length;k++)
        printf("%d  ",L.data[k]);
        printf("\n");
    return 1;
}
int GetElem(Lnode L,int i,int *x)
{
    if(L.length==0)
    {
        printf("���Ա�����\n");
        return 0;
    }
    if(i<1||i>L.length)
    {
       printf("��ȡλ�ò�����\n");
        return 0;
    }
    *x=L.data[i-1];
    return 1;
}
int main()
{
   int i;
   Lnode L;
   L=InitList();
   for(i=0;i<5;i++)
   {
       L.data[i]=i;
       L.length++;
   }
   PrintList(L);
   InsertList(&L,6,10);
   PrintList(L);
   int m;
   DeleteList(&L,6,&m);
   PrintList(L);
   printf("%d",m);
   GetElem(L,1,&m);
   printf("%d",m);
}

//������
#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;
typedef struct Lnode
{
    elemtype data;
    struct Lnode *next;
}Lnode,*Linklist;
//typedef struct Lnode *Linklist;
int InsertList(Linklist *L,int i,elemtype e)
{
    Linklist s,p;
    p=*L;
    int j=1;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i)
        return 0;
    s=(Linklist)malloc(sizeof(Lnode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return 1;
}
int DeleteList(Linklist *L,int i,elemtype *e)
{
   int j=1;
   Linklist p,s;
   p=*L;
   while(p&&j<i)
   {
       p=p->next;
       j++;
   }
   if(!p||j>i)
        {
            printf("��ɾ���ڵ㲻����\n");
            return 0;
        }
        s=p->next;
        p->next=s->next;
        *e=s->data;
        free(s);
        return 1;
}
int GetElem(Linklist L,int i,elemtype *e)
{
    Linklist p;
    int j=1;
    p=L->next;
    while(p&&j<i)
   {
       p=p->next;
       j++;
   }
   if(!p||j>i)
        {
            printf("�����ҽڵ㲻����\n");
            return 0;
        }
        *e=p->data;
        return 1;
}
int CreateListHead(Linklist *L,int n)//ͷ�巨
{
    Linklist p;
    int i;
    *L=(Linklist)malloc(sizeof(Lnode));
    (*L)->next=NULL;
    for(i=0;i<n;i++)
    {
        p=(Linklist)malloc(sizeof(Lnode));
        p->data=i;
        p->next=(*L)->next;
        (*L)->next=p;
    }
    return 1;
}
int CreateListTail(Linklist *L,int n)//ͷ�巨
{
    Linklist p,s;
    int i;
    *L=(Linklist)malloc(sizeof(Lnode));
    s=*L;
    for(i=0;i<n;i++)
    {
        p=(Linklist)malloc(sizeof(Lnode));
        p->data=i;
        s->next=p;
        s=p;
    }
    s->next=NULL;
    return 1;
}
int PrintList(Linklist L)
{
    Linklist p;
    p=L->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return 1;
}
int ClearList(Linklist *L)
{
    Linklist p,q;
    p=(*L)->next;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
    (*L)->next=NULL;
    return 1;
}
int main()
{
    Linklist L;
    elemtype e;
    CreateListTail(&L,4);
    PrintList(L);
    InsertList(&L,3,9);
    PrintList(L);
    DeleteList(&L,4,&e);
    PrintList(L);
    GetElem(L,3,&e);
    printf("\n%d",e);
    ClearList(&L);
    PrintList(L);
}

*/
#include<stdio.h>
#include<stdlib.h>
typedef int elemtype;
typedef struct Lnode
{
    elemtype data;
    struct Lnode *next;
}Lnode,*Linklist;
int DeleteList(Linklist *L,int i)
{
   int j=0;
   Linklist p,s;
   p=*L;
   while(p&&j<i)
   {
       p=p->next;
       j++;
   }
   if(!p||j>i)
        {
            return 0;
        }
        s=p->next;
        p->next=s->next;
        printf("%d ",s->data);
        free(s);
        return 1;
}
int CreateListTail(Linklist *L,int n)//ͷ�巨
{
    Linklist p,s;
    int i;
    *L=(Linklist)malloc(sizeof(Lnode));
    s=*L;
    for(i=0;i<n;i++)
    {
        p=(Linklist)malloc(sizeof(Lnode));
        p->data=i+1;
        s->next=p;
        s=p;
    }
    s->next=NULL;
    return 1;
}
int PrintList(Linklist L)
{
    Linklist p;
    p=L->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return 1;
}
int main()
{
    Linklist L;
    elemtype e;
    int m,n,sum,i;
    scanf("%d",&sum);
    for(i=0;i<sum;i++){
        scanf("%d%d",&n,&m);
        CreateListTail(&L,n);
        //PrintList(L);
        for(int i=0;i<n;i++)
        DeleteList(&L,m);
    }
}
