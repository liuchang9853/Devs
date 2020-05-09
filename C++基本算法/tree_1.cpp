#include <iostream>
#include <queue> //����ͷ�ļ� 
using namespace std;

typedef struct BiTNode{
	int data;
	BiTNode *lchild , *rchild;
} BiTNode , *BiTNodePtr;

void visit(BiTNodePtr T) {
	cout << T->data << ends;
}

void PreOrder(BiTNodePtr T) { //�������
	if(T!=nullptr) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BiTNodePtr T) { //�������
	if(T!=nullptr) {
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTNodePtr T) { //�������
	if(T!=nullptr) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}

void LevelOrder(BiTNodePtr T){ //��α��� 
	queue<BiTNodePtr> BiTQueue; //��ʼ�����У�queue<ElemType> queueName;
	BiTNodePtr ptr;
	BiTQueue.push(T); //���ڵ���ӣ���ӣ�queueName.push(elem);
	while(!BiTQueue.empty()){ //�ж��Ƿ�Ϊ�գ�queueName.empty();
		ptr = BiTQueue.front(); //���ض����еĵ�һ��Ԫ�أ�queueName.front();
		BiTQueue.pop(); //���ӣ�ɾ����Ԫ����queueName.pop();
		visit(ptr);
		if(ptr->lchild!=nullptr) BiTQueue.push(ptr->lchild);
		if(ptr->rchild!=nullptr) BiTQueue.push(ptr->rchild);
	} 
}
/*
���ض�����Ԫ�صĸ�����queueName.size();
���ض��������һ��Ԫ�أ�queueName.back();
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
