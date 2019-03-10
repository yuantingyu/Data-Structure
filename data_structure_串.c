//����ģʽƥ���㷨KMP
/*
#include<stdio.h>
#include<string.h>
int get_next(char T[],int *next)
{
    int i=0,j=-1;
    next[0]=0;
    while(i<strlen(T))//T[0]��ʾ��T�ĳ���
    {
        if(j==-1||T[i]==T[j])//T[i]��ʾǰ׺�ĵ����ַ���T[j]��ʾ��׺�ĵ����ַ�
        {
            i++;
            j++;
            next[i]=j+1;
        }
        else
            j=next[j]-1;//�ַ�����ȣ�jֵ����

    }
    for(i=0;i<strlen(T);i++)
    printf("%d ",next[i]);
    return 1;
}
int Index_KMP(char S[],char T[],int pos)
{
    int i=pos-1;//i���������е�ǰλ���±�ֵ��pos��Ϊ1�����posλ�ÿ�ʼƥ��
    int j=0;//�Ӵ��е�ǰλ���±�ֵ
    int next[20];
    get_next(T,next);
    while(i<strlen(S)&&j<strlen(T))
    {
        if(j==0||S[i]==T[j])
        {
            i++;
            j++;
        }
        else//ָ���������ƥ��
            j=next[j-1];//j�˻غ���λ�ã�iֵ����
    }
    if(j>=strlen(T))
        return i-strlen(T);
    else
        return 0;
}
int main()
{   char S[20],T[20];
    scanf("%s",S);
    scanf("%s",T);
    int m=Index_KMP(S,T,1);
    printf("%d",m);
}
*/
//�Ľ�KMP�㷨
#include<stdio.h>
int get_nextval(char T[],int *nextval)
{
    int i=1,j=0;
    nextval[1]=0;
    while(i<T[0]-'0')//T[0]��ʾ��T�ĳ���
    {
        if(j==0||T[i]==T[j])//T[i]��ʾǰ׺�ĵ����ַ���T[j]��ʾ��׺�ĵ����ַ�
        {
            i++;
            j++;
            if(T[i]!=T[j])//��ǰ�ַ���ǰ׺�ַ������
            {
               nextval[i]=j;//��ǰjΪnextval��iλ���ϵ�ֵ
            }
            else//��ǰ�ַ���ǰ׺�ַ����,ǰ׺�ַ�nextvalֵ��ֵ��iλ���ϵ�ֵ
               nextval[i]=nextval[j];
        }
        else
            j=nextval[j];//�ַ�����ȣ�jֵ����

    }
    for(i=1;i<=T[0]-'0';i++)
        printf("%d ",nextval[i]);
    return 1;
}
int Index_KMP(char S[],char T[],int pos)
{
    int i=pos;//i���������е�ǰλ���±�ֵ��pos��Ϊ1�����posλ�ÿ�ʼƥ��
    int j=1;//�Ӵ��е�ǰλ���±�ֵ
    int nextval[20];
    get_nextval(T,nextval);
    while(i<=S[0]-'0'&&j<=T[0]-'0')
    {
        if(j==0||S[i]==T[j])
        {
            i++;
            j++;
        }
        else//ָ���������ƥ��
            j=nextval[j];//j�˻غ���λ�ã�iֵ����
    }
    if(j>T[0]-'0')
        return i-(T[0]-'0');
    else
        return 0;
}
int main()
{   char S[20],T[20];
    scanf("%s",S);
    scanf("%s",T);
    int m=Index_KMP(S,T,1);
    printf("%d",m);
}
