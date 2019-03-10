//朴素模式匹配算法KMP
/*
#include<stdio.h>
#include<string.h>
int get_next(char T[],int *next)
{
    int i=0,j=-1;
    next[0]=0;
    while(i<strlen(T))//T[0]表示串T的长度
    {
        if(j==-1||T[i]==T[j])//T[i]表示前缀的单个字符，T[j]表示后缀的单个字符
        {
            i++;
            j++;
            next[i]=j+1;
        }
        else
            j=next[j]-1;//字符不相等，j值回溯

    }
    for(i=0;i<strlen(T);i++)
    printf("%d ",next[i]);
    return 1;
}
int Index_KMP(char S[],char T[],int pos)
{
    int i=pos-1;//i用于主串中当前位置下标值，pos不为1，则从pos位置开始匹配
    int j=0;//子串中当前位置下标值
    int next[20];
    get_next(T,next);
    while(i<strlen(S)&&j<strlen(T))
    {
        if(j==0||S[i]==T[j])
        {
            i++;
            j++;
        }
        else//指针后退重新匹配
            j=next[j-1];//j退回合适位置，i值不变
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
//改进KMP算法
#include<stdio.h>
int get_nextval(char T[],int *nextval)
{
    int i=1,j=0;
    nextval[1]=0;
    while(i<T[0]-'0')//T[0]表示串T的长度
    {
        if(j==0||T[i]==T[j])//T[i]表示前缀的单个字符，T[j]表示后缀的单个字符
        {
            i++;
            j++;
            if(T[i]!=T[j])//当前字符与前缀字符不相等
            {
               nextval[i]=j;//当前j为nextval在i位置上的值
            }
            else//当前字符与前缀字符相等,前缀字符nextval值赋值给i位置上的值
               nextval[i]=nextval[j];
        }
        else
            j=nextval[j];//字符不相等，j值回溯

    }
    for(i=1;i<=T[0]-'0';i++)
        printf("%d ",nextval[i]);
    return 1;
}
int Index_KMP(char S[],char T[],int pos)
{
    int i=pos;//i用于主串中当前位置下标值，pos不为1，则从pos位置开始匹配
    int j=1;//子串中当前位置下标值
    int nextval[20];
    get_nextval(T,nextval);
    while(i<=S[0]-'0'&&j<=T[0]-'0')
    {
        if(j==0||S[i]==T[j])
        {
            i++;
            j++;
        }
        else//指针后退重新匹配
            j=nextval[j];//j退回合适位置，i值不变
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
