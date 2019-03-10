#include<stdio.h>
#include<stdlib.h>
#define Hashsize 12//定义散列表长为数组长度
#define Nullkey -56787
typedef struct
{
    int *elem;//数据元素存储基地址，动态分配数组
    int count;//当前数据元素个数
}HashTable;
int m=0;//散列表长，全局变量
int InitHashTable(HashTable *H)//初始化散列表
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
int Hash(int key)//散列函数，计算插入的地址
{
    return key%m;//除留余数法
}
//插入关键字进散列表
void InsertHash(HashTable *H,int key)
{
    int addr=Hash(key);//求散列地址
    while(H->elem[addr]!=Nullkey)//地址不为空即冲突
    addr=(addr+1)%m;//开放地址法进行探测
    H->elem[addr]=key;

}
int SearchHashTable(HashTable H,int key,int *addr)
{
    *addr=Hash(key);
    while(H.elem[*addr]!=key)//如果查找位置不为key，可能冲突去了别的位置
    {
       *addr=(*addr+1)%m;
       if(H.elem[*addr]==Nullkey||*addr==Hash(key))
        //找到位置为空或者回到起始点，证明不存在这个点
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
