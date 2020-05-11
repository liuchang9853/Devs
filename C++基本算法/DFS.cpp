#include<iostream>
#define MAX_VERTEX_NUM 20
using namespace std;
//图定义 
typedef struct{ //图的邻接矩阵存储 
	char vex [MAX_VERTEX_NUM]; //下标从0~20，与visited[]一一对应；二者的对应通过相等的下标实现。 
	int edge [MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //设不可达是-1，对角处为0。 
	int vexnum , arcnum; //图的定点数 和 弧数（有向图）；无向图则是edgenum。 
} Graph , *GraphPtr;

//DFS
bool visited[MAX_VERTEX_NUM];
void visit(GraphPtr G , int v){
	cout << G->vex[v] << ends;
}
int FirstNeighbor(GraphPtr G , int v){
	int w = 0;
	for(; w < G->vexnum && G->edge[v][w] <= 0 ; ++w);
	if(w == G->vexnum) return -1;
	else return w; 
}
int NextNeighbor(GraphPtr G , int v , int w){
	for(++w ; w < G->vexnum && G->edge[v][w] <= 0 ; ++w);
	if(w == G->vexnum) return -1;
	else return w; 
}
void DFS(GraphPtr G , int v) {
	visit(G , v);
	visited[v] = true;
	for(int w = FirstNeighbor(G , v); w > 0; w = NextNeighbor(G , v , w))
		if(!visited[w]) DFS(G , w);
}

//启动函数 
void DFSTraverse(GraphPtr G) {
	for(int v = 0; v < G->vexnum; ++v)
		visited[v] = false;
	for(int v = 0; v < G->vexnum; ++v)
		if(!visited[v]) DFS(G , v);
}

int main() {
	GraphPtr G = new Graph();
	G->vexnum = 4;
	G->arcnum = 4;
	for(int i = 0 ; i < G->vexnum ; ++i) G->vex[i] = char(65 + i);
	
	//G_1
	G->edge[0][0] = 0;
	G->edge[0][1] = 3;
	G->edge[0][2] = -1;
	G->edge[0][3] = 6;
	
	G->edge[1][0] = -1;
	G->edge[1][1] = 0;
	G->edge[1][2] = -1;
	G->edge[1][3] = 5;
	
	G->edge[2][0] = -1;
	G->edge[2][1] = -1;
	G->edge[2][2] = 0;
	G->edge[2][3] = -1;
	
	G->edge[3][0] = 2;
	G->edge[3][1] = -1;
	G->edge[3][2] = -1;
	G->edge[3][3] = 0;
	
	DFSTraverse(G);
	
	cout << endl;
	 
	//G_2
	G->edge[0][0] = 0;
	G->edge[0][1] = 3;
	G->edge[0][2] = 6;
	G->edge[0][3] = -1;
	
	G->edge[1][0] = -1;
	G->edge[1][1] = 0;
	G->edge[1][2] = -1;
	G->edge[1][3] = 5;
	
	G->edge[2][0] = -1;
	G->edge[2][1] = -1;
	G->edge[2][2] = 0;
	G->edge[2][3] = -1;
	
	G->edge[3][0] = -1;
	G->edge[3][1] = -1;
	G->edge[3][2] = -1;
	G->edge[3][3] = 0;
	
	DFSTraverse(G);

	return 0;
}
