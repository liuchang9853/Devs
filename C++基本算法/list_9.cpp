/*
��Ŀ����ʵ�ֺ���ComplexListNode* Clone(ComplexListNode* pHead)����
��һ�����������ڸ��������У�ÿ����������һ��m_pNextָ��ָ����һ��
����⣬����һ��m_pSibling ָ�������е����������nullptr��
��1����һ���Ǵ�Ҷ����뵽�ģ����������ķ������ȹ�����һ�����������������
count��ͨ������ÿһԭ����ڵ�� m_pSibling ָ�룬����countֵ���Եõ���pHead��m_pSibling
�ľ��룬Ȼ�����Ǹ�����������ʵ�ָ��ơ�
��һ�ĺ��ľ��ǵõ���pHead��ÿһ�ڵ��m_pSibling�ľ��롣�ɴˣ������뵽�˷�����
��2������ÿһLNode�л�������һ��int�������ǽ�ֱ�ӽ�����⡣������һ��int hash��
�±��0~n����˳�����е�����ڵ��е�int��������ֵ��ʾ m_pSibling->������
������������в�ͨ�ģ���Ϊ���������⣬�ı���LNode�ṹ��ͬ��������ϸ˼������֪
struct{LNodePtr , int index};�����İ���Ҳ�ǲ����еġ���Ϊͨ������Ĺ�ϵ���޷�
�������ϼ�struct�Ĺ�ϵ������index��LNodePtr�����໥�����ġ�
��3�����������ƵĽ��ŷ�����
�ȹ���A->A'->B->B'->C->C' ��A��m_pSiblingָ��C����A'��m_pSiblingָ��A->m_pSibling->next��
֮�󣬲�ֿ���A->B->CΪԭ����A'->B'->C'Ϊ��������
*/
#include <iostream>
using namespace std;

typedef struct ListNode {
	char data;
	ListNode * nextPtr , * sibling;
} ListNode , * ListPtr;

void clone_list(ListPtr & L , ListPtr & L_Clone) {
	if(!L) return;
	 
	ListPtr LPtr = L , L_ClonePtr = L_Clone;
	
	while(LPtr) { //L��L_Clone����ƴ�ӣ���L_Clone��data��ʼ���� 
		L_ClonePtr = new ListNode();
		L_ClonePtr->data = LPtr->data;
		L_ClonePtr->nextPtr = LPtr->nextPtr;
		LPtr->nextPtr = L_ClonePtr;
		LPtr = LPtr->nextPtr->nextPtr;
	}
	L_Clone = L->nextPtr;
	
	LPtr = L; //��ʼ��L_Clone��sibling
	while(LPtr) { 
		if(!LPtr->sibling) LPtr->nextPtr->sibling = LPtr->sibling;
		else LPtr->nextPtr->sibling = LPtr->sibling->nextPtr;
		LPtr = LPtr->nextPtr->nextPtr;
	}

	LPtr = L; //L��L_Clone���룬��ʼ��L_Clone��nextPtr
	L_ClonePtr = L_Clone;
	while(LPtr) {
		LPtr->nextPtr = L_ClonePtr->nextPtr;
		if(L_ClonePtr->nextPtr)
			L_ClonePtr->nextPtr = L_ClonePtr->nextPtr->nextPtr;
		LPtr = LPtr->nextPtr;
		L_ClonePtr = L_ClonePtr->nextPtr;
	}
}

int main() {
	ListPtr L = new ListNode();
	L->data = 'A';
	L->nextPtr = new ListNode();

	ListNode * ptr = L;
	ptr = ptr->nextPtr;

	ptr->data = 'B';
	ptr->nextPtr = new ListNode();
	ptr = ptr->nextPtr;

	ptr->data = 'C';
	ptr->nextPtr = new ListNode();
	ptr = ptr->nextPtr;

	ptr->data = 'D';
	ptr->nextPtr = new ListNode();
	ptr = ptr->nextPtr;

	ptr->data = 'E';
	ptr->nextPtr = nullptr;

	ptr = L;
	ptr->sibling = L->nextPtr->nextPtr;

	ptr = ptr->nextPtr;
	ptr->sibling = L->nextPtr->nextPtr->nextPtr->nextPtr;

	ptr = ptr->nextPtr;
	ptr->sibling = nullptr;

	ptr = ptr->nextPtr;
	ptr->sibling = L->nextPtr;

	ptr = ptr->nextPtr;
	ptr->sibling = nullptr;

	ListPtr L_Clone = nullptr;
	clone_list(L , L_Clone);

	for(ListPtr L_Clone_Ptr = L_Clone ; L_Clone_Ptr ; L_Clone_Ptr = L_Clone_Ptr->nextPtr)
		if(L_Clone_Ptr->sibling)
			cout << L_Clone_Ptr->sibling->data << ends;
		else cout << -1 << ends;

	return 0;
}
