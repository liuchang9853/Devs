/*
题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点。
法一：从头遍历直到ptr->next = deletePtr，然后ptr->next = deletePtr->next;delete deletePtr;
法二：
node[0]是头结点
对于deletePtr->one of &node[1~n-1]，将deletePtr指向节点i的下一个节点j的内容复制给i，然后删除j。
对于deletePtr->&node[n]，采用法一。
*/
#include <iostream>
using namespace std;

typedef struct ListNode {
	int data;
	ListNode *nextPtr;
} LNode , *ListPtr;

//尾插法
void addToTail(ListPtr &L , int data) {
	ListPtr nodePtr = new LNode();
	nodePtr->data = data;
	nodePtr->nextPtr = nullptr;
	ListPtr ptr = L;
	while (ptr->nextPtr != nullptr) ptr = ptr->nextPtr;
	ptr->nextPtr = nodePtr;
}

//按指针删除
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
	
	ListPtr deletePtr = L->nextPtr->nextPtr->nextPtr; //删除17 
	removeNode(L,deletePtr);
	
	deletePtr = L->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr; //删除39
	removeNode(L,deletePtr);

	ListPtr ptr = L;
	while(ptr->nextPtr != nullptr) {
		cout << ptr->nextPtr->data << ends;
		ptr = ptr->nextPtr;
	}

	return 0;
}
