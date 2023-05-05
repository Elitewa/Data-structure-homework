#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VEXNUM 9
#define INF 9999   //无穷大
int visited[VEXNUM];
struct Graph{//通用图形定义,用于创建图形的邻接矩阵和邻接表-全局变量
    int vexnum,arcnum,kind;//顶点数、边数、图类型：1234-无向图、有向图、无向网、有向网
    char vexs[VEXNUM+1];   //顶点字符数组
    int arcs[30];          //边起止点下标及权值数组
} graph={8,10,1,"ABCDEFGH",{0,1,0,0,2,0,0,5,0,1,3,0,2,6,0,3,4,0,3,6,0,5,6,0,5,7,0,6,7,0}};
//8个顶点、10条边、无向网、顶点依次为ABCDEFGH
//A-D,A-C,A-F,B-D,C-G,D-E,D-G,F-G,F-H,G-H
struct MGraph_Mat{//图的邻接矩阵存储数据定义
    int vexnum,arcnum;     //顶点数、边数
    char vexs[VEXNUM];     //顶点数组
    int arcs[VEXNUM][VEXNUM];//邻接矩阵
    int kind;              //图类型
};
struct arcnode{//邻接表-边结点
    int adjvex,weight;//邻接边下标、权值
    struct arcnode *nextarc; //下一边表指针
};
struct vexnode{//顶点结点
    char vexdata;     //顶点字符数据
    struct arcnode *firstarc;//第一个边表指针
};
struct MGraph_Adj{//图的邻接表存储数据定义
    int vexnum,arcnum;//顶点数、边数
    struct vexnode vexarr[VEXNUM];//顶点结点数组
    int kind;         //图类型
};
void create_Mat(struct MGraph_Mat *g){      //创建图的邻接矩阵
    int i,j;
    g->vexnum=graph.vexnum;//顶点数
    g->arcnum=graph.arcnum;//边数
    g->kind=graph.kind;    //图类型：1234-无向图、有向图、无向网、有向网	
    for(i=0;i<=g->vexnum-1;i++)
        g->vexs[i]=graph.vexs[i];//逐个赋值顶点字符
    for(i=1;i<=g->vexnum;i++)
	{
        for(j=1;j<=g->vexnum;j++)
		{							//是无向图
                g->arcs[i-1][j-1]=0;  //邻接矩阵全部初始值为0
        }
    }
    for(i=0;i<=g->arcnum-1;i++)
	{								//无向图,一条边处理矩阵两个元素,放1
            g->arcs[graph.arcs[i*3]][graph.arcs[i*3+1]]=1;
            g->arcs[graph.arcs[i*3+1]][graph.arcs[i*3]]=1;//对称点
        
    }
}
void create_Adj(struct MGraph_Adj *g){//根据全局通用图形定义graph，创建图的邻接表
    int i;
    struct arcnode *p=NULL;
    g->vexnum=graph.vexnum;//顶点数
    g->arcnum=graph.arcnum;//边数
    g->kind=graph.kind;//图类型：1234-无向图、有向图、无向网、有向网	
    for(i=0;i<=g->vexnum-1;i++){
        g->vexarr[i].vexdata=graph.vexs[i];//逐个顶点赋值-顶点字符
        g->vexarr[i].firstarc=NULL;//第一条边初始值置空
    }
    for(i=0;i<=g->arcnum-1;i++){//逐条边创建边表结点	
        p=(struct arcnode *)(malloc(sizeof(struct arcnode)));//申请边表空间
        p->adjvex=graph.arcs[i*3+1];//边结点-边下标
        p->weight=graph.arcs[i*3+2];//边结点-权值
        p->nextarc=g->vexarr[graph.arcs[i*3]].firstarc;
        g->vexarr[graph.arcs[i*3]].firstarc=p;//将p结点插入在指定顶点之后-前插
        if(g->kind==1){//若果是无向图，需再创建一个结点		
            p=(struct arcnode *)(malloc(sizeof(struct arcnode)));
            p->adjvex=graph.arcs[i*3];//边结点-边下标
            p->nextarc=g->vexarr[graph.arcs[i*3+1]].firstarc;
            g->vexarr[graph.arcs[i*3+1]].firstarc=p;//将p结点插入在指定顶点之后-前插
        }
    }
}
void print_Mat(struct MGraph_Mat g)
{									//显示邻接矩阵
    int i,j;
    printf("  ");
    for(i=0;i<=g.vexnum-1;i++)
        printf("%3c",g.vexs[i]);//显示第一行,各节点字符
    printf("\n");
    for(i=0;i<=g.vexnum-1;i++)
	{								//各行	
        printf("  %c  ",g.vexs[i]);//先显示字符
        for(j=0;j<=g.vexnum-1;j++)
		{									//各列		
            if(g.kind==1||g.kind==2)//图
                printf("%d  ",g.arcs[i][j]);//显示1、0
		}
        printf("\n");
    }
}
void print_Adj(struct MGraph_Adj g){//显示邻接表
    int i;
    struct arcnode *p=NULL;
    printf("\n\n");
    for(i=0;i<=g.vexnum-1;i++){//处理各顶点	
        printf("  %d %c",i,g.vexarr[i].vexdata);//下标、顶点字符
        p=g.vexarr[i].firstarc;//p指向第一个边表结点
        while(p){//逐个边表显示		
            if(g.kind==1||g.kind==2)//如果是图只显示边序号
                printf("->%d",p->adjvex);
            p=p->nextarc;//下一边表
        }
        printf("\n");
    }
}
void BFS_Mat(struct MGraph_Mat g,int v) //广度优先递归体
{
	int Lq[VEXNUM],i,j,f=0,r=0;
	printf("%c",g.vexs[v]);
	visited[v]=1;
	Lq[r++]=v;
	while(r!=f)
	{
		i=Lq[f++];
		for(j=0;j<=g.vexnum-1;j++)
		{
			if(g.arcs[i][j]!=0&&g.arcs[i][j]!=INF&&visited[j]==0)
			{
				printf(" %c ",g.vexs[j]);
				visited[j]=1;
				Lq[r++]=j;
			}
		}
	}
}
void BFSTraverse_Mat(struct MGraph_Mat g,int v) //广度
{
	int i;
	memset(visited,0,sizeof(visited));
	printf("\n邻接矩阵广度优先搜索序列");
	for(i=v;i<g.vexnum;i++)
		if(visited[i%g.vexnum]==0)
			BFS_Mat(g,i%g.vexnum);
}
void DFS_Mat(struct MGraph_Mat g,int v)
{
	int i;
	printf(" %c ",g.vexs[v]);
	visited[v]=1;
	for(i=0;i<=g.vexnum-1;i++)
	{
		if(g.arcs[v][i]!=0&&g.arcs[v][i]!=INF&&visited[i]==0)
			DFS_Mat(g,i);
	}
}
void DFSTraverse_Mat(struct MGraph_Mat g,int v)
{
	int i;
	memset(visited,0,sizeof(visited));
	printf("\n邻接矩阵深度优先搜索序列");
	for(i=v;i<g.vexnum+v-1;i++)
	{
		if(visited[i%g.vexnum]==0)
			DFS_Mat(g,i%g.vexnum);
	}
}

int main(){
    struct MGraph_Mat g;
    struct MGraph_Adj g1;
    create_Mat(&g);
    create_Adj(&g1);
    print_Mat(g);
	print_Adj(g1);
    DFSTraverse_Mat(g,3);
	BFSTraverse_Mat(g,3);
    
}
