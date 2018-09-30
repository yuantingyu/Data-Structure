//顺序查找法1
/*
#include<stdio.h>
int Sequential_Search(int a[],int n,int key)
{
  int i;
  for(i=1;i<n;i++)
      {
          if(a[i]==key)
             return i;
      }
      return 0;
}
int main()
{
  int a[10]={0,3,18,92,76,34,25,10,89,100};
  int location;
  location=Sequential_Search(a,10,34);
  if(location)
    printf("查找位置为%d \n",location);
  else
    printf("不存在这个数\n");

}
*/
/*
//顺序查找法2（设置哨兵，增加了查找效率）
#include<stdio.h>
int Sequential_Search(int a[],int n,int key)
{
    a[0]=key;//设置哨兵
    int i=n;
    while(a[i]!=a[0])
    {
        i--;
    }
    return i;//如果数组里没有，就会返回0
}

int main()
{
    int a[10]={0,3,18,92,76,34,25,10,89,100};
    int location;
    location=Sequential_Search(a,10,34);
    if(location)
        printf("查找位置为%d \n",location);
        else
            printf("不存在这个数\n");

}
*/
/*
//折半查找（基于已经排序好的顺序表）
#include<stdio.h>
int Binary_Search(int a[],int n,int key)
{
    int low=1,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]<key)
            low=mid+1;
        else if(a[mid]>key)
            high=mid-1;
        else
            return mid;//终止条件high=low为key值，或者mid恰好蹦到了key值
    }
    return 0;
}
int main()
{
    int a[10]={0,3,18,22,76,74,85,90,99,100};
    int location;
    location=Binary_Search(a,10,10);
    if(location)
        printf("查找位置为%d \n",location);
        else
            printf("不存在这个数\n");
}
*/
/*
//插值查找（基于已经排序好的顺序表），只是插值位置不是一半处，
//而是根据一种线性关系寻找位置.适用于表长较大，分布并比较均匀的表
//对于比较极端的0，11，74938则不适用，效率低
#include<stdio.h>
int Interpolation_Search(int a[],int n,int key)
{
    int low=1,high=n-1,mid;
    while(low<=high)
    {
        mid=low+(key-a[low])/(a[high]-a[low])*(high-low);
        if(a[mid]<key)
            low=mid+1;
        else if(a[mid]>key)
            high=mid-1;
        else
            return mid;
    }
    return 0;
}
int main()
{
    int a[10]={0,3,18,22,76,74,85,90,99,100};
    int location;
    location=Interpolation_Search(a,10,99);
    if(location)
        printf("查找位置为%d \n",location);
        else
            printf("不存在这个数\n");
}
//斐波那契查找(利用黄金分割原理，也针对有序表进行，也是对查找位置做了改变)
//太恶心了
#include<stdio.h>
int Fiboncacci_Search(int a[],int n,int key)
{
    int low=1,high=n-1,mid;
    while(low<=high)
    {
        mid=low+(key-a[low])/(a[high]-a[low])*(high-low);
        if(a[mid]<key)
            low=mid+1;
        else if(a[mid]>key)
            high=mid-1;
        else
            return mid;
    }
    return 0;
}
int main()
{
    int a[10]={0,3,18,22,76,74,85,90,99,100};
    int location;
    location=Fiboncacci_Search(a,10,99);
    if(location)
        printf("查找位置为%d \n",location);
        else
            printf("不存在这个数\n");
}
*/
//二叉排序树
#include<stdio.h>
#include<stdlib.h>
typedef struct BiNode
{
    int data;
    struct BiNode *lchild,*rchild;
}BiNode,*Bitree;
int SearchBST(Bitree T,int key,Bitree f,Bitree *p)
//f指向T的双亲，T为根结点初始值为空，
//若查找成功，p指向那个结点，返回1，否则，指向路径上最后一个节点，返回0
{
    if(!T)//查找不成功
    {
        *p=f;
        return 0;
    }
    else if(key==T->data)//查找成功
    {
        *p=T;
        return 1;
    }
    else if(key<T->data)
        SearchBST(T->lchild,key,T,p);//在左子树继续寻找
    else
        SearchBST(T->rchild,key,T,p);//在右子树继续寻找
}
int InsertBST(Bitree *T,int key)
{
   Bitree p,s;
   if(!SearchBST(*T,key,NULL,&p))
   {
       s=(Bitree)malloc(sizeof(BiNode));
       s->data=key;
       s->lchild=s->rchild=NULL;
       if(!p)
           *T=s;//插入s为新的根节点
       else if(key>p->data)
        p->rchild=s;
       else if(key<p->data)
        p->lchild=s;7
        return 1;
   }
   else
    return 0;//树中已经存在这个节点
}
int InOrderTraverse(Bitree T)//中序
{
    if(T==NULL)
        return 0;
    InOrderTraverse(T->lchild);
    printf("%d ",T->data);
    InOrderTraverse(T->rchild);
    return 1;
}
int main()
{
    int a[10]={62,88,58,47,35,73,51,99,37,93};
    int i=0;
    Bitree T=NULL;
    for(i=0;i<10;i++)
        InsertBST(&T,a[i]);
    InOrderTraverse(T);
}
