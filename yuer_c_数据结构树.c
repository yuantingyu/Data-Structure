//二叉树
#include<stdio.h>
#include<stdlib.h>
typedef  char Elemtype;
typedef struct BITnode
{
    Elemtype data;
    struct BITnode *lchild;
    struct BITnode *rchild;
}BiTnode,*Bitree;
void visit(Elemtype c,int level)
{
    if(c=='D')
        printf("The D in the tree is %d level\n",level);
}
void print(Elemtype c)
{
    printf("%c ",c);
}
void CreatTree(Bitree *T)
{
    Elemtype c;
    scanf("%c",&c);
    if(c==' ')//遇到空格结束，对于一棵树，输入时如果是叶子结点，
        //就打两个空格，只有一个结点，打一个空格
        *T=NULL;
    else
    {
        *T=(BiTnode *)malloc(sizeof(BiTnode));
        (*T)->data=c;
        CreatTree(&((*T)->lchild));
        CreatTree(&((*T)->rchild));
    }
}
//先序遍历二叉树求深度
void PreorderTraversedeep(Bitree T,int level)
{
    if(T)
    {
        visit(T->data,level);
        PreorderTraversedeep(T->lchild,level+1);
        PreorderTraversedeep(T->rchild,level+1);
    }
}
//先序遍历二叉树 根左右
void PreorderTraverse(Bitree T)
{
    if(T)
    {
        print(T->data);
        PreorderTraverse(T->lchild);
        PreorderTraverse(T->rchild);
    }
}
//中序遍历二叉树 左根右
void InorderTraverse(Bitree T)
{
    if(T)
    {
        InorderTraverse(T->lchild);
        print(T->data);
        InorderTraverse(T->rchild);
    }
}
//后序遍历二叉树 左右根
void PosorderTraverse(Bitree T)
{
    if(T)
    {
        PosorderTraverse(T->lchild);
        PosorderTraverse(T->rchild);
        print(T->data);
    }
}
int main()
{
    int level=1;
    Bitree T=NULL;
    printf("请输入字母创建一个树\n");
    CreatTree(&T);
    printf("请输入字母D在树中第几层\n");
    PreorderTraversedeep(T,level);
    printf("请输入树先序遍历结果\n");
    PreorderTraverse(T);
    printf("\n");
    printf("请输入树中序遍历结果\n");
    InorderTraverse(T);
    printf("\n");
    printf("请输入树后序遍历结果\n");
    PosorderTraverse(T);
     printf("\n");
     getche();
}
