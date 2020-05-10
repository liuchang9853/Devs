/*
��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö����������������
ǰ���������������Ľ���ж������ظ������֡�
*/
#include <iostream>
using namespace std;

typedef struct BiTNode {
	int data;
	BiTNode *lchild , *rchild;
} BiTNode , *BiTNodePtr;

//������������֤
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

//�������������������������ؽ�������
BiTNodePtr BiTConstruct(BiTNodePtr L , int Pre[] , int In[] , int InLen) {
	//��ʹ�β���arr[]��arrҲ��ָ�����ͣ���������ָ�룬��sizeof(arr)=8��
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

	//�ݹ�
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

	//��֤
	PreOrder(L);
	cout << endl;

	InOrder(L);
	return 0;
}
