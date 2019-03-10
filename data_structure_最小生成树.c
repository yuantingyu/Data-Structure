//Prim算法
#include<stdio.h>
#include<stdlib.h>
#define maxvex 10
#define infinity 65535
int visit[maxvex];
typedef char VertexType;//顶点类型
typedef int Edgetype;//权值类型
typedef struct
{
    VertexType vex[maxvex];//顶点数组
    int arc[maxvex][maxvex];//邻接矩阵
    int numvertexes,numedges;//当前顶点数和边数
}Mygraph;
void Creategraph(Mygraph *G)
{
    FILE *fp=fopen("./input_graph.txt","rt");
    int i,j,k,w;
    if(!fp) printf("error");
    fscanf(fp,"%d %d",&G->numvertexes,&G->numedges);//顶点数和边数
    fgetc(fp);//%c会接受回车字符，所以用它接一下，不然会出错
    for(i=0;i<G->numvertexes;i++)//输入顶点信息
    {
        fscanf(fp,"%c",&G->vex[i]);
    }
    fgetc(fp);
    for(i=0;i<G->numvertexes;i++)
    for(j=0;j<G->numvertexes;j++)//邻接矩阵初始化
    {
        G->arc[i][j]=infinity;
    }
    for(k=0;k<G->numedges;k++)
    {
        fscanf(fp,"%d%d%d",&i,&j,&w);//边（vi,vj）上顶点序号及权值
        G->arc[i][j]=w;
        G->arc[j][i]=w;
    }
    fclose(fp);
}
void MiniSpanTree_Prim(Mygraph G)
{
    int lowcost[maxvex];//保存相关顶点间权值
    int adjvex[maxvex];//保存相关顶点间下标
    int i,j,min,k,sum=0;
    lowcost[0]=0;//初始化第一个权值为0，即第一个结点加入主树
    adjvex[0]=0;//初始化第一个顶点下标为0
    for(i=1;i<G.numvertexes;i++)//循环除下标为0的全部结点
    {
        lowcost[i]=G.arc[0][i];
        adjvex[i]=0;//初始化都为v0的下标
    }
    for(i=1;i<G.numvertexes;i++)
    {
        min=infinity;//初始化最小权值为无穷
        j=1;k=0;
        while(j<G.numvertexes)//循环全部结点
        {
            if(lowcost[j]!=0&&lowcost[j]<min)//下标为j的结点未加入树且权值小于min
            {
                min=lowcost[j];//当前成为最小权值
                k=j;
            }
            j++;
        }
        sum+=min;
        printf("(%d %d) ",adjvex[k],k);//打印当前顶点边中的权值最小值
        lowcost[k]=0;//当前定点权值设为0，表示已经加入树中
        for(j=1;j<G.numvertexes;j++)
        {
            if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
            {//若下标为k顶点各边权值小于此前顶点未被加入树的顶点
                lowcost[j]=G.arc[k][j];//将较小权值存入lowcost
                adjvex[j]=k;//将下标为k的点存入adjvex
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
