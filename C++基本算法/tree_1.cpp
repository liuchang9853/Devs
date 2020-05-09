#include <iostream>
#include <queue> //队列头文件 
using namespace std;

typedef struct BiTNode{
	int data;
	BiTNode *lchild , *rchild;
} BiTNode , *BiTNodePtr;

void visit(BiTNodePtr T) {
	cout << T->data << ends;
}

void PreOrder(BiTNodePtr T) { //先序遍历
	if(T!=nullptr) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BiTNodePtr T) { //中序遍历
	if(T!=nullptr) {
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTNodePtr T) { //后序遍历
	if(T!=nullptr) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}

void LevelOrder(BiTNodePtr T){ //层次遍历 
	queue<BiTNodePtr> BiTQueue; //初始化队列：queue<ElemType> queueName;
	BiTNodePtr ptr;
	BiTQueue.push(T); //根节点入队；入队：queueName.push(elem);
	while(!BiTQueue.empty()){ //判断是否为空：queueName.empty();
		ptr = BiTQueue.front(); //返回队列中的第一个元素：queueName.front();
		BiTQueue.pop(); //出队（删除首元）：queueName.pop();
		visit(ptr);
		if(ptr->lchild!=nullptr) BiTQueue.push(ptr->lchild);
		if(ptr->rchild!=nullptr) BiTQueue.push(ptr->rchild);
	} 
}
/*
返回队列中元素的个数：queueName.size();
返回队列中最后一个元素：queueName.back();
*/

int main() {
	BiTNodePtr tree = new BiTNode();
	tree->data = 2;
	tree->lchild = new BiTNode();
	tree->rchild = new BiTNode();
	
	tree->lchild->data = 1;
	tree->lchild->lchild = nullptr;
	tree->lchild->rchild = nullptr;
	
	tree->rchild->data = 3;
	tree->rchild->lchild = nullptr;
	tree->rchild->rchild = nullptr;
	
	PreOrder(tree);
	cout << endl;
	
	InOrder(tree);
	cout << endl;
	
	PostOrder(tree);
	cout << endl;
	
	LevelOrder(tree);
	
	return 0;
}
