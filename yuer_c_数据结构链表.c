//链表
/*#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct node
{
    Elemtype data;
    struct node *next;
}Lnode,*Linklist;
//Lnode *p与Linklist p等价
Linklist creatList(int n)//创建链表，结点n个
{
    Linklist p,r,list=NULL;
    Elemtype e;
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&e);
        p=(Linklist)malloc(sizeof(Lnode));//为新申请结点申请空间
        p->data=e;
        p->next=NULL;
        if(!list)
            list=p;//赋值链表头指针list
        else
            r->next=p;
        r=p;//表尾指针r
    }
    return list;
}
void destroyList(Linklist *List)//销毁链表
//销毁后List变为空，改变了地址，所以要用*List
{
   Linklist p,q;
   p=*List;
   while(p)//循环释放掉每一个链表的节点
   {
       q=p->next;
       free(p);
       p=q;
   }
   *List=NULL;
}
void deleteList(Linklist *List,Linklist q)//表头节点可能改变地址
{
   Linklist r;
   if(q==*List)//删除节点在表头
   {
       *List=q->next;
       free(q);
   }
   else//删除节点在表中间
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
//在指定q结点后面插入结点，数据为e
*/
/*
Linklist *List相当于Lnode **list;指向指针的指针变量。因为函数中要对List
即表头指针进行修改，调用函数时，实参实际上是&list，而不是list。因此必须
采用指针参数传递的方法，否则无法在被调函数中修改主函数中定义的变量内容
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
        p->next=q->next;//原链表的q的next值赋值给新申请节点的next
        q->next=p;//p的值赋值给q的next
    }
}
int main()
{
    Elemtype e;
    int i;
    Linklist l,q;
    q=l=creatList(1);//创建一个链表结点，ql均指向该节点
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
