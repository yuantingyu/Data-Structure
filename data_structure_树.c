/*
//���������ֱ�����ʽ��ǰ����
#include<stdio.h>
#include<stdlib.h>
typedef char Telemtype;
typedef struct BiTnode
{
    Telemtype data;
    struct BiTnode  *lchild,*rchild;
}BiTnode,*BiTree;
int PreCreateBiTree(BiTree *T)//ǰ����
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
int InCreateBiTree(BiTree *T)//�������д��󣬵ݹ���ֹ����ʹ���޷�������
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

int PostCreateBiTree(BiTree *T)//������  �д��󣬵ݹ���ֹ����ʹ���޷�������
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
int PreOrderTraverse(BiTree T)//ǰ��
{
    if(T==NULL)
        return 0;
    printf("%c",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    return 1;
}
int InOrderTraverse(BiTree T)//����
{
    if(T==NULL)
        return 0;
    InOrderTraverse(T->lchild);
    printf("%c",T->data);
    InOrderTraverse(T->rchild);
    return 1;
}
int PostOrderTraverse(BiTree T)//����
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
//����������
#include<stdio.h>
#include<stdlib.h>
typedef enum{Link,Thread} PointerTag;//Link=0��ʾָ�����Һ���ָ��
//Thread��ʾָ��ǰ�����ߺ�̵�����
//ö������ �г����п��ܵ�ȡֵ����������ȡһ�����֣�Ĭ�ϵ�һ��ֵΪ0��
//�������μ�һ
typedef char Telemtype;
typedef struct BiThrnode//�����������ṹ
{
    Telemtype data;//�������
    struct BiThrnode  *lchild,*rchild;//���Һ���ָ��
    PointerTag LTag,RTag;//���ұ�־
}BiThrnode,*BiThrTree;
