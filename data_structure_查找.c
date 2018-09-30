//˳����ҷ�1
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
    printf("����λ��Ϊ%d \n",location);
  else
    printf("�����������\n");

}
*/
/*
//˳����ҷ�2�������ڱ��������˲���Ч�ʣ�
#include<stdio.h>
int Sequential_Search(int a[],int n,int key)
{
    a[0]=key;//�����ڱ�
    int i=n;
    while(a[i]!=a[0])
    {
        i--;
    }
    return i;//���������û�У��ͻ᷵��0
}

int main()
{
    int a[10]={0,3,18,92,76,34,25,10,89,100};
    int location;
    location=Sequential_Search(a,10,34);
    if(location)
        printf("����λ��Ϊ%d \n",location);
        else
            printf("�����������\n");

}
*/
/*
//�۰���ң������Ѿ�����õ�˳���
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
            return mid;//��ֹ����high=lowΪkeyֵ������midǡ�ñĵ���keyֵ
    }
    return 0;
}
int main()
{
    int a[10]={0,3,18,22,76,74,85,90,99,100};
    int location;
    location=Binary_Search(a,10,10);
    if(location)
        printf("����λ��Ϊ%d \n",location);
        else
            printf("�����������\n");
}
*/
/*
//��ֵ���ң������Ѿ�����õ�˳�����ֻ�ǲ�ֵλ�ò���һ�봦��
//���Ǹ���һ�����Թ�ϵѰ��λ��.�����ڱ��ϴ󣬷ֲ����ȽϾ��ȵı�
//���ڱȽϼ��˵�0��11��74938�����ã�Ч�ʵ�
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
        printf("����λ��Ϊ%d \n",location);
        else
            printf("�����������\n");
}
//쳲���������(���ûƽ�ָ�ԭ��Ҳ����������У�Ҳ�ǶԲ���λ�����˸ı�)
//̫������
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
        printf("����λ��Ϊ%d \n",location);
        else
            printf("�����������\n");
}
*/
//����������
#include<stdio.h>
#include<stdlib.h>
typedef struct BiNode
{
    int data;
    struct BiNode *lchild,*rchild;
}BiNode,*Bitree;
int SearchBST(Bitree T,int key,Bitree f,Bitree *p)
//fָ��T��˫�ף�TΪ������ʼֵΪ�գ�
//�����ҳɹ���pָ���Ǹ���㣬����1������ָ��·�������һ���ڵ㣬����0
{
    if(!T)//���Ҳ��ɹ�
    {
        *p=f;
        return 0;
    }
    else if(key==T->data)//���ҳɹ�
    {
        *p=T;
        return 1;
    }
    else if(key<T->data)
        SearchBST(T->lchild,key,T,p);//������������Ѱ��
    else
        SearchBST(T->rchild,key,T,p);//������������Ѱ��
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
           *T=s;//����sΪ�µĸ��ڵ�
       else if(key>p->data)
        p->rchild=s;
       else if(key<p->data)
        p->lchild=s;7
        return 1;
   }
   else
    return 0;//�����Ѿ���������ڵ�
}
int InOrderTraverse(Bitree T)//����
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
