/*
题目：输入两棵二叉树A和B，判断B是不是A的子结构。
（1）先在A中找到与B_Root相等的节点。
（2）匹配结构。 
*/
#include <iostream>
using namespace std;

typedef struct BiTNode {
	int data;
	BiTNode *lchild , *rchild;
} BiTNode , *BiTNodePtr;

bool match(BiTNodePtr T_A , BiTNodePtr T_B) {
	if(T_B) {
		if(T_A && T_A->data == T_B->data)
			if(match(T_A->lchild , T_B->lchild))
				if(match(T_A->rchild , T_B->rchild)) return true;

		return false;
	} else return true;
}

bool PreOrder(BiTNodePtr T_A , BiTNodePtr T_B) {
	if(!T_B) return true; //若T_B为空，匹配。

	if(T_A) {
		if(T_A->data == T_B->data)
			if(match(T_A , T_B)) return true;
		if(PreOrder(T_A->lchild , T_B)) return true;
		if(PreOrder(T_A->rchild , T_B)) return true;
	}

	return false; //T_A为空执行；T_A及它的两个子树不匹配执行。
}

void create_tree(BiTNodePtr ptr , int data , BiTNode * lchild , BiTNode * rchild) {
	ptr->data = data;
	ptr->lchild = lchild;
	ptr->rchild = rchild;
}

int main() {
	BiTNodePtr T_A = new BiTNode[7]();
	create_tree(&T_A[0] , 8 , &T_A[1] , &T_A[2]);
	create_tree(&T_A[1] , 8 , &T_A[3] , &T_A[4]);
	create_tree(&T_A[2] , 7 , nullptr , nullptr);
	create_tree(&T_A[3] , 9 , nullptr , nullptr);
	create_tree(&T_A[4] , 2 , &T_A[5] , &T_A[6]);
	create_tree(&T_A[5] , 4 , nullptr , nullptr);
	create_tree(&T_A[6] , 7 , nullptr , nullptr);

	BiTNodePtr T_B = new BiTNode[3]();
	create_tree(&T_B[0] , 8 , &T_B[1] , &T_B[2]);
	create_tree(&T_B[1] , 9 , nullptr , nullptr);
	create_tree(&T_B[2] , 2 , nullptr , nullptr);

	if(PreOrder(T_A , T_B)) cout << "T_A matches T_B.";
	else cout << "T_A doesn't match T_B.";

	return 0;
}
