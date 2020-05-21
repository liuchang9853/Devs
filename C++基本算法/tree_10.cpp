/*
题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
不能创建任何新的结点，只能调整树中结点指针的指向。
（1）法一是将中序遍历的指针存储。用指针改正lchild和rchild。
（2）法二是利用递归思路。把树看做是左子树、根、右子树。让左子树的最右节点的rchild
指向根，让根的lchild指向左子树的最右节点。同理让右子树的最左节点的lchild指向根，让
根的rchild指向右子树的最左节点。然后递归，让左子树、右子树按上述方式执行。
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct BiTNode {
	int data;
	BiTNode * lchild , * rchild;
} BiTNode , * BiTNodePtr;

//中序遍历造指针数组
void InOrder(BiTNodePtr & T , vector <BiTNodePtr> & nodePtr) {
	if(T) {
		InOrder(T->lchild , nodePtr);
		nodePtr.push_back(T);
		InOrder(T->rchild , nodePtr);
	}
}

//转换函数_1
void double_list_1(BiTNodePtr & T) {
	if(!T) return;

	vector<BiTNodePtr> nodePtr;
	InOrder(T , nodePtr);
	for(vector<BiTNodePtr>::iterator it = nodePtr.begin() ; it != nodePtr.end() ; ++it) {
		if(it != nodePtr.begin() && it != nodePtr.end() - 1) {
			(* it)->lchild = *(it - 1);
			(* it)->rchild = *(it + 1);
			continue;
		}
		if((it == nodePtr.begin()) && (it != nodePtr.end() - 1)) {
			(* it)->lchild = nullptr;
			(* it)->rchild = *(it + 1);
			continue;
		}
		if((it == nodePtr.end() - 1) && (it != nodePtr.begin())) {
			(* it)->lchild = *(it - 1);
			(* it)->rchild = nullptr;
			continue;
		}
		/*
		if和continue的使用是为了减少不必要的判断。
		*/
	}
	T = * nodePtr.begin();
	nodePtr.clear();
}

//转换函数_2
void transform(BiTNodePtr & T) {
	if(T) {
		transform(T->lchild);
		transform(T->rchild);
		
		if(T->lchild) {
			BiTNodePtr lT = T->lchild;
			for( ; lT->rchild ; lT = lT->rchild);
			lT->rchild = T;
			T->lchild = lT;
		}
		
		if(T->rchild) {
			BiTNodePtr rT = T->rchild;
			for( ; rT->lchild ; rT = rT->lchild);
			rT->lchild = T;
			T->rchild = rT;
		}
		/*
		先转换好左右子树，才能转换根节点。如果先转换根节点，那T->lchild和T->rchild就
		变了，不能再递归了。 
		*/
	}
}
void double_list_2(BiTNodePtr & T){
	transform(T);
	for( ; T->lchild ; T = T->lchild);
}
//构建函数
void create_tree(BiTNodePtr ptr , int data , BiTNode * lchild , BiTNode * rchild) {
	ptr->data = data;
	ptr->lchild = lchild;
	ptr->rchild = rchild;
}

int main() {
	BiTNodePtr T = new BiTNode[7]();

	create_tree(&T[0] , 10 , &T[1] , &T[2]);
	create_tree(&T[1] , 6 , &T[3] , &T[4]);
	create_tree(&T[2] , 14 , &T[5] , &T[6]);
	create_tree(&T[3] , 4 , nullptr , nullptr);
	create_tree(&T[4] , 8 , nullptr , nullptr);
	create_tree(&T[5] , 12 , nullptr , nullptr);
	create_tree(&T[6] , 16 , nullptr , nullptr);

	//double_list_1(T);
	double_list_2(T);

	if(T) {
		BiTNodePtr ptr = T;
		for( ; ptr->rchild != nullptr ; ptr = ptr->rchild) cout << ptr->data << ends;
		cout << ptr->data << endl;

		for( ; ptr != T ; ptr = ptr->lchild) cout << ptr->data << ends;
		cout << ptr->data << endl;
	}
	
	return 0;
}
