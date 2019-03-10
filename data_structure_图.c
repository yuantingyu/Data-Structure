//邻接表表示
/*
#include<stdio.h>
#include<stdlib.h>
#define maxvex 10
#include<C:\Users\tingyu\Documents\data structure_2\data_structure_队列.c>
typedef char VertexType;//顶点类型
typedef int Edgetype;//权值类型
int visit[maxvex];
typedef struct EdgeNode//边表
{
    int adjvex;//邻接点域，存储该顶点对应下标
    Edgetype weight;//权值，非网可以不用
    struct EdgeNode *next;//链域，指向下一个邻接点
}EdgeNode;
typedef struct VertexNode//顶点表
{
    VertexType data;//顶点信息
    EdgeNode *firstedge;//边表头指针
}VertexNode,AdjList[maxvex];
typedef struct
{
    AdjList adjList;
    int numVertexes,numEdges;//图中当前顶点数和边数
}GraphAdjlist;
void CreateGraph(GraphAdjlist *G)
{
    int i,j,k;
    EdgeNode *e;
    printf("输入顶点数和边数\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    getchar();
    printf("输入顶点信息\n");
    for(i=0;i<G->numVertexes;i++)//建立顶点表
    {
        scanf("%c",&G->adjList[i].data);//输入顶点信息
        G->adjList[i].firstedge=NULL;//边表置空
    }
    getchar();
    for(k=0;k<G->numEdges;k++)//建立边表
    {
        printf("请输入边（vi,vj）上顶点序号：\n");
        scanf("%d %d",&i,&j);
        e=(EdgeNode *)malloc(sizeof(EdgeNode));//申请空间，形成边表节点
        e->adjvex=j;//邻接序号j
        e->next=G->adjList[i].firstedge;//将e指针指向当前顶点指向的结点
        G->adjList[j].firstedge=e;//当前顶点指针指向e
        e=(EdgeNode *)malloc(sizeof(EdgeNode));//申请空间，形成边表节点
        e->adjvex=i;//邻接序号i
        e->next=G->adjList[j].firstedge;//将e指针指向当前顶点指向的结点
        G->adjList[j].firstedge=e;//当前顶点指针指向e
    }
}
void DFS(GraphAdjlist G,int i)//邻接表深度优先递归算法
{
    EdgeNode *p;
    visit[i]=1;
    printf("%c ",G.adjList[i].data);
    p=G.adjList[i].firstedge;
    while(p)
    {
        if(!visit[p->adjvex])
            DFS(G,p->adjvex);//对未访问邻接结点递归调用
        p=p->next;
    }
}
void DFSTravel(GraphAdjlist G)
{
    int i;
    for(i=0;i<G.numVertexes;i++)
        visit[i]=0;
    for(i=0;i<G.numVertexes;i++)//未访问顶点，调用DFS
        if(!visit[i])
        DFS(G,i);

}
void BFSTravel(GraphAdjlist G)
{
    int i;
    LinkQueue Q;
    EdgeNode *p;
    InitQueue(&Q);//初始化一个辅助队列
    for(i=0;i<G.numVertexes;i++)
        visit[i]=0;
    for(i=0;i<G.numVertexes;i++)
        {
            if(!visit[i])
            {
                visit[i]=1;
                printf("%c ",G.adjList[i].data);
                EnQueue(&Q,i);
                while(!EmptyQueue(Q))
                {
                    DeQueue(&Q,&i);
                    p=G.adjList[i].firstedge;//找到当前顶点边表链表头指针
                    while(p)
                    {
                        if(!visit[p->adjvex])
                        {
                            visit[p->adjvex]=1;
                            printf("%c ",G.adjList[p->adjvex].data);
                            EnQueue(&Q,p->adjvex);//将此顶点入队列
                        }
                        p=p->next;//p指向下一个邻接点
                    }
                }
            }
        }
}
int main()
{
    GraphAdjlist G;
    CreateGraph(&G);
    DFSTravel(G);
    BFSTravel(G);

}
*/
//邻接矩阵表示
#include<stdio.h>
#include<stdlib.h>
#define maxvex 10
#define infinity 65535
#include<C:\Users\tingyu\Documents\data structure_2\data_structure_队列.c>
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
    int i,j,k,w;
    printf("输入顶点数和边数\n");
    scanf("%d%d",&G->numvertexes,&G->numedges);
    getchar();//%c会接受回车字符，所以用它接一下，不然会出错
    printf("输入顶点信息\n");
    for(i=0;i<G->numvertexes;i++)
    {
        scanf("%c",&G->vex[i]);
    }
    getchar();
    for(i=0;i<G->numvertexes;i++)
    for(j=0;j<G->numvertexes;j++)//邻接矩阵初始化
    {
        G->arc[i][j]=infinity;
    }
    for(k=0;k<G->numedges;k++)
    {
        printf("请输入边（vi,vj）上顶点序号及权值：\n");
        scanf("%d%d%d",&i,&j,&w);
        G->arc[i][j]=w;
        G->arc[j][i]=w;
    }
}
void DFS(Mygraph G,int i)//深度优先递归算法
{
    int j;
    visit[i]=1;
    printf("%c ",G.vex[i]);//打印结点
    for(j=0;j<G.numvertexes;j++)
        if(G.arc[i][j]!=infinity&&!visit[j])
            DFS(G,j);//对未访问邻接顶点递归调用
}
void DFSTravel(Mygraph G)
{
    int i;
    for(i=0;i<G.numvertexes;i++)//初始化都设置为未访问过
        visit[i]=0;
    for(i=0;i<G.numvertexes;i++)
        if(!visit[i])//对未访问顶点调用DFS,若是联通图，只会调用一次
        DFS(G,i);
}
void BFSTravel(Mygraph G)
{
    int i,j;
    LinkQueue Q;
    InitQueue(&Q);
    for(i=0;i<G.numvertexes;i++)
        visit[i]=0;
    for(i=0;i<G.numvertexes;i++)
    {
        if(!visit[i])
        {
            printf("%c ",G.vex[i]);
            visit[i]=1;
            EnQueue(&Q,i);
            while(!EmptyQueue(Q))
            {
                DeQueue(&Q,&i);
                for(j=0;j<G.numvertexes;j++)
                    if(G.arc[i][j]!=infinity&&!visit[j])
                        {
                            printf("%c ",G.vex[j]);
                            visit[j]=1;
                            EnQueue(&Q,j);
                        }
            }
        }
    }
}
int main()
{
    Mygraph G;
    Creategraph(&G);
    DFSTravel(G);
    BFSTravel(G);
}
