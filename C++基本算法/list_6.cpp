/*
��Ŀ��һ�������а�����������ҳ�������ڽ�㣿
step_1����ʼ��sec_ptr��fir_ptrΪL��sec_ptr��һ����fir_ptr����������������ǰ���ٶ�
���������������óɶ��ٱ������ԣ���������ĳһʱ��ָ��ͬһ�ڵ㣬�������д��ڻ���
step_2������ptrָ����ָ��ָ���ͬһ�ڵ㡣��sec_ptrһ��һ���ߣ����߱߼�����������
�ص�ptr��ʱ��nodeCount = ���е�node����
step_3�����³�ʼ��sec_ptr��fir_ptrΪL������fir_ptr�ߣ�ֱ�������һ���ڵ����nodeCount��
����sec_ptrָ����Ԫ��֮�����ͬ����ǰ�ƶ���ֱ������ָ��ͬһ���ڵ㣬�ýڵ���ǻ�����ڡ�
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
	int nodeCount = 1; //����ptr��ָ��Ľڵ� 
	
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
