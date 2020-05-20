/*
题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。
（1）法一就是大家都能想到的，运算量最大的方法，先构建出一个常规的链表，再设置
count，通过考虑每一原链表节点的 m_pSibling 指针，计算count值，以得到从pHead到m_pSibling
的距离，然后在那个常规链表上实现复制。
法一的核心就是得到从pHead到每一节点的m_pSibling的距离。由此，我们想到了法二。
（2）倘若每一LNode中还定义了一个int索引，那将直接解出此题。可以设一个int hash，
下标从0~n代表顺序排列的链表节点中的int索引，其值表示 m_pSibling->索引。
但这个方法是行不通的，因为不符合题意，改变了LNode结构。同样，再仔细思考，可知
struct{LNodePtr , int index};这样的安排也是不可行的。因为通过链表的关系，无法
定义它上级struct的关系。即，index和LNodePtr仍是相互独立的。
（3）特殊链表复制的较优方法：
先构建A->A'->B->B'->C->C' ，A的m_pSibling指向C，则A'的m_pSibling指向A->m_pSibling->next。
之后，拆分开：A->B->C为原链，A'->B'->C'为复制链。
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
	
	while(LPtr) { //L与L_Clone交叉拼接，对L_Clone的data初始化。 
		L_ClonePtr = new ListNode();
		L_ClonePtr->data = LPtr->data;
		L_ClonePtr->nextPtr = LPtr->nextPtr;
		LPtr->nextPtr = L_ClonePtr;
		LPtr = LPtr->nextPtr->nextPtr;
	}
	L_Clone = L->nextPtr;
	
	LPtr = L; //初始化L_Clone的sibling
	while(LPtr) { 
		if(!LPtr->sibling) LPtr->nextPtr->sibling = LPtr->sibling;
		else LPtr->nextPtr->sibling = LPtr->sibling->nextPtr;
		LPtr = LPtr->nextPtr->nextPtr;
	}

	LPtr = L; //L与L_Clone分离，初始化L_Clone的nextPtr
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
