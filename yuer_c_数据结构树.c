//������
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
    if(c==' ')//�����ո����������һ����������ʱ�����Ҷ�ӽ�㣬
        //�ʹ������ո�ֻ��һ����㣬��һ���ո�
        *T=NULL;
    else
    {
        *T=(BiTnode *)malloc(sizeof(BiTnode));
        (*T)->data=c;
        CreatTree(&((*T)->lchild));
        CreatTree(&((*T)->rchild));
    }
}
//������������������
void PreorderTraversedeep(Bitree T,int level)
{
    if(T)
    {
        visit(T->data,level);
        PreorderTraversedeep(T->lchild,level+1);
        PreorderTraversedeep(T->rchild,level+1);
    }
}
//������������� ������
void PreorderTraverse(Bitree T)
{
    if(T)
    {
        print(T->data);
        PreorderTraverse(T->lchild);
        PreorderTraverse(T->rchild);
    }
}
//������������� �����
void InorderTraverse(Bitree T)
{
    if(T)
    {
        InorderTraverse(T->lchild);
        print(T->data);
        InorderTraverse(T->rchild);
    }
}
//������������� ���Ҹ�
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
    printf("��������ĸ����һ����\n");
    CreatTree(&T);
    printf("��������ĸD�����еڼ���\n");
    PreorderTraversedeep(T,level);
    printf("������������������\n");
    PreorderTraverse(T);
    printf("\n");
    printf("������������������\n");
    InorderTraverse(T);
    printf("\n");
    printf("������������������\n");
    PosorderTraverse(T);
     printf("\n");
     getche();
}
