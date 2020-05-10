/*
��Ŀ������һ�ö����������е�һ����㣬����ҳ��������˳�����һ����㣿
���еĽ������������ֱ�ָ�������ӽ���ָ�����⣬����һ��ָ�򸸽���ָ�롣
��1����һ���������������������ʵ�ּ򵥣�����ΪҪ����1~m���ڵ㣬ʱ�俪����
��2�����������ø�ָ��������
a.rchild!=nullptr�Ľڵ㣬����һ�ڵ���������������ڵ㡣
b.rchild=nullptr�Ľڵ㣬����һ�ڵ���ֱϵ�����ڵ��е�a�ڵ㡣Ҫ��ýڵ��һ����
ֱϵ��������a�����ӣ���a�Ǹò��ֵ���С���ڵ㡣
*/
#include <iostream>
using namespace std;

typedef struct BiTNode {
	char data;
	BiTNode *lchild , *rchild , *father;
} BiTNode , *BiTNodePtr;

//�����������򹹽�����������ΪnextNode�����롣��֤
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


//��һ�ڵ� 
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
	
	nextNode(L , L->lchild->lchild); //'d'����һ�� 
	nextNode(L , L->lchild->rchild->lchild); //'h'����һ�� 
	nextNode(L , L->lchild); //'b'����һ�� 
	nextNode(L , L->lchild->rchild->rchild); //'i'����һ�� 
	return 0;
}
