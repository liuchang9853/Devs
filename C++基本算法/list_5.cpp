/*
题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
值为4的结点。

要注意的地方是：
（1）k = 0
（2）len(list) < k
（3）ListPtr->nextPtr = nullptr
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

//返回倒数第k个元素
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
	ListPtr ptr = find_k(L , k); //之所以定义ptr是避免两次调用find_k()函数 
	if(ptr) cout << find_k(L , k)->data;
	else cout << "error";
	 
	return 0;
}
