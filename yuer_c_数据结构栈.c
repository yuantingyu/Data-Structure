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
    int stacksize;//栈当前可用最大容量，指分配的地址对应的，包括已经使用的
}sqStack;
void Initstack(sqStack *s)//初始化
{
    s->base=(Elemtype *)malloc(Statement*sizeof(Elemtype));
    if(!s->base) exit(0);//分配空间失败
    s->top=s->base;//最开始，空栈栈顶就是栈底
    s->stacksize=Statement;
}
void Pop(sqStack *s,Elemtype *e)//出栈
{
    if(s->top==s->base) return;//栈空直接退出
    *e=*--(s->top);
}
void Push(sqStack *s,Elemtype e)//入栈
{
    if(s->top-s->base>=s->stacksize)//栈满，追加空间
    {
        s->base=(Elemtype *)realloc(s->base,(s->stacksize+
        Init_size)*sizeof(Elemtype));//追加地址
        if(!s->base)
            exit(0);
        s->top=s->base+s->stacksize;
        s->stacksize=s->stacksize+Init_size;//设置栈最大容量
    }
    *(s->top)=e;//将数字入栈
    s->top++;
}
int Stacklen(sqStack *s)//栈长度，也可以传递值变量int Stacklen(sqStack s)
{
    return (s->top-s->base);
}
int main()
{
  Elemtype c;
  sqStack s;
  int i,len,sum=0;
  printf("Please input a binary digit\n");
  Initstack(&s);//创建一个栈，存放二进制字符串
  scanf("%c",&c);
  while(c!='#')
  {
      if(c == '0' || c == '1')//防止其他数据乱入
      Push(&s,c);
      scanf("%c",&c);
  }
  len=Stacklen(&s);//得到栈中元素个数，二进制数的长度
  for(i=0;i<len;i++)
  {
      Pop(&s,&c);
      sum=sum+(c-48)*pow(2,i);//转换为十进制
  }
  printf("Decimal is %d\n",sum);
}
//栈的其他操作
//清空栈  栈中元素全部作废，物理空间不一定发生变化
Clearstack(sqStack *s)
{
   s->top=s->base;
}
//销毁栈   释放空间弄空栈，长度置0
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
