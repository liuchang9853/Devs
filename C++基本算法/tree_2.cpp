/*
题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的
前序遍历和中序遍历的结果中都不含重复的数字。
*/
#include <iostream>
using namespace std;

typedef struct BiTNode {
	int data;
	BiTNode *lchild , *rchild;
} BiTNode , *BiTNodePtr;

//遍历，用于验证
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

//根据先序遍历和中序遍历进行重建二叉树
BiTNodePtr BiTConstruct(BiTNodePtr L , int Pre[] , int In[] , int InLen) {
	//即使形参是arr[]，arr也是指针类型，而非数组指针，即sizeof(arr)=8。
	int i = 0;
	for(; In[i]!=Pre[0]; ++i);
	L = new BiTNode();
	L->data = Pre[0];

	//Pre
	int * PreLeft = new int[i];
	for(int j=0; j<i; ++j) PreLeft[j] = Pre[j+1];

	int * PreRight = new int[InLen-i-1];
	for(int j=0; j<InLen-i-1; ++j) PreRight[j] = Pre[j+1+i];

	//In
	int * InLeft = new int[i];
	for(int j=0; j<i; ++j) InLeft[j] = In[j];

	int * InRight = new int[InLen-i-1];
	for(int j=0; j<InLen-i-1; ++j) InRight[j] = In[j+1+i];

	//递归
	if(i == 0) L->lchild = nullptr;
	else L->lchild = BiTConstruct(L->lchild , PreLeft , InLeft , i);

	if(i == InLen - 1) L->rchild = nullptr;
	else L->rchild = BiTConstruct(L->rchild , PreRight , InRight , InLen-i-1);

	return L;
}

template <class T>
int length(const T & arr) {
	return sizeof(arr)/sizeof(arr[0]);
}

int main() {
	BiTNodePtr L = nullptr;
	int pre [] = {1,2,4,7,3,5,6,8,9};
	int in [] = {4,7,2,1,5,3,8,6,9};
	L = BiTConstruct(L , pre , in , length(in));

	//验证
	PreOrder(L);
	cout << endl;

	InOrder(L);
	return 0;
}
