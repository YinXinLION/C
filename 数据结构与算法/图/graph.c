/*************************************************************************
	> File Name: 1.c
	> Author:YinXin 
	> Mail:yinxin19950816@gmail.com 
	> Created Time: 2015年12月06日 星期日 17时03分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VERTEX_NUM 20
//#define enum{DG ,DN ,UDG ,UDN}GraphKind;//有向图,有向网,无向图,无向网
#define True 1
#define False 0
typedef struct ArcNode
{
    int adjvex;//临接点,存储该定点对应的下标
    struct ArcNode *nextarc;//存储与表头节点相连的其他节点的指针
    int info_weight;//权值
}ArcNode;

typedef struct VertexNode
{
    char data;//存储定点
    ArcNode *firstarc;//边表头指针,指向链表的指针
}VertexNode;

typedef struct 
{
    VertexNode vertex[MAX_VERTEX_NUM];//个数
//    GraphKind kind;//无向图还是...
    int Num_Nodes ,Num_Edges;//总定点数和总边数
}AdjList;

int visited[MAX_VERTEX_NUM] = {0};

ArcNode *create_edge_node();
void CreateGraph_UDG(AdjList *G);
void DepthFirstSearch(AdjList g,int v0);
void DfsTravel(AdjList G);
void PrintfGraphAL(AdjList *G);
void Create_Choose_Graph(AdjList *G);
void CreateGraph_DG(AdjList *G);


int main(void)
{
    AdjList graph;
    Create_Choose_Graph(&graph);
}
void Create_Choose_Graph(AdjList *G)
{
    int choose ,c;
    printf("请选择:\n1.有向图 2.有向网 3.无向图 4.无向网\n选择(1-4):");
    scanf("%d",&choose);
    do{
        c = fgetc(stdin);
    }while(c != '\n' && c != EOF);

    switch(choose)
    {
        case 1:
        CreateGraph_DG(G);
        PrintfGraphAL(G);
        DfsTravel(*G);
        break;
        case 2:break;
        case 3:
        CreateGraph_UDG(G);
        PrintfGraphAL(G);
        DfsTravel(*G);
        break;
        case 4:break;
    }
}
void CreateGraph_UDG(AdjList *G) //无向图
{
    int i ,j ,k ,c;
    ArcNode *e ,*p;
    printf("输入顶点数和边数:\n");
    scanf("%d %d",&(G -> Num_Nodes) ,&(G -> Num_Edges));//输入顶点数,边数
    do{
        c = fgetc(stdin);          
    }while (c != '\n' && c != EOF);

    for(i = 1; i <= G -> Num_Nodes; i++)
    {
        printf("number %d is :",i);
        scanf("%c",&(G -> vertex[i].data)); //输入节点信息
        printf("\n");
        do{
            c = fgetc(stdin);         
        }while (c != '\n' && c != EOF);
        G -> vertex[i].firstarc = NULL; //置空
    }

    for(k = 0; k < G -> Num_Edges; k++) //建立边
    {
        printf("输入边(vi,vj)上的顶点序号:\n");
        scanf("%d,%d",&i ,&j);
        do{
            c = fgetc(stdin);         
        }while (c != '\n' && c != EOF);
        e = create_edge_node();
        e -> adjvex = j;
        e -> nextarc = G->vertex[i].firstarc;//头插
        G->vertex[i].firstarc = e;

        e = create_edge_node();
        e -> adjvex = i;
        e -> nextarc = G -> vertex[j].firstarc;
        G -> vertex[j].firstarc = e;
    }
}

void CreateGraph_DG(AdjList *G) //有向图
{
    int i ,j ,k ,c;
    ArcNode *e ,*p;
    printf("输入顶点数和边数:\n");
    scanf("%d %d",&(G -> Num_Nodes) ,&(G -> Num_Edges));//输入顶点数,边数
    do{
        c = fgetc(stdin);          
    }while (c != '\n' && c != EOF);

    for(i = 1; i <= G -> Num_Nodes; i++)
    {
        printf("number %d is :",i);
        scanf("%c",&(G -> vertex[i].data)); //输入节点信息
        printf("\n");
        do{
            c = fgetc(stdin);         
        }while (c != '\n' && c != EOF);
        G -> vertex[i].firstarc = NULL; //置空
    }
    for(k = 0; k < G -> Num_Edges; k++) //建立边
    {
        printf("输入边(vi,vj)上的顶点序号:vi -> vj\n");
        scanf("%d,%d",&i ,&j);
        do{
            c = fgetc(stdin);         
        }while (c != '\n' && c != EOF);
        e = create_edge_node();
        e -> adjvex = j;
        e -> nextarc = G->vertex[i].firstarc;//头插
        G->vertex[i].firstarc = e;
    }
}

ArcNode *create_edge_node()
{
    ArcNode *head;
    head = (ArcNode *)malloc(sizeof(ArcNode));
    return head;
}

void DepthFirstSearch(AdjList g,int v0)
{
    ArcNode *p;
    printf("visit vertex:%c\n",g.vertex[v0].data);
    visited[v0] = True;
    p = g.vertex[v0].firstarc;
    while(p != NULL)
    {
        if(!visited[p -> adjvex])
        DepthFirstSearch(g ,p -> adjvex);
        p = p -> nextarc;
    }
}

void DfsTravel(AdjList g)
{
    int i;
    for(i = 0; i < (g.Num_Nodes) ;i++)
    visited[i] = False;

    for(i = 1; i <= (g.Num_Nodes) ;i++)
    if(!visited[i])
    DepthFirstSearch(g ,i);
}

void PrintfGraphAL(AdjList *G)
{
    int i;
    for ( i = 1; i <= G->Num_Nodes; i++)
    {
        printf("vertex:%c", G -> vertex[i].data);
        ArcNode *p = G->vertex[i].firstarc;
        while (p)
        {
            printf("→:%d", p->adjvex);
            p = p->nextarc;                    
        }
        printf("\n");     
    }

}
