//Prim�㷨
#include<stdio.h>
#include<stdlib.h>
#define maxvex 10
#define infinity 65535
int visit[maxvex];
typedef char VertexType;//��������
typedef int Edgetype;//Ȩֵ����
typedef struct
{
    VertexType vex[maxvex];//��������
    int arc[maxvex][maxvex];//�ڽӾ���
    int numvertexes,numedges;//��ǰ�������ͱ���
}Mygraph;
void Creategraph(Mygraph *G)
{
    FILE *fp=fopen("./input_graph.txt","rt");
    int i,j,k,w;
    if(!fp) printf("error");
    fscanf(fp,"%d %d",&G->numvertexes,&G->numedges);//�������ͱ���
    fgetc(fp);//%c����ܻس��ַ�������������һ�£���Ȼ�����
    for(i=0;i<G->numvertexes;i++)//���붥����Ϣ
    {
        fscanf(fp,"%c",&G->vex[i]);
    }
    fgetc(fp);
    for(i=0;i<G->numvertexes;i++)
    for(j=0;j<G->numvertexes;j++)//�ڽӾ����ʼ��
    {
        G->arc[i][j]=infinity;
    }
    for(k=0;k<G->numedges;k++)
    {
        fscanf(fp,"%d%d%d",&i,&j,&w);//�ߣ�vi,vj���϶�����ż�Ȩֵ
        G->arc[i][j]=w;
        G->arc[j][i]=w;
    }
    fclose(fp);
}
void MiniSpanTree_Prim(Mygraph G)
{
    int lowcost[maxvex];//������ض����Ȩֵ
    int adjvex[maxvex];//������ض�����±�
    int i,j,min,k,sum=0;
    lowcost[0]=0;//��ʼ����һ��ȨֵΪ0������һ������������
    adjvex[0]=0;//��ʼ����һ�������±�Ϊ0
    for(i=1;i<G.numvertexes;i++)//ѭ�����±�Ϊ0��ȫ�����
    {
        lowcost[i]=G.arc[0][i];
        adjvex[i]=0;//��ʼ����Ϊv0���±�
    }
    for(i=1;i<G.numvertexes;i++)
    {
        min=infinity;//��ʼ����СȨֵΪ����
        j=1;k=0;
        while(j<G.numvertexes)//ѭ��ȫ�����
        {
            if(lowcost[j]!=0&&lowcost[j]<min)//�±�Ϊj�Ľ��δ��������ȨֵС��min
            {
                min=lowcost[j];//��ǰ��Ϊ��СȨֵ
                k=j;
            }
            j++;
        }
        sum+=min;
        printf("(%d %d) ",adjvex[k],k);//��ӡ��ǰ������е�Ȩֵ��Сֵ
        lowcost[k]=0;//��ǰ����Ȩֵ��Ϊ0����ʾ�Ѿ���������
        for(j=1;j<G.numvertexes;j++)
        {
            if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
            {//���±�Ϊk�������ȨֵС�ڴ�ǰ����δ���������Ķ���
                lowcost[j]=G.arc[k][j];//����СȨֵ����lowcost
                adjvex[j]=k;//���±�Ϊk�ĵ����adjvex
            }
        }
    }
    printf("%d ",sum);
}
int iniSpanTree_Kruskal()
{

}
int main()
{
    Mygraph G;
    Creategraph(&G);
    MiniSpanTree_Prim(G);
    iniSpanTree_Kruskal(G);
}
