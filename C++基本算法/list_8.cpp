/*
题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的。
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
	if(!L) L = nodePtr;
	else {
		ListPtr ptr = L;
		while (ptr->nextPtr != nullptr) ptr = ptr->nextPtr;
		ptr->nextPtr = nodePtr;
	}
}

ListPtr merge_list(ListPtr L_1 , ListPtr L_2) {
	if(L_1 == nullptr) L_1 = L_2;
	if(L_2 == nullptr) L_2 = L_1;
	if(!L_1) return nullptr;
	if(L_1 == L_2) return L_1;

	ListPtr L = nullptr , L_1_ptr = L_1, L_2_ptr = L_2;
	if(L_1_ptr->data <= L_2_ptr->data) L = L_1_ptr;
	else L = L_2_ptr;

	while(true) {
		if(L_1_ptr->data <= L_2_ptr->data) {
			for( ; L_1_ptr->nextPtr != nullptr && L_1_ptr->nextPtr->data <= L_2_ptr->data ; L_1_ptr = L_1_ptr->nextPtr);
			if(!L_1_ptr->nextPtr) {
				L_1_ptr->nextPtr = L_2_ptr;
				return L;
			}
			ListPtr temp_ptr = L_1_ptr->nextPtr;
			L_1_ptr->nextPtr = L_2_ptr;
			L_1_ptr = temp_ptr;
		}

		if(L_2_ptr->data <= L_1_ptr->data) {
			for( ; L_2_ptr->nextPtr != nullptr && L_2_ptr->nextPtr->data <= L_1_ptr->data ; L_2_ptr = L_2_ptr->nextPtr);
			if(!L_2_ptr->nextPtr) {
				L_2_ptr->nextPtr = L_1_ptr;
				return L;
			}
			ListPtr temp_ptr = L_2_ptr->nextPtr;
			L_2_ptr->nextPtr = L_1_ptr;
			L_2_ptr = temp_ptr;
		}
	}
}

int main() {
	ListPtr L_1 = nullptr , L_2 = nullptr;

	addToTail(L_1,7);
	addToTail(L_1,17);
	addToTail(L_1,27);
	addToTail(L_1,37);
	addToTail(L_1,47);

	addToTail(L_2,17);
	addToTail(L_2,20);
	addToTail(L_2,100);

	ListPtr L = merge_list(L_1 , L_2);
	if(L) {
		cout << L->data << ends;
		while(L->nextPtr != nullptr) {
			cout << L->nextPtr->data << ends;
			L = L->nextPtr;
		}
	} else cout << "list is empty.";

	return 0;
}
