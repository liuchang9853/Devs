/*
��Ŀ���������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ���ý�㡣
��һ����ͷ����ֱ��ptr->next = deletePtr��Ȼ��ptr->next = deletePtr->next;delete deletePtr;
������
node[0]��ͷ���
����deletePtr->one of &node[1~n-1]����deletePtrָ��ڵ�i����һ���ڵ�j�����ݸ��Ƹ�i��Ȼ��ɾ��j��
����deletePtr->&node[n]�����÷�һ��
*/
#include <iostream>
using namespace std;

typedef struct ListNode {
	int data;
	ListNode *nextPtr;
} LNode , *ListPtr;

//β�巨
void addToTail(ListPtr &L , int data) {
	ListPtr nodePtr = new LNode();
	nodePtr->data = data;
	nodePtr->nextPtr = nullptr;
	ListPtr ptr = L;
	while (ptr->nextPtr != nullptr) ptr = ptr->nextPtr;
	ptr->nextPtr = nodePtr;
}

//��ָ��ɾ��
void removeNode(ListPtr &L , ListPtr &deletePtr) {
	if(deletePtr->nextPtr != nullptr) {
		ListPtr ptr = deletePtr->nextPtr;
		deletePtr->data = ptr->data;
		deletePtr->nextPtr = ptr->nextPtr;
		delete ptr;
	} else {
		ListPtr ptr = L;
		while(ptr->nextPtr->nextPtr != nullptr) {
			ptr = ptr->nextPtr;
		}
		ptr->nextPtr = nullptr;
		delete deletePtr;
	}
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
	
	ListPtr deletePtr = L->nextPtr->nextPtr->nextPtr; //ɾ��17 
	removeNode(L,deletePtr);
	
	deletePtr = L->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr; //ɾ��39
	removeNode(L,deletePtr);

	ListPtr ptr = L;
	while(ptr->nextPtr != nullptr) {
		cout << ptr->nextPtr->data << ends;
		ptr = ptr->nextPtr;
	}

	return 0;
}
