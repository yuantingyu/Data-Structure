//����
/*#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct node
{
    Elemtype data;
    struct node *next;
}Lnode,*Linklist;
//Lnode *p��Linklist p�ȼ�
Linklist creatList(int n)//�����������n��
{
    Linklist p,r,list=NULL;
    Elemtype e;
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&e);
        p=(Linklist)malloc(sizeof(Lnode));//Ϊ������������ռ�
        p->data=e;
        p->next=NULL;
        if(!list)
            list=p;//��ֵ����ͷָ��list
        else
            r->next=p;
        r=p;//��βָ��r
    }
    return list;
}
void destroyList(Linklist *List)//��������
//���ٺ�List��Ϊ�գ��ı��˵�ַ������Ҫ��*List
{
   Linklist p,q;
   p=*List;
   while(p)//ѭ���ͷŵ�ÿһ������Ľڵ�
   {
       q=p->next;
       free(p);
       p=q;
   }
   *List=NULL;
}
void deleteList(Linklist *List,Linklist q)//��ͷ�ڵ���ܸı��ַ
{
   Linklist r;
   if(q==*List)//ɾ���ڵ��ڱ�ͷ
   {
       *List=q->next;
       free(q);
   }
   else//ɾ���ڵ��ڱ��м�
   {
       for(r=*List;r->next!=q;r=r->next);
       if(r->next!=NULL)
       {
           r->next=q->next;
           free(q);
       }
       else
        printf("The point you plan to delete is empty!");
   }
}
void insertList(Linklist *List,Linklist q,Elemtype e)
//��ָ��q����������㣬����Ϊe
*/
/*
Linklist *List�൱��Lnode **list;ָ��ָ���ָ���������Ϊ������Ҫ��List
����ͷָ������޸ģ����ú���ʱ��ʵ��ʵ������&list��������list����˱���
����ָ��������ݵķ����������޷��ڱ����������޸��������ж���ı�������
*/
/*
{
    Linklist p;
    p=(Linklist)malloc(sizeof(Lnode));
    p->data=e;
    if(!*List)
    {
        *List=p;
        p->next=NULL;
    }
    else
    {
        p->next=q->next;//ԭ�����q��nextֵ��ֵ��������ڵ��next
        q->next=p;//p��ֵ��ֵ��q��next
    }
}
int main()
{
    Elemtype e;
    int i;
    Linklist l,q;
    q=l=creatList(1);//����һ�������㣬ql��ָ��ýڵ�
    scanf("%d",&e);
    while(e)
    {
        insertList(&l,q,e);
        q=q->next;
        scanf("%d",&e);
    }
    q=l;
    printf("The content of the linklist is \n");
    while(q)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    q=l;
    printf("Delete the fifth element\n");
    for(i=0;i<4;i++)
    {
        q=q->next;
    }
    deleteList(&l,q);
    q=l;
    while(q)
    {
        printf("%d",q->data);
        q=q->next;
    }
    destroyList(&l);
    //getche();
}
*/

#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct node
{
    Elemtype data;
    struct node *next;
}Lnode,*Linklist;
Linklist Creatlist(Elemtype n)
{
    Linklist p,List=NULL,r;
    Elemtype i,e;
    //List=(Linklist)malloc(sizeof(Lnode));
    for(i=0;i<n;i++)
    {
        scanf("%d",&e);
        p=(Linklist)malloc(sizeof(Lnode));
        p->data=e;
        if(!List)
            List=p;
        else
            r->next=p;
        r=p;
    }
    return List;
}
void Destroylist(Linklist *List)
{
    Linklist p,r;
    p=*List;
    while(p)
    {
        r=p->next;
        free(p);
        p=r;
    }
    *List=NULL;
}
void Insertlist(Linklist *List,Linklist p,Elemtype e)
{
    Linklist q,r;
    r=(Linklist)malloc(sizeof(Lnode));
    r->data=e;
    r->next=NULL;
    if(!*List)
      {
        r=*List;
    r->next=NULL;
      }
      else{
    for(q=*List;q!=p;q=q->next);
    {r->next=q->next;
    q->next=r;}
      }
}
void Deletelist(Linklist *List,Linklist q)
{
    Linklist p;
    if(q==*List)
        {
            *List=q->next;
            free(q);
        }
    else
        {
             for(p=*List;p->next!=q;p=p->next);
            if(p->next!=NULL)
               {
                   p->next=q->next;
                   free(q);
               }
        }
}
int main()
{
    Linklist p,l;
   p=l=Creatlist(5);
   Elemtype i;
   while(p)
   {
       printf("%d ",p->data);
       p=p->next;
   }
   p=l;
   for(i=0;i<1;i++)
    p=p->next;
   Deletelist(&l,p);
   printf("Delete the second element,the content of the list is\n");
   p=l;
   while(p)
   {
       printf("%d ",p->data);
       p=p->next;
   }
   printf("Insert the second element,the content of the list is\n");
   p=l;
   for(i=0;i<1;i++)
    p=p->next;
   Insertlist(&l,p,5);
   p=l;
   while(p)
   {
       printf("%d ",p->data);
       p=p->next;
   }
   Destroylist(&l);
}
