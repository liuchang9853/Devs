/*
题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
（1）法一：中序遍历二叉树。代码实现简单，但因为要操作1~m个节点，时间开销大。
（2）法二：利用父指针条件。
a.rchild!=nullptr的节点，其下一节点是右子树的最左节点。
b.rchild=nullptr的节点，其下一节点是直系父辈节点中的a节点。要求该节点的一部分
直系父辈属于a的左孩子，且a是该部分的最小父节点。
*/
#include <iostream>
using namespace std;

typedef struct BiTNode {
	char data;
	BiTNode *lchild , *rchild , *father;
} BiTNode , *BiTNodePtr;

//根据先序、中序构建二叉树，作为nextNode的输入。验证
BiTNodePtr BiTConstruct(BiTNodePtr L , char Pre[] , char In[] , int InLen) {
	int i = 0;
	for(; In[i]!=Pre[0]; ++i);
	L = new BiTNode();
	L->data = Pre[0];

	char * PreLeft = new char[i];
	for(int j=0; j<i; ++j) PreLeft[j] = Pre[j+1];

	char * PreRight = new char[InLen-i-1];
	for(int j=0; j<InLen-i-1; ++j) PreRight[j] = Pre[j+1+i];

	char * InLeft = new char[i];
	for(int j=0; j<i; ++j) InLeft[j] = In[j];

	char * InRight = new char[InLen-i-1];
	for(int j=0; j<InLen-i-1; ++j) InRight[j] = In[j+1+i];

	if(i == 0) L->lchild = nullptr;
	else {
		L->lchild = BiTConstruct(L->lchild , PreLeft , InLeft , i);
		L->lchild->father = L;
	}

	if(i == InLen - 1) L->rchild = nullptr;
	else {
		L->rchild = BiTConstruct(L->rchild , PreRight , InRight , InLen-i-1);
		L->rchild->father = L;
	}
	
	return L;
}


//下一节点 
void nextNode(BiTNodePtr L , BiTNodePtr ptr) {
	if(ptr->rchild!=nullptr) {
		BiTNodePtr i = ptr->rchild;
		for(; i->lchild != nullptr; i = i->lchild);
		cout << i->data << endl;
	} else {
		BiTNodePtr i = ptr;
		BiTNodePtr j = ptr->father;
		while(j->lchild != i) {
			i=j;
			j=i->father;
		}
		cout << j->data << endl;
	}
}

template <class T>
int length(const T & arr) {
	return sizeof(arr)/sizeof(arr[0]);
}

int main() {
	BiTNodePtr L = nullptr;
	char pre [] = {'a','b','d','e','h','i','c','f','g'};
	char in [] = {'d','b','h','e','i','a','f','c','g'};
	L = BiTConstruct(L , pre , in , length(in));
	L->father = nullptr;
	
	nextNode(L , L->lchild->lchild); //'d'的下一个 
	nextNode(L , L->lchild->rchild->lchild); //'h'的下一个 
	nextNode(L , L->lchild); //'b'的下一个 
	nextNode(L , L->lchild->rchild->rchild); //'i'的下一个 
	return 0;
}
