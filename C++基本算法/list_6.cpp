/*
题目：一个链表中包含环，如何找出环的入口结点？
step_1：初始化sec_ptr和fir_ptr为L，sec_ptr走一步，fir_ptr走两步，即后者是前者速度
的两倍（这里设置成多少倍都可以）。若二者某一时刻指向同一节点，则链表中存在环。
step_2：设置ptr指向两指针指向的同一节点。让sec_ptr一步一步走，边走边计数，当重新
回到ptr处时，nodeCount = 环中的node数。
step_3：重新初始化sec_ptr和fir_ptr为L，先让fir_ptr走，直到它与第一个节点相差nodeCount，
再让sec_ptr指向首元，之后二者同步向前移动。直到二者指向同一个节点，该节点便是环的入口。
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

ListPtr ring_entrance(ListPtr &L) {
	//step_1 
	ListPtr fir_ptr = L , sec_ptr = L;
	while(fir_ptr != sec_ptr || fir_ptr == L) {
		if(fir_ptr->nextPtr && fir_ptr->nextPtr->nextPtr) fir_ptr = fir_ptr->nextPtr->nextPtr;
		else return nullptr;
		if(sec_ptr->nextPtr) sec_ptr = sec_ptr->nextPtr;
		else return nullptr;
	}
	
	//step_2
	ListPtr ptr = sec_ptr;
	int nodeCount = 1; //代表ptr所指向的节点 
	
	sec_ptr = sec_ptr->nextPtr;
	while(sec_ptr != ptr){
		++nodeCount;
		sec_ptr = sec_ptr->nextPtr;
	}
	
	//step_3
	fir_ptr = L;
	sec_ptr = L;
	for( ; nodeCount-- >= 0 ; fir_ptr = fir_ptr->nextPtr);
	sec_ptr = sec_ptr->nextPtr;
	while(fir_ptr != sec_ptr){
		fir_ptr = fir_ptr->nextPtr;
		sec_ptr = sec_ptr->nextPtr;
	}
	
	return sec_ptr;
}

int main() {
	ListPtr L = new LNode();
	L->nextPtr = nullptr;
	
	addToTail(L,7);
	addToTail(L,8);
	addToTail(L,17);
	addToTail(L,6);
	addToTail(L,9); //entrance
	addToTail(L,23);
	addToTail(L,14);
	addToTail(L,65);
	
	L->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr = L->nextPtr->nextPtr->nextPtr->nextPtr->nextPtr;
	
	cout << ring_entrance(L)->data;
	
	return 0;
}
