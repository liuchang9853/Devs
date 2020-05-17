/*
题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。
解法：求镜像，就是将一个事物逐层反转。
*/
#include <iostream>
#include <queue>
using namespace std;

typedef struct BiTNode{
	int data;
	BiTNode *lchild , *rchild;
} BiTNode , *BiTNodePtr;

//层次遍历，用于测试 
void visit(BiTNodePtr T) {
	cout << T->data << ends;
}

void LevelOrder(BiTNodePtr T){
	queue<BiTNodePtr> BiTQueue;
	BiTNodePtr ptr;
	BiTQueue.push(T);
	while(!BiTQueue.empty()){
		ptr = BiTQueue.front();
		BiTQueue.pop();
		visit(ptr);
		if(ptr->lchild!=nullptr) BiTQueue.push(ptr->lchild);
		if(ptr->rchild!=nullptr) BiTQueue.push(ptr->rchild);
	} 
}

//构建函数
void create_tree(BiTNodePtr ptr , int data , BiTNode * lchild , BiTNode * rchild) {
	ptr->data = data;
	ptr->lchild = lchild;
	ptr->rchild = rchild;
}

//求镜像 
void mirror_tree(BiTNodePtr T){
	if(T) {
		if(T->lchild || T->rchild){
			BiTNodePtr ptr = T->lchild;
			T->lchild = T->rchild;
			T->rchild = ptr;
		}
		mirror_tree(T->lchild);
		mirror_tree(T->rchild);
	}
}

int main(){
	BiTNodePtr T = new BiTNode[7]();
	create_tree(&T[0] , 8 , &T[1] , &T[2]);
	create_tree(&T[1] , 6 , &T[3] , &T[4]);
	create_tree(&T[2] , 10 , &T[5] , &T[6]);
	create_tree(&T[3] , 5 , nullptr , nullptr);
	create_tree(&T[4] , 7 , nullptr , nullptr);
	create_tree(&T[5] , 9 , nullptr , nullptr);
	create_tree(&T[6] , 11 , nullptr , nullptr);
	
	LevelOrder(T);
	cout << endl;
	
	mirror_tree(T);
	LevelOrder(T);
	
	return 0;
} 
