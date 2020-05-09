/*
��Ŀ������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��
���ǲ����������Ǵ�ͷ��β������Ҫ���β��ͷ����������뵽����
����һ��ջ��ɨ��list����ÿһԪ�ط���stack�У��������Ƚ������
�ص㣬ʵ��Ŀ�ꡣ
*/
#include <iostream>
#include <stack> //ջͷ�ļ� 
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

void reverseList(ListPtr &L) {
	ListPtr ptr = L;
	stack<int> ListStack; //ջ���壺stack<ElemType> stackName;

	while(ptr->nextPtr != nullptr) {
		ListStack.push(ptr->nextPtr->data); //��ջ��stackName.push(elem); 
		ptr = ptr->nextPtr;
	}

	while (!ListStack.empty()) { //�ж�ջ�Ƿ�Ϊ�գ�stackName.empty();
		cout << ListStack.top() << " "; //����ջ��Ԫ�أ�stackName.top();
		ListStack.pop(); //��ջ��stackName.pop();
	}
} 
//����ջ��Ԫ�صĸ�����stackName.size();

int main() {
	ListPtr L = new LNode();
	L->nextPtr = nullptr;
	addToTail(L,7);
	addToTail(L,8);
	addToTail(L,17);
	addToTail(L,25);
	addToTail(L,36);

	ListPtr ptr = L;
	while(ptr->nextPtr != nullptr) {
		cout << ptr->nextPtr->data << " ";
		ptr = ptr->nextPtr;
	}
	cout << endl;
	
	reverseList(L);
	
	return 0;
}
