#include<stdio.h>
#include<stdlib.h>
#define Hashsize 12//����ɢ�б�Ϊ���鳤��
#define Nullkey -56787
typedef struct
{
    int *elem;//����Ԫ�ش洢����ַ����̬��������
    int count;//��ǰ����Ԫ�ظ���
}HashTable;
int m=0;//ɢ�б���ȫ�ֱ���
int InitHashTable(HashTable *H)//��ʼ��ɢ�б�
{
    int i;
    m=Hashsize;
    H->count=m;
    H->elem=(int *)malloc(m*sizeof(int));
    for(i=0;i<m;i++)
    {
        H->elem[i]=Nullkey;
    }
    return 0;
}
int Hash(int key)//ɢ�к������������ĵ�ַ
{
    return key%m;//����������
}
//����ؼ��ֽ�ɢ�б�
void InsertHash(HashTable *H,int key)
{
    int addr=Hash(key);//��ɢ�е�ַ
    while(H->elem[addr]!=Nullkey)//��ַ��Ϊ�ռ���ͻ
    addr=(addr+1)%m;//���ŵ�ַ������̽��
    H->elem[addr]=key;

}
int SearchHashTable(HashTable H,int key,int *addr)
{
    *addr=Hash(key);
    while(H.elem[*addr]!=key)//�������λ�ò�Ϊkey�����ܳ�ͻȥ�˱��λ��
    {
       *addr=(*addr+1)%m;
       if(H.elem[*addr]==Nullkey||*addr==Hash(key))
        //�ҵ�λ��Ϊ�ջ��߻ص���ʼ�㣬֤�������������
        return 0;
    }
    return 1;
}
int main()
{
    int addr;
    HashTable H;
    InitHashTable(&H);
    InsertHash(&H,60);
    int k=SearchHashTable(H,60,&addr);
    printf("%d  %d  %d",H.count,H.elem[0],k);
}
