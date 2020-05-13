#include <iostream>
#include <queue>
#define MAX_VERTEX_NUM 20
using namespace std;

//图定义
typedef struct {
	char vex [MAX_VERTEX_NUM];
	int edge [MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum , arcnum;
} Graph , *GraphPtr;

//BFS
bool visited[MAX_VERTEX_NUM];
void visit(GraphPtr G , int v) {
	cout << G->vex[v] << ends;
}
int FirstNeighbor(GraphPtr G , int v) {
	int w = 0;
	for(; w < G->vexnum && G->edge[v][w] <= 0 ; ++w);
	if(w == G->vexnum) return -1;
	else return w;
}
int NextNeighbor(GraphPtr G , int v , int w) {
	for(++w ; w < G->vexnum && G->edge[v][w] <= 0 ; ++w);
	if(w == G->vexnum) return -1;
	else return w;
}
void BFS(GraphPtr G , int v , queue<int> &Q) {
	visit(G , v);
	visited[v] = true;
	Q.push(v);
	while(!Q.empty()) {
		int head = Q.front();
		Q.pop();
		for(int w = FirstNeighbor(G , head) ; w > 0 ; w = NextNeighbor(G , head , w))
			if(!visited[w]) {
				visit(G , w);
				visited[w] = true;
				Q.push(w);
			}
	}
}

//启动函数
void BFSTraverse(GraphPtr G) {
	for(int i = 0 ; i < G->vexnum ; ++i) visited[i] = false;

	queue<int> Q;
	for(int i = 0 ; i < G->vexnum ; ++i)
		if(!visited[i])
			BFS(G , i , Q);
}

int main() {
	GraphPtr G = new Graph();
	G->vexnum = 4;
	G->arcnum = 4;
	for(int i = 0 ; i < G->vexnum ; ++i) G->vex[i] = char(65 + i);
	
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
	
	BFSTraverse(G);
	
	return 0;
}
