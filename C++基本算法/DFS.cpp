#include<iostream>
#define MAX_VERTEX_NUM 20
using namespace std;
//ͼ���� 
typedef struct{ //ͼ���ڽӾ���洢 
	char vex [MAX_VERTEX_NUM]; //�±��0~20����visited[]һһ��Ӧ�����ߵĶ�Ӧͨ����ȵ��±�ʵ�֡� 
	int edge [MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //�費�ɴ���-1���ԽǴ�Ϊ0�� 
	int vexnum , arcnum; //ͼ�Ķ����� �� ����������ͼ��������ͼ����edgenum�� 
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

//�������� 
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
