//�ڽӱ��ʾ
/*
#include<stdio.h>
#include<stdlib.h>
#define maxvex 10
#include<C:\Users\tingyu\Documents\data structure_2\data_structure_����.c>
typedef char VertexType;//��������
typedef int Edgetype;//Ȩֵ����
int visit[maxvex];
typedef struct EdgeNode//�߱�
{
    int adjvex;//�ڽӵ��򣬴洢�ö����Ӧ�±�
    Edgetype weight;//Ȩֵ���������Բ���
    struct EdgeNode *next;//����ָ����һ���ڽӵ�
}EdgeNode;
typedef struct VertexNode//�����
{
    VertexType data;//������Ϣ
    EdgeNode *firstedge;//�߱�ͷָ��
}VertexNode,AdjList[maxvex];
typedef struct
{
    AdjList adjList;
    int numVertexes,numEdges;//ͼ�е�ǰ�������ͱ���
}GraphAdjlist;
void CreateGraph(GraphAdjlist *G)
{
    int i,j,k;
    EdgeNode *e;
    printf("���붥�����ͱ���\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    getchar();
    printf("���붥����Ϣ\n");
    for(i=0;i<G->numVertexes;i++)//���������
    {
        scanf("%c",&G->adjList[i].data);//���붥����Ϣ
        G->adjList[i].firstedge=NULL;//�߱��ÿ�
    }
    getchar();
    for(k=0;k<G->numEdges;k++)//�����߱�
    {
        printf("������ߣ�vi,vj���϶�����ţ�\n");
        scanf("%d %d",&i,&j);
        e=(EdgeNode *)malloc(sizeof(EdgeNode));//����ռ䣬�γɱ߱�ڵ�
        e->adjvex=j;//�ڽ����j
        e->next=G->adjList[i].firstedge;//��eָ��ָ��ǰ����ָ��Ľ��
        G->adjList[j].firstedge=e;//��ǰ����ָ��ָ��e
        e=(EdgeNode *)malloc(sizeof(EdgeNode));//����ռ䣬�γɱ߱�ڵ�
        e->adjvex=i;//�ڽ����i
        e->next=G->adjList[j].firstedge;//��eָ��ָ��ǰ����ָ��Ľ��
        G->adjList[j].firstedge=e;//��ǰ����ָ��ָ��e
    }
}
void DFS(GraphAdjlist G,int i)//�ڽӱ�������ȵݹ��㷨
{
    EdgeNode *p;
    visit[i]=1;
    printf("%c ",G.adjList[i].data);
    p=G.adjList[i].firstedge;
    while(p)
    {
        if(!visit[p->adjvex])
            DFS(G,p->adjvex);//��δ�����ڽӽ��ݹ����
        p=p->next;
    }
}
void DFSTravel(GraphAdjlist G)
{
    int i;
    for(i=0;i<G.numVertexes;i++)
        visit[i]=0;
    for(i=0;i<G.numVertexes;i++)//δ���ʶ��㣬����DFS
        if(!visit[i])
        DFS(G,i);

}
void BFSTravel(GraphAdjlist G)
{
    int i;
    LinkQueue Q;
    EdgeNode *p;
    InitQueue(&Q);//��ʼ��һ����������
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
                    p=G.adjList[i].firstedge;//�ҵ���ǰ����߱�����ͷָ��
                    while(p)
                    {
                        if(!visit[p->adjvex])
                        {
                            visit[p->adjvex]=1;
                            printf("%c ",G.adjList[p->adjvex].data);
                            EnQueue(&Q,p->adjvex);//���˶��������
                        }
                        p=p->next;//pָ����һ���ڽӵ�
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
//�ڽӾ����ʾ
#include<stdio.h>
#include<stdlib.h>
#define maxvex 10
#define infinity 65535
#include<C:\Users\tingyu\Documents\data structure_2\data_structure_����.c>
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
    int i,j,k,w;
    printf("���붥�����ͱ���\n");
    scanf("%d%d",&G->numvertexes,&G->numedges);
    getchar();//%c����ܻس��ַ�������������һ�£���Ȼ�����
    printf("���붥����Ϣ\n");
    for(i=0;i<G->numvertexes;i++)
    {
        scanf("%c",&G->vex[i]);
    }
    getchar();
    for(i=0;i<G->numvertexes;i++)
    for(j=0;j<G->numvertexes;j++)//�ڽӾ����ʼ��
    {
        G->arc[i][j]=infinity;
    }
    for(k=0;k<G->numedges;k++)
    {
        printf("������ߣ�vi,vj���϶�����ż�Ȩֵ��\n");
        scanf("%d%d%d",&i,&j,&w);
        G->arc[i][j]=w;
        G->arc[j][i]=w;
    }
}
void DFS(Mygraph G,int i)//������ȵݹ��㷨
{
    int j;
    visit[i]=1;
    printf("%c ",G.vex[i]);//��ӡ���
    for(j=0;j<G.numvertexes;j++)
        if(G.arc[i][j]!=infinity&&!visit[j])
            DFS(G,j);//��δ�����ڽӶ���ݹ����
}
void DFSTravel(Mygraph G)
{
    int i;
    for(i=0;i<G.numvertexes;i++)//��ʼ��������Ϊδ���ʹ�
        visit[i]=0;
    for(i=0;i<G.numvertexes;i++)
        if(!visit[i])//��δ���ʶ������DFS,������ͨͼ��ֻ�����һ��
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
