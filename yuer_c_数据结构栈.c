#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define Statement 20
#define Init_size 10
typedef char Elemtype;
typedef struct
{
    Elemtype *top;
    Elemtype *base;
    int stacksize;//ջ��ǰ�������������ָ����ĵ�ַ��Ӧ�ģ������Ѿ�ʹ�õ�
}sqStack;
void Initstack(sqStack *s)//��ʼ��
{
    s->base=(Elemtype *)malloc(Statement*sizeof(Elemtype));
    if(!s->base) exit(0);//����ռ�ʧ��
    s->top=s->base;//�ʼ����ջջ������ջ��
    s->stacksize=Statement;
}
void Pop(sqStack *s,Elemtype *e)//��ջ
{
    if(s->top==s->base) return;//ջ��ֱ���˳�
    *e=*--(s->top);
}
void Push(sqStack *s,Elemtype e)//��ջ
{
    if(s->top-s->base>=s->stacksize)//ջ����׷�ӿռ�
    {
        s->base=(Elemtype *)realloc(s->base,(s->stacksize+
        Init_size)*sizeof(Elemtype));//׷�ӵ�ַ
        if(!s->base)
            exit(0);
        s->top=s->base+s->stacksize;
        s->stacksize=s->stacksize+Init_size;//����ջ�������
    }
    *(s->top)=e;//��������ջ
    s->top++;
}
int Stacklen(sqStack *s)//ջ���ȣ�Ҳ���Դ���ֵ����int Stacklen(sqStack s)
{
    return (s->top-s->base);
}
int main()
{
  Elemtype c;
  sqStack s;
  int i,len,sum=0;
  printf("Please input a binary digit\n");
  Initstack(&s);//����һ��ջ����Ŷ������ַ���
  scanf("%c",&c);
  while(c!='#')
  {
      if(c == '0' || c == '1')//��ֹ������������
      Push(&s,c);
      scanf("%c",&c);
  }
  len=Stacklen(&s);//�õ�ջ��Ԫ�ظ��������������ĳ���
  for(i=0;i<len;i++)
  {
      Pop(&s,&c);
      sum=sum+(c-48)*pow(2,i);//ת��Ϊʮ����
  }
  printf("Decimal is %d\n",sum);
}
//ջ����������
//���ջ  ջ��Ԫ��ȫ�����ϣ�����ռ䲻һ�������仯
Clearstack(sqStack *s)
{
   s->top=s->base;
}
//����ջ   �ͷſռ�Ū��ջ��������0
Destroystack(sqStack *s)
{
    int i,len;
    len=s->stacksize;
    for(i=0;i<len;i++)
    {
        free(s->base);
        s->base++;
    }
    s->base=s->top=NULL;
    s->stacksize=0;
}
