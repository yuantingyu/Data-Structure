/*
//ð������0
//�Ƚ��ҳ���Сֵ���䲻�Ͻ���λ��
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
void swap(Sqlist *L,int i,int j)//����˳�����i��jλ���ϵ�ֵ
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
//ð������1
//�����������Ͻ���λ��
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
void swap(Sqlist *L,int i,int j)//����˳�����i��jλ���ϵ�ֵ
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
//ð������2
//�����������Ͻ���λ��,ͨ����־��������������Ѿ�������������Ƚϵ�����
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
void swap(Sqlist *L,int i,int j)//����˳�����i��jλ���ϵ�ֵ
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
int BubbleSort2(Sqlist *L)
{
   int i,j;
   int flag=1;//flag���������
   for(i=1;i<=L->length&&flag;i++)//flagΪ0�˳�ѭ��
   {
       flag=0;
       for(j=L->length;j>i;j--)
       {
           if(L->r[j]<L->r[j-1])
           {
               swap(L,j,j-1);
               flag=1;//�����ݽ�����flag��Ϊ1
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
//��ѡ������
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
void swap(Sqlist *L,int i,int j)//����˳�����i��jλ���ϵ�ֵ
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
//ֱ�Ӳ�������
//Ĭ�ϵ�һ��������ģ�����������Ϊ��׼�����������˳��
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
int InsertSort(Sqlist *L)
{
    int i,j;
    for(i=2;i<=L->length;i++)
    {
        if(L->r[i]<L->r[i-1])
        {
            L->r[0]=L->r[i];//�����ڱ�
            for(j=i-1;L->r[j]>L->r[0];j--)
                L->r[j+1]=L->r[j];//��¼����
            L->r[j+1]=L->r[0];//���뵽��ȷλ��
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
//ϣ������
//���һ����������ԾʽŲ�ƣ��ﵽ��������
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
void swap(Sqlist *L,int i,int j)//����˳�����i��jλ���ϵ�ֵ
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
//������
//���µ��ϡ����������ε������ѣ����Ѷ�Ԫ��������β��㽻��λ��
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
void swap(Sqlist *L,int i,int j)//����˳�����i��jλ���ϵ�ֵ
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
void AdjustHeap(Sqlist *L,int s,int m)
{
    int temp,i;
    temp=L->r[s];
    for(i=2*s;i<=m;i*=2)//���ϵ���ԭ��
    {
        if(i<m)//��ǰ�±�Ϊi�Ľ�㻹���ҽڵ�
            i=L->r[i+1]>L->r[i]?i+1:i;//�ϴ�ĺ����±�
        if(temp>=L->r[i])
            break;//���ڵ�Ⱥ��Ӵ󣬲���Ҫ����
        L->r[s]=L->r[i];//�������λ��
        L->r[i]=temp;
        s=i;//����ѭ�����ã������ÿ����㶼Ҫ����Ϊ�����
    }
}
void HeapSort(Sqlist *L)
{
    int i;
    //�ѳ�ʼ״̬��r������һ�������
    for(i=L->length/2;i>0;i--)//���µ���ԭ��
    {
        AdjustHeap(L,i,L->length);
    }
    //����׶Σ����Ѷ�Ԫ�غ͵�ǰδ������������ĩβ��㽻��λ��
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
//��������0
//���÷ֶ���֮˼�룬����ѡȡ�м���Ŧֵ�����־ֲ����������
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
void swap(Sqlist *L,int i,int j)//����˳�����i��jλ���ϵ�ֵ
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
int Partition(Sqlist *L,int low,int high)
{
    int p=L->r[low];//�ñ��е�һ��λ����Ϊ��Ŧ��¼
    while(low<high)
    {
        //����ŦС�Ľ������Ͷ�
        while(low<high&&L->r[high]>=p)
            high--;
        swap(L,low,high);
        //����Ŧ��Ľ������߶�
        while(low<high&&L->r[low]<=p)
            low++;
        swap(L,low,high);
    }
    return low;//������Ŧ����λ��
}
//��˳����������������r[low...high]
void QSort(Sqlist *L,int low,int high)
{
    int p;
    if(low<high)
    {
        p=Partition(L,low,high);//��Lһ��Ϊ���������Ŧֵλ��p
        QSort(L,low,p-1);//���ӱ�ݹ�����
        QSort(L,p+1,high);//���ӱ�ݹ�����
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
//��������1
//��swap��Ϊ=
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
int Partition(Sqlist *L,int low,int high)
{
    int p=L->r[low];//�ñ��е�һ��λ����Ϊ��Ŧ��¼
    L->r[0]=p;//��Ŧ�ؼ�ֵ���ݵ�r[0]
    while(low<high)
    {
        //����ŦС�Ľ������Ͷ�
        while(low<high&&L->r[high]>=p)
            high--;
        L->r[low]=L->r[high];//�滻�����ǽ���
        //����Ŧ��Ľ������߶�
        while(low<high&&L->r[low]<=p)
            low++;
        L->r[high]=L->r[low];
    }
    L->r[low]=L->r[0];//����Ŧ�滻��L->r[low],Ҳ������L->r[high],��Ϊ��ʱhigh==low
    return low;//������Ŧ����λ��
}
//��˳����������������r[low...high]
void QSort(Sqlist *L,int low,int high)
{
    int p;
    if(low<high)
    {
        p=Partition(L,low,high);//��Lһ��Ϊ���������Ŧֵλ��p
        QSort(L,low,p-1);//���ӱ�ݹ�����
        QSort(L,p+1,high);//���ӱ�ݹ�����
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
//��������2
//С������ֱ�壬�����鲿���ÿ���
#include<stdio.h>
#define Maxsize 10
#include<stdio.h>
#define MAX_LENGTH_QUICKSORT 2
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
int InsertSort(Sqlist *L)
{
    int i,j;
    for(i=2;i<=L->length;i++)
    {
        if(L->r[i]<L->r[i-1])
        {
            L->r[0]=L->r[i];//�����ڱ�
            for(j=i-1;L->r[j]>L->r[0];j--)
                L->r[j+1]=L->r[j];//��¼����
            L->r[j+1]=L->r[0];//���뵽��ȷλ��
        }
    }
}
int Partition(Sqlist *L,int low,int high)
{
    int p=L->r[low];//�ñ��е�һ��λ����Ϊ��Ŧ��¼
    L->r[0]=p;//��Ŧ�ؼ�ֵ���ݵ�r[0]
    while(low<high)
    {
        //����ŦС�Ľ������Ͷ�
        while(low<high&&L->r[high]>=p)
            high--;
        L->r[low]=L->r[high];//�滻�����ǽ���
        //����Ŧ��Ľ������߶�
        while(low<high&&L->r[low]<=p)
            low++;
        L->r[high]=L->r[low];
    }
    L->r[low]=L->r[0];//����Ŧ�滻��L->r[low],Ҳ������L->r[high],��Ϊ��ʱhigh==low
    return low;//������Ŧ����λ��
}
//��˳����������������r[low...high]
void QSort(Sqlist *L,int low,int high)
{
    int p;
    if((high-low)>MAX_LENGTH_QUICKSORT)
    {
        p=Partition(L,low,high);//��Lһ��Ϊ���������Ŧֵλ��p
        QSort(L,low,p-1);//���ӱ�ݹ�����
        QSort(L,p+1,high);//���ӱ�ݹ�����
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
//��������3
//������Ϊβ�ݹ�
#include<stdio.h>
#define Maxsize 10
#include<stdio.h>
#define MAX_LENGTH_QUICKSORT 2
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
int InsertSort(Sqlist *L)
{
    int i,j;
    for(i=2;i<=L->length;i++)
    {
        if(L->r[i]<L->r[i-1])
        {
            L->r[0]=L->r[i];//�����ڱ�
            for(j=i-1;L->r[j]>L->r[0];j--)
                L->r[j+1]=L->r[j];//��¼����
            L->r[j+1]=L->r[0];//���뵽��ȷλ��
        }
    }
}
int Partition(Sqlist *L,int low,int high)
{
    int p=L->r[low];//�ñ��е�һ��λ����Ϊ��Ŧ��¼
    L->r[0]=p;//��Ŧ�ؼ�ֵ���ݵ�r[0]
    while(low<high)
    {
        //����ŦС�Ľ������Ͷ�
        while(low<high&&L->r[high]>=p)
            high--;
        L->r[low]=L->r[high];//�滻�����ǽ���
        //����Ŧ��Ľ������߶�
        while(low<high&&L->r[low]<=p)
            low++;
        L->r[high]=L->r[low];
    }
    L->r[low]=L->r[0];//����Ŧ�滻��L->r[low],Ҳ������L->r[high],��Ϊ��ʱhigh==low
    return low;//������Ŧ����λ��
}
//��˳����������������r[low...high]
void QSort(Sqlist *L,int low,int high)
{
    int p;
    if((high-low)>MAX_LENGTH_QUICKSORT)
    {
        while(low<high)
        {
            p=Partition(L,low,high);
            QSort(L,low,p-1);//β�ݹ�
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
//��������4
//pֵѡȡ��Ϊ����ȡ��low��high��middle
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
void swap(Sqlist *L,int i,int j)//����˳�����i��jλ���ϵ�ֵ
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
int Partition(Sqlist *L,int low,int high)
{
    int p,m;
    m=low+(low+high)/2;//���������м��±�
    if(L->r[low]>L->r[high])
        swap(L,low,high);//�����������ݣ���֤��˽�С
    if(L->r[m]>L->r[high])
        swap(L,m,high);//�����������ݣ���֤�м��С
    if(L->r[low]<L->r[m])
        swap(L,low,m);//�����������ݣ���֤�м��С��low��Ϊ�м�ֵ
    p=L->r[low];//�ñ��е�һ��λ����Ϊ��Ŧ��¼
    while(low<high)
    {
        //����ŦС�Ľ������Ͷ�
        while(low<high&&L->r[high]>=p)
            high--;
        swap(L,low,high);
        //����Ŧ��Ľ������߶�
        while(low<high&&L->r[low]<=p)
            low++;
        swap(L,low,high);
    }
    return low;//������Ŧ����λ��
}
//��˳����������������r[low...high]
void QSort(Sqlist *L,int low,int high)
{
    int p;
    if(low<high)
    {
        p=Partition(L,low,high);//��Lһ��Ϊ���������Ŧֵλ��p
        QSort(L,low,p-1);//���ӱ�ݹ�����
        QSort(L,p+1,high);//���ӱ�ݹ�����
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
//2·�鲢����
//
#include<stdio.h>
#define Maxsize 10
typedef struct
{
    int r[Maxsize];//����Ҫ�������飬r[0]�����ڱ�
    int length;//˳�����
}Sqlist;
void swap(Sqlist *L,int i,int j)//����˳�����i��jλ���ϵ�ֵ
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
int Partition(Sqlist *L,int low,int high)
{
    int p,m;
    m=low+(low+high)/2;//���������м��±�
    if(L->r[low]>L->r[high])
        swap(L,low,high);//�����������ݣ���֤��˽�С
    if(L->r[m]>L->r[high])
        swap(L,m,high);//�����������ݣ���֤�м��С
    if(L->r[low]<L->r[m])
        swap(L,low,m);//�����������ݣ���֤�м��С��low��Ϊ�м�ֵ
    p=L->r[low];//�ñ��е�һ��λ����Ϊ��Ŧ��¼
    while(low<high)
    {
        //����ŦС�Ľ������Ͷ�
        while(low<high&&L->r[high]>=p)
            high--;
        swap(L,low,high);
        //����Ŧ��Ľ������߶�
        while(low<high&&L->r[low]<=p)
            low++;
        swap(L,low,high);
    }
    return low;//������Ŧ����λ��
}
//��˳����������������r[low...high]
void QSort(Sqlist *L,int low,int high)
{
    int p;
    if(low<high)
    {
        p=Partition(L,low,high);//��Lһ��Ϊ���������Ŧֵλ��p
        QSort(L,low,p-1);//���ӱ�ݹ�����
        QSort(L,p+1,high);//���ӱ�ݹ�����
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




