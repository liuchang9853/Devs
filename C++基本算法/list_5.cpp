/*
��Ŀ������һ����������������е�����k����㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
�����1��ʼ�������������β����ǵ�����1����㡣����һ��������6����㣬
��ͷ��㿪ʼ���ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3�������
ֵΪ4�Ľ�㡣

Ҫע��ĵط��ǣ�
��1��k = 0
��2��len(list) < k
��3��ListPtr->nextPtr = nullptr
*/
#include <iostream>
using namespace std;

typedef struct ListNode {
	int data;
	ListNode *nextPtr;
} LNode , *ListPtr;

void addToTail(ListPtr &L , int data) {
	ListPtr nodePtr = new LNode();
	nodePtr->data = data;
	nodePtr->nextPtr = nullptr;
	ListPtr ptr = L;
	while (ptr->nextPtr != nullptr) ptr = ptr->nextPtr;
	ptr->nextPtr = nodePtr;
}

//���ص�����k��Ԫ��
ListPtr find_k(ListPtr L , int k) {
	if(k == 0) return nullptr;
	
	ListPtr ptr_before = L;
	ListPtr ptr_after = nullptr;
	
	int i = 0;
	for( ; ptr_before->nextPtr != nullptr && i < k ; ptr_before = ptr_before->nextPtr , ++i);
	if(ptr_before->nextPtr == nullptr && i < k) return nullptr;
	
	ptr_after = L->nextPtr;
	for( ; ptr_before->nextPtr != nullptr ; ptr_before = ptr_before->nextPtr , ptr_after = ptr_after->nextPtr);
	return ptr_after;
}

int main() {
	ListPtr L = new LNode();
	L->nextPtr = nullptr;

	addToTail(L,7);
	addToTail(L,9);
	addToTail(L,17);
	addToTail(L,69);
	addToTail(L,18);
	addToTail(L,39);
	
	int k = 7;
	ListPtr ptr = find_k(L , k); //֮���Զ���ptr�Ǳ������ε���find_k()���� 
	if(ptr) cout << find_k(L , k)->data;
	else cout << "error";
	 
	return 0;
}
