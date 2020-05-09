#include <iostream>
using namespace std;

typedef struct ListNode {
	int data;
	ListNode *nextPtr;
} LNode , *ListPtr;

void addToTail(ListPtr &L , int data) { //β�ӷ�
	ListPtr nodePtr = new LNode();
	nodePtr->data = data;
	nodePtr->nextPtr = nullptr;

	ListPtr ptr = L;
	while (ptr->nextPtr != nullptr) ptr = ptr->nextPtr;
	ptr->nextPtr = nodePtr;
	/*
	һ���ɻ��ǣ��·���Ŀռ�᲻�����Ÿú������õĽ����������գ���Ҫ������ڴ�ռ�
	��Ӧ�ı�����
	��1�����ñ�����static��������ñ�������Ӧ�Ŀռ����ȫ���������ڣ����汻��������
	����ʵ�����ս���սᡣ
	��2����������������������������������ȥ�� �ռ���ַָ�� �� �ռ����� ���磺
	void t_1(ElemType *p) �� void t_2(ElemType &p) ��void t_2(ElemType arr[])��
	��Ըñ�������Ӧ�ռ����ɾ�ľ����򱻵��������ս��ʧЧ��
	��3���������Ĳ�����
	char * test(){
		char arr[] = {'a','b'};
		return arr;
	}
	void main(){
		char * a = test();
	}
	����ͼ����return����һ��ָ�� �ɱ����������ɵĿռ� ��ָ�룬����ʮ��Σ�յġ�
	��Ϊ����ռ��һ��ʼ����test()���ٵģ� �ȷ�static������main()��Ҳû��һ��
	ָ������ָ���Ա������ڱ��������ս�ʱ�������ա�����һ�������������������ģ�
	return��ֵ����ʱ����->���տռ�->��ʱ����ֵ��main()�еĶ���->������ʱ����
	��ômain()�е�a����һ��ָ�������ռ��ָ�롣 
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
