/*
��Ŀ������һ������������һ�������ͷ��㣬��ת�����������ת�������ͷ��㡣
*/
#include <iostream>
using namespace std;

typedef struct ListNode {
	int data;
	ListNode *nextPtr;
} LNode , *ListPtr;

void addToTail(ListPtr &L , int data) { //��û��ͷ��㣬��Ҫ��д
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

	if(!L) { //��LΪ��
		cout << "LΪ�ա�" << endl;
		return;
	}

	ListPtr fir_ptr = L , sec_ptr = L;
	if(!fir_ptr->nextPtr) { //L��һ���ڵ�
		cout << L->data << endl;
		return;
	} else sec_ptr = fir_ptr->nextPtr;

	ListPtr thi_ptr = L;
	if(!sec_ptr->nextPtr) { //L�������ڵ�
		fir_ptr->nextPtr = nullptr;
		sec_ptr->nextPtr = fir_ptr;
		L = sec_ptr;
		cout << L->data << endl;
		return;
	} else thi_ptr = sec_ptr->nextPtr;

	fir_ptr->nextPtr = nullptr; //L��3��3�����ϵĽڵ�
	sec_ptr->nextPtr = fir_ptr;
	while(thi_ptr->nextPtr) {
		fir_ptr = sec_ptr;
		sec_ptr = thi_ptr;
		thi_ptr = thi_ptr->nextPtr; //��ָ������ƶ�

		sec_ptr->nextPtr = fir_ptr;
	}
	sec_ptr->nextPtr = fir_ptr;
	thi_ptr->nextPtr = sec_ptr;
	L=thi_ptr;
	cout << L->data << endl;
}

int main() {
	ListPtr L = nullptr; //����ʱ��Ҫ�����Թ��Ƿ�����ͷ�����ڡ����������͵ÿ���L=nullptr�������
	reverse_list(L);

	addToTail(L,7); //��һ���ڵ�
	reverse_list(L);

	addToTail(L,9); //�������ڵ�
	reverse_list(L);

	addToTail(L,17); //�������ڵ�
	reverse_list(L);

	addToTail(L,69); //�����������ڵ�
	addToTail(L,18);

	reverse_list(L);

	return 0;
}
