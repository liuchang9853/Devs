#include <iostream>
using namespace std;

typedef struct ListNode {
	int data;
	ListNode *nextPtr;
} LNode , *ListPtr;

void addToTail(ListPtr &L , int data) { //尾加法
	ListPtr nodePtr = new LNode();
	nodePtr->data = data;
	nodePtr->nextPtr = nullptr;

	ListPtr ptr = L;
	while (ptr->nextPtr != nullptr) ptr = ptr->nextPtr;
	ptr->nextPtr = nodePtr;
	/*
	一个疑惑是，新分配的空间会不会随着该函数调用的结束而被回收？这要看这个内存空间
	对应的变量。
	（1）若该变量由static声明，则该变量及对应的空间具有全局生命周期，不随被调函数、
	对象实例的终结而终结。
	（2）若被调函数操作的是由主调函数传过去的 空间首址指针 或 空间引用 ，如：
	void t_1(ElemType *p) 、 void t_2(ElemType &p) 、void t_2(ElemType arr[])，
	则对该变量所对应空间的增删改均不因被调函数的终结而失效。
	（3）有这样的操作：
	char * test(){
		char arr[] = {'a','b'};
		return arr;
	}
	void main(){
		char * a = test();
	}
	即试图利用return返回一个指向 由被调函数生成的空间 的指针，这是十分危险的。
	因为这个空间从一开始就是test()开辟的， 既非static，且在main()中也没有一个
	指向它的指针以保障其在被调函数终结时不被回收。所以一旦编译器是这样操作的：
	return赋值给临时对象->回收空间->临时对象赋值给main()中的对象->析构临时对象。
	那么main()中的a就是一个指向垃圾空间的指针。 
	*/
}

void removeNode(ListPtr &L , int data) {
	ListPtr ptr_1 = L , ptr_2 = nullptr;
	while (ptr_1->nextPtr != nullptr) {
		if (ptr_1->nextPtr->data == data) {
			ptr_2 = ptr_1->nextPtr;
			ptr_1->nextPtr = ptr_2->nextPtr;
			delete ptr_2;
		} else ptr_1 = ptr_1->nextPtr;
	}
}

int main() {
	ListPtr L = new LNode();
	L->nextPtr = nullptr;

	addToTail(L,7);
	addToTail(L,9);
	addToTail(L,17);
	addToTail(L,9);
	removeNode(L,9);

	ListPtr ptr = L;
	while(ptr->nextPtr != nullptr) {
		cout << ptr->nextPtr->data;
		ptr = ptr->nextPtr;
	}

	return 0;
}
