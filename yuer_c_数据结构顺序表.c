/*
//静态顺序表
#include<stdio.h>
#define maxsize 10
void insertElem(int Sqlist[],int *len,int i,int x)
//i插入元素位置，x待插入元素值，Sqlist表首地址，*len表的长度
{
    int t;
    if(*len==maxsize||i<1||i>*len+1)
    {
        printf("This insert is illegal\n");
    }//非法插入
    for(t=*len-1;t>=i-1;t--)
        Sqlist[t+1]=Sqlist[t];;
    Sqlist[i-1]=x;
    *len=*len+1;
}
void deleteElem(int Sqlist[],int *len,int i)
{
    int j;
    if(i<1||i>*len)
    {
        printf("This delete is illegal\n");
        return ;
    }
    for(j=i;j<*len;j++)
        Sqlist[j]=Sqlist[j+1];
    *len=*len-1;
}
void print(int Sqlist[],int *len)
{
    int i;
    for(i=0;i<*len;i++)
        printf("%d ",Sqlist[i]);
    printf("\nThe spare length is %d\n",maxsize-*len);
}
int main()
{
    int Sqlist[maxsize];
    int len,i;
    for(i=0;i<6;i++)
        scanf("%d",&Sqlist[i]);
    len=6;
    print(Sqlist,&len);
    insertElem(Sqlist,&len,3,0);
    print(Sqlist,&len);
    insertElem(Sqlist,&len,11,0);
    deleteElem(Sqlist,&len,6);
    print(Sqlist,&len);
}
//动态顺序表
#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
typedef int Elemtype;
typedef struct
{
    Elemtype *elem;
    Elemtype length;
    Elemtype listsize;
}Sqlist;
void initSqlist(Sqlist *L)
{
    L->elem=(Elemtype *)malloc(maxsize*sizeof(Elemtype));
    if(!L->elem)
        exit(0);
    L->listsize=maxsize;
    L->length=0;
}
void insertElem(Sqlist *L,int i,int item)
{
    Elemtype *insertptr,*p,*base;
    if(i<1||i>L->length+1)
        exit(0);
    if(L->length>=L->listsize)
        {
            base=(Elemtype *)realloc(L->elem,(L->listsize+10)*sizeof(Elemtype));
            L->elem=base;
            L->listsize=L->listsize+10;
        }
            insertptr=&(L->elem[i-1]);
        for(p=&(L->elem[L->length-1]);p>=insertptr;p--)
            *(p+1)=*p;
        *insertptr=item;
        ++L->length;
}
void deleteElem(Sqlist *L,int i)
{
    Elemtype *delitem;
    if(i<1||i>L->length+1)
        exit(0);
    delitem=&(L->elem[i-1]);
    for(;delitem<(L->elem+L->length-1);delitem++)
        *delitem=*(delitem+1);
    L->length--;
}
int main()
{
    Sqlist L;
    int i=0,a[100],m;
    initSqlist(&L);//初始化顺序表
    while((~scanf("%d",&a[i]))&&(a[i]!=0))
    {
        insertElem(&L,i+1,a[i]);
        i++;
    }
    printf("\nThen content of the list is \n");
    for(i=0;i<L.length;i++)
    printf("%d  ",L.elem[i]);
    printf("\nPlease input the deleted number \n");
    if(scanf("%d",&m))
    deleteElem(&L,m);
    printf("\ndelete the fifth item is\n");
        for(i=0;i<L.length;i++)
    printf("%d  ",L.elem[i]);
}


//动态顺序表
#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
typedef int Elemtype;
typedef struct
{
    Elemtype *elem;
    Elemtype length;
    Elemtype listsize;
}Sqlist;
void initSqlist(Sqlist *L)
{
    L->elem=(Elemtype *)malloc(maxsize*sizeof(Elemtype));
    if(!L->elem)
        exit(0);
    L->listsize=maxsize;
    L->length=0;
}
void insertElem(Sqlist *L,int i,int item)
{
    Elemtype *insertptr,*p,*base;
    if(i<1||i>L->length+1)
        exit(0);
    if(L->length>=L->listsize)
        {
            base=(Elemtype *)realloc(L->elem,(L->listsize+10)*sizeof(Elemtype));
            L->elem=base;
            L->listsize=L->listsize+10;
        }
            insertptr=&(L->elem[i-1]);
        for(p=&(L->elem[L->length-1]);p>=insertptr;p--)
            *(p+1)=*p;
        *insertptr=item;
        ++L->length;
}
void deleteElem(Sqlist *L,int i)
{
    Elemtype *delitem;
    if(i<1||i>L->length+1)
        exit(0);
    delitem=&(L->elem[i-1]);
    for(;delitem<(L->elem+L->length-1);delitem++)
        *delitem=*(delitem+1);
    L->length--;
}
int main()
{
    Sqlist L;
    int i=0,a[100],m;
    initSqlist(&L);//初始化顺序表
    while((~scanf("%d",&a[i]))&&(a[i]!=0))
    {
        insertElem(&L,i+1,a[i]);
        i++;
    }
    printf("\nThen content of the list is \n");
    for(i=0;i<L.length;i++)
    printf("%d  ",L.elem[i]);
    printf("\nPlease input the deleted number \n");
    if(scanf("%d",&m))
    deleteElem(&L,m);
    printf("\ndelete the fifth item is\n");
        for(i=0;i<L.length;i++)
    printf("%d  ",L.elem[i]);
}
