/*
//冒泡排序0
//比较找出较小值与其不断交换位置
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
void swap(Sqlist *L,int i,int j)//交换顺序表中i和j位置上的值
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
int BubbleSort0(Sqlist *L)
{
   int i,j;
   for(i=1;i<=L->length;i++)
   {
       for(j=i+1;j<=L->length;j++)
       {
           if(L->r[i]>L->r[j])
            swap(L,i,j);
       }
   }
   return 1;
}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
       L.length=5;
    BubbleSort0(&L);
    for(i=1;i<6;i++)
        printf("%d",L.r[i]);

}
//冒泡排序1
//相邻两数不断交换位置
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
void swap(Sqlist *L,int i,int j)//交换顺序表中i和j位置上的值
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
int BubbleSort1(Sqlist *L)
{
   int i,j;
   for(i=1;i<=L->length;i++)
   {
       for(j=L->length;j>i;j--)
       {
           if(L->r[j]<L->r[j-1])
            swap(L,j,j-1);
       }
   }
   return 1;
}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
       L.length=5;
    BubbleSort1(&L);
    for(i=1;i<6;i++)
        printf("%d",L.r[i]);

}
//冒泡排序2
//相邻两数不断交换位置,通过标志旗帜来解决后续已经有序但仍需继续比较的问题
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
void swap(Sqlist *L,int i,int j)//交换顺序表中i和j位置上的值
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
int BubbleSort2(Sqlist *L)
{
   int i,j;
   int flag=1;//flag用来做标记
   for(i=1;i<=L->length&&flag;i++)//flag为0退出循环
   {
       flag=0;
       for(j=L->length;j>i;j--)
       {
           if(L->r[j]<L->r[j-1])
           {
               swap(L,j,j-1);
               flag=1;//有数据交换，flag就为1
           }
       }
       printf("%d ",flag);
   }
   return 1;
}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
       L.length=5;
    BubbleSort2(&L);
    for(i=1;i<6;i++)
        printf("%d",L.r[i]);
}
//简单选择排序
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
void swap(Sqlist *L,int i,int j)//交换顺序表中i和j位置上的值
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
int SelectSort(Sqlist *L)
{
    int i,j,min;
    for(i=1;i<=L->length;i++)
    {
        min=i;
        for(j=i+1;j<=L->length;j++)
        {
            if(L->r[min]>L->r[j])
                min=j;
        }
        swap(L,i,min);
    }
}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
       L.length=5;
    SelectSort(&L);
    for(i=1;i<6;i++)
        printf("%d",L.r[i]);
}
//直接插入排序
//默认第一个是有序的，其他的以其为基准不断往里调整顺序
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
int InsertSort(Sqlist *L)
{
    int i,j;
    for(i=2;i<=L->length;i++)
    {
        if(L->r[i]<L->r[i-1])
        {
            L->r[0]=L->r[i];//设置哨兵
            for(j=i-1;L->r[j]>L->r[0];j--)
                L->r[j+1]=L->r[j];//记录后移
            L->r[j+1]=L->r[0];//插入到正确位置
        }
    }
}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
       L.length=5;
    InsertSort(&L);
    for(i=1;i<6;i++)
        printf("%d",L.r[i]);
}
//希尔排序
//间隔一定长度来跳跃式挪移，达到部分有序
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
void swap(Sqlist *L,int i,int j)//交换顺序表中i和j位置上的值
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
int ShellSort(Sqlist *L)
{
    int i,j;
    int increment=L->length;
    do{
        increment=increment/3+1;
        for(i=increment+1;i<L->length;i++)
        {
            if(L->r[i]<L->r[i-increment])
            {
                swap(L,i,i-increment);
            }
        }
    }while(increment>1);
}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
    L.length=6;
    ShellSort(&L);
    for(i=1;i<6;i++)
        printf("%d ",L.r[i]);
}
//堆排序
//从下到上。从左到右依次调整根堆，将堆顶元素依次与尾结点交换位置
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
void swap(Sqlist *L,int i,int j)//交换顺序表中i和j位置上的值
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
void AdjustHeap(Sqlist *L,int s,int m)
{
    int temp,i;
    temp=L->r[s];
    for(i=2*s;i<=m;i*=2)//从上到下原则
    {
        if(i<m)//当前下标为i的结点还有右节点
            i=L->r[i+1]>L->r[i]?i+1:i;//较大的孩子下标
        if(temp>=L->r[i])
            break;//根节点比孩子大，不需要调整
        L->r[s]=L->r[i];//否则调整位置
        L->r[i]=temp;
        s=i;//控制循环作用，后面的每个结点都要调整为大根堆
    }
}
void HeapSort(Sqlist *L)
{
    int i;
    //把初始状态的r建立成一个大根堆
    for(i=L->length/2;i>0;i--)//从下到上原则
    {
        AdjustHeap(L,i,L->length);
    }
    //排序阶段，将堆顶元素和当前未经排序子序列末尾结点交换位置
    for(i=L->length;i>0;i--)
    {
        swap(L,1,i);
        AdjustHeap(L,1,i-1);
    }

}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
    L.length=5;
    HeapSort(&L);
    for(i=1;i<6;i++)
        printf("%d ",L.r[i]);
}
//快速排序0
//采用分而治之思想，不断选取中间枢纽值来划分局部有序的序列
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
void swap(Sqlist *L,int i,int j)//交换顺序表中i和j位置上的值
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
int Partition(Sqlist *L,int low,int high)
{
    int p=L->r[low];//用表中第一个位置作为枢纽记录
    while(low<high)
    {
        //比枢纽小的交换到低端
        while(low<high&&L->r[high]>=p)
            high--;
        swap(L,low,high);
        //比枢纽大的交换到高端
        while(low<high&&L->r[low]<=p)
            low++;
        swap(L,low,high);
    }
    return low;//返回枢纽所在位置
}
//对顺序表的子序列做快排r[low...high]
void QSort(Sqlist *L,int low,int high)
{
    int p;
    if(low<high)
    {
        p=Partition(L,low,high);//将L一分为二，求出枢纽值位置p
        QSort(L,low,p-1);//低子表递归排序
        QSort(L,p+1,high);//高子表递归排序
    }
}
void QuickSort(Sqlist *L)
{
    QSort(L,1,L->length);

}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
    L.length=5;
    QuickSort(&L);
    for(i=1;i<6;i++)
        printf("%d ",L.r[i]);
}
//快速排序1
//把swap变为=
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
int Partition(Sqlist *L,int low,int high)
{
    int p=L->r[low];//用表中第一个位置作为枢纽记录
    L->r[0]=p;//枢纽关键值备份到r[0]
    while(low<high)
    {
        //比枢纽小的交换到低端
        while(low<high&&L->r[high]>=p)
            high--;
        L->r[low]=L->r[high];//替换而不是交换
        //比枢纽大的交换到高端
        while(low<high&&L->r[low]<=p)
            low++;
        L->r[high]=L->r[low];
    }
    L->r[low]=L->r[0];//将枢纽替换回L->r[low],也可以是L->r[high],因为此时high==low
    return low;//返回枢纽所在位置
}
//对顺序表的子序列做快排r[low...high]
void QSort(Sqlist *L,int low,int high)
{
    int p;
    if(low<high)
    {
        p=Partition(L,low,high);//将L一分为二，求出枢纽值位置p
        QSort(L,low,p-1);//低子表递归排序
        QSort(L,p+1,high);//高子表递归排序
    }
}
void QuickSort(Sqlist *L)
{
    QSort(L,1,L->length);

}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
    L.length=5;
    QuickSort(&L);
    for(i=1;i<6;i++)
        printf("%d ",L.r[i]);
}
//快速排序2
//小数组用直插，大数组部分用快排
#include<stdio.h>
#define Maxsize 10
#include<stdio.h>
#define MAX_LENGTH_QUICKSORT 2
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
int InsertSort(Sqlist *L)
{
    int i,j;
    for(i=2;i<=L->length;i++)
    {
        if(L->r[i]<L->r[i-1])
        {
            L->r[0]=L->r[i];//设置哨兵
            for(j=i-1;L->r[j]>L->r[0];j--)
                L->r[j+1]=L->r[j];//记录后移
            L->r[j+1]=L->r[0];//插入到正确位置
        }
    }
}
int Partition(Sqlist *L,int low,int high)
{
    int p=L->r[low];//用表中第一个位置作为枢纽记录
    L->r[0]=p;//枢纽关键值备份到r[0]
    while(low<high)
    {
        //比枢纽小的交换到低端
        while(low<high&&L->r[high]>=p)
            high--;
        L->r[low]=L->r[high];//替换而不是交换
        //比枢纽大的交换到高端
        while(low<high&&L->r[low]<=p)
            low++;
        L->r[high]=L->r[low];
    }
    L->r[low]=L->r[0];//将枢纽替换回L->r[low],也可以是L->r[high],因为此时high==low
    return low;//返回枢纽所在位置
}
//对顺序表的子序列做快排r[low...high]
void QSort(Sqlist *L,int low,int high)
{
    int p;
    if((high-low)>MAX_LENGTH_QUICKSORT)
    {
        p=Partition(L,low,high);//将L一分为二，求出枢纽值位置p
        QSort(L,low,p-1);//低子表递归排序
        QSort(L,p+1,high);//高子表递归排序
    }
    else
        InsertSort(L);
}
void QuickSort(Sqlist *L)
{
    QSort(L,1,L->length);

}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
    L.length=5;
    QuickSort(&L);
    for(i=1;i<6;i++)
        printf("%d ",L.r[i]);
}
//快速排序3
//迭代变为尾递归
#include<stdio.h>
#define Maxsize 10
#include<stdio.h>
#define MAX_LENGTH_QUICKSORT 2
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
int InsertSort(Sqlist *L)
{
    int i,j;
    for(i=2;i<=L->length;i++)
    {
        if(L->r[i]<L->r[i-1])
        {
            L->r[0]=L->r[i];//设置哨兵
            for(j=i-1;L->r[j]>L->r[0];j--)
                L->r[j+1]=L->r[j];//记录后移
            L->r[j+1]=L->r[0];//插入到正确位置
        }
    }
}
int Partition(Sqlist *L,int low,int high)
{
    int p=L->r[low];//用表中第一个位置作为枢纽记录
    L->r[0]=p;//枢纽关键值备份到r[0]
    while(low<high)
    {
        //比枢纽小的交换到低端
        while(low<high&&L->r[high]>=p)
            high--;
        L->r[low]=L->r[high];//替换而不是交换
        //比枢纽大的交换到高端
        while(low<high&&L->r[low]<=p)
            low++;
        L->r[high]=L->r[low];
    }
    L->r[low]=L->r[0];//将枢纽替换回L->r[low],也可以是L->r[high],因为此时high==low
    return low;//返回枢纽所在位置
}
//对顺序表的子序列做快排r[low...high]
void QSort(Sqlist *L,int low,int high)
{
    int p;
    if((high-low)>MAX_LENGTH_QUICKSORT)
    {
        while(low<high)
        {
            p=Partition(L,low,high);
            QSort(L,low,p-1);//尾递归
            low=p+1;
        }
    }
    else
        InsertSort(L);
}
void QuickSort(Sqlist *L)
{
    QSort(L,1,L->length);
}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
    L.length=5;
    QuickSort(&L);
    for(i=1;i<6;i++)
        printf("%d ",L.r[i]);
}
//快速排序4
//p值选取变为三点取中low，high，middle
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
void swap(Sqlist *L,int i,int j)//交换顺序表中i和j位置上的值
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
int Partition(Sqlist *L,int low,int high)
{
    int p,m;
    m=low+(low+high)/2;//计算数组中间下标
    if(L->r[low]>L->r[high])
        swap(L,low,high);//交换左右数据，保证左端较小
    if(L->r[m]>L->r[high])
        swap(L,m,high);//交换右中数据，保证中间较小
    if(L->r[low]<L->r[m])
        swap(L,low,m);//交换左中数据，保证中间较小，low即为中间值
    p=L->r[low];//用表中第一个位置作为枢纽记录
    while(low<high)
    {
        //比枢纽小的交换到低端
        while(low<high&&L->r[high]>=p)
            high--;
        swap(L,low,high);
        //比枢纽大的交换到高端
        while(low<high&&L->r[low]<=p)
            low++;
        swap(L,low,high);
    }
    return low;//返回枢纽所在位置
}
//对顺序表的子序列做快排r[low...high]
void QSort(Sqlist *L,int low,int high)
{
    int p;
    if(low<high)
    {
        p=Partition(L,low,high);//将L一分为二，求出枢纽值位置p
        QSort(L,low,p-1);//低子表递归排序
        QSort(L,p+1,high);//高子表递归排序
    }
}
void QuickSort(Sqlist *L)
{
    QSort(L,1,L->length);

}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
    L.length=5;
    QuickSort(&L);
    for(i=1;i<6;i++)
        printf("%d ",L.r[i]);
}
*/
//2路归并排序
//
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//储存要排序数组，r[0]用作哨兵
    int length;//顺序表长度
}Sqlist;
void swap(Sqlist *L,int i,int j)//交换顺序表中i和j位置上的值
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
int Partition(Sqlist *L,int low,int high)
{
    int p,m;
    m=low+(low+high)/2;//计算数组中间下标
    if(L->r[low]>L->r[high])
        swap(L,low,high);//交换左右数据，保证左端较小
    if(L->r[m]>L->r[high])
        swap(L,m,high);//交换右中数据，保证中间较小
    if(L->r[low]<L->r[m])
        swap(L,low,m);//交换左中数据，保证中间较小，low即为中间值
    p=L->r[low];//用表中第一个位置作为枢纽记录
    while(low<high)
    {
        //比枢纽小的交换到低端
        while(low<high&&L->r[high]>=p)
            high--;
        swap(L,low,high);
        //比枢纽大的交换到高端
        while(low<high&&L->r[low]<=p)
            low++;
        swap(L,low,high);
    }
    return low;//返回枢纽所在位置
}
//对顺序表的子序列做快排r[low...high]
void QSort(Sqlist *L,int low,int high)
{
    int p;
    if(low<high)
    {
        p=Partition(L,low,high);//将L一分为二，求出枢纽值位置p
        QSort(L,low,p-1);//低子表递归排序
        QSort(L,p+1,high);//高子表递归排序
    }
}
void QuickSort(Sqlist *L)
{
    QSort(L,1,L->length);

}
int main()
{
    Sqlist L;
    int i;
    for(i=1;i<6;i++)
        scanf("%d",&L.r[i]);
    L.length=5;
    QuickSort(&L);
    for(i=1;i<6;i++)
        printf("%d ",L.r[i]);
}




