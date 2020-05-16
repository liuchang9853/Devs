/*
题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
*/
#include <iostream>
using namespace std;

typedef struct ListNode {
	int data;
	ListNode *nextPtr;
} LNode , *ListPtr;

void addToTail(ListPtr &L , int data) { //因没有头结点，需要重写
	ListPtr nodePtr = new LNode();
	nodePtr->data = data;
	nodePtr->nextPtr = nullptr;
	if(!L) L = nodePtr;
	else {
		ListPtr ptr = L;
		while (ptr->nextPtr != nullptr) ptr = ptr->nextPtr;
		ptr->nextPtr = nodePtr;
	}
}

void reverse_list(ListPtr &L) {

	if(!L) { //若L为空
		cout << "L为空。" << endl;
		return;
	}

	ListPtr fir_ptr = L , sec_ptr = L;
	if(!fir_ptr->nextPtr) { //L含一个节点
		cout << L->data << endl;
		return;
	} else sec_ptr = fir_ptr->nextPtr;

	ListPtr thi_ptr = L;
	if(!sec_ptr->nextPtr) { //L含两个节点
		fir_ptr->nextPtr = nullptr;
		sec_ptr->nextPtr = fir_ptr;
		L = sec_ptr;
		cout << L->data << endl;
		return;
	} else thi_ptr = sec_ptr->nextPtr;

	fir_ptr->nextPtr = nullptr; //L含3及3个以上的节点
	sec_ptr->nextPtr = fir_ptr;
	while(thi_ptr->nextPtr) {
		fir_ptr = sec_ptr;
		sec_ptr = thi_ptr;
		thi_ptr = thi_ptr->nextPtr; //三指针向后移动

		sec_ptr->nextPtr = fir_ptr;
	}
	sec_ptr->nextPtr = fir_ptr;
	thi_ptr->nextPtr = sec_ptr;
	L=thi_ptr;
	cout << L->data << endl;
}

int main() {
	ListPtr L = nullptr; //面试时，要问面试官是否允许头结点存在。若不允许，就得考虑L=nullptr的情况。
	reverse_list(L);

	addToTail(L,7); //含一个节点
	reverse_list(L);

	addToTail(L,9); //含两个节点
	reverse_list(L);

	addToTail(L,17); //含三个节点
	reverse_list(L);

	addToTail(L,69); //含大于三个节点
	addToTail(L,18);

	reverse_list(L);

	return 0;
}
