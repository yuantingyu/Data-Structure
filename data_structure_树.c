/*
//二叉树三种遍历方式及前序建立
#include<stdio.h>
#include<stdlib.h>
typedef char Telemtype;
typedef struct BiTnode
{
    Telemtype data;
    struct BiTnode  *lchild,*rchild;
}BiTnode,*BiTree;
int PreCreateBiTree(BiTree *T)//前序建立
{
    Telemtype ch;
    scanf("%c",&ch);
    if(ch=='#')
       *T=NULL;
    else
       {
           *T=(BiTree)malloc(sizeof(BiTnode));
           if(!(*T))
            exit(0);
           (*T)->data=ch;
           PreCreateBiTree(&(*T)->lchild);
           PreCreateBiTree(&(*T)->rchild);
       }
    return 1;
}
int InCreateBiTree(BiTree *T)//中序建立有错误，递归终止条件使得无法建立树
{
    Telemtype ch;
    scanf("%c",&ch);
    if(ch=='#')
       *T=NULL;
    else
       {
           *T=(BiTree)malloc(sizeof(BiTnode));
           if(!(*T))
            exit(0);
           InCreateBiTree(&(*T)->lchild);
           (*T)->data=ch;
           InCreateBiTree(&(*T)->rchild);
       }
    return 1;
}

int PostCreateBiTree(BiTree *T)//后序建立  有错误，递归终止条件使得无法建立树
{
    Telemtype ch;
    scanf("%c",&ch);
    if(ch=='#')
       *T=NULL;
    else
       {
           *T=(BiTree)malloc(sizeof(BiTnode));
           if(!(*T))
            exit(0);
           PostCreateBiTree(&(*T)->lchild);
           PostCreateBiTree(&(*T)->rchild);
           (*T)->data=ch;
       }
    return 1;
}
int PreOrderTraverse(BiTree T)//前序
{
    if(T==NULL)
        return 0;
    printf("%c",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    return 1;
}
int InOrderTraverse(BiTree T)//中序
{
    if(T==NULL)
        return 0;
    InOrderTraverse(T->lchild);
    printf("%c",T->data);
    InOrderTraverse(T->rchild);
    return 1;
}
int PostOrderTraverse(BiTree T)//后序
{
    if(T==NULL)
        return 0;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c",T->data);
    return 1;
}
int main()
{
    BiTree T;
    PreCreateBiTree(&T);
    PreOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
}
*/
//二叉线索表
#include<stdio.h>
#include<stdlib.h>
typedef enum{Link,Thread} PointerTag;//Link=0表示指向左右孩子指针
//Thread表示指向前驱或者后继的线索
//枚举类型 列出所有可能的取值，并给它们取一个名字，默认第一个值为0，
//后面依次加一
typedef char Telemtype;
typedef struct BiThrnode//二叉线索树结构
{
    Telemtype data;//结点数据
    struct BiThrnode  *lchild,*rchild;//左右孩子指针
    PointerTag LTag,RTag;//左右标志
}BiThrnode,*BiThrTree;
