/*
题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
我们操作链表总是从头到尾，现在要求从尾到头输出。于是想到可以
建立一个栈，扫描list，将每一元素放入stack中，利用其先进后出的
特点，实现目标。
*/
#include <iostream>
#include <stack> //栈头文件 
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
	stack<int> ListStack; //栈定义：stack<ElemType> stackName;

	while(ptr->nextPtr != nullptr) {
		ListStack.push(ptr->nextPtr->data); //入栈：stackName.push(elem); 
		ptr = ptr->nextPtr;
	}

	while (!ListStack.empty()) { //判断栈是否为空：stackName.empty();
		cout << ListStack.top() << " "; //返回栈顶元素：stackName.top();
		ListStack.pop(); //出栈：stackName.pop();
	}
} 
//返回栈中元素的个数：stackName.size();

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
