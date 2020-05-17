/*
题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
它的镜像一样，那么它是对称的。
（1）判断左根右遍历的data值 是否等于 右根左遍历的data值。
（2）判断两种遍历情况下，树根位置是否相同。为应对全树等值的情况。 
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct BiTNode {
	int data;
	BiTNode *lchild , *rchild;
} BiTNode , *BiTNodePtr;

//构建函数
void create_tree(BiTNodePtr ptr , int data , BiTNode * lchild , BiTNode * rchild) {
	ptr->data = data;
	ptr->lchild = lchild;
	ptr->rchild = rchild;
}

//对称判定 
void InOrder_l_r(BiTNodePtr T , vector<BiTNodePtr> &arr) {
	if(T!=nullptr) {
		InOrder_l_r(T->lchild , arr);
		arr.push_back(T);
		InOrder_l_r(T->rchild , arr);
	}
}

void InOrder_r_l(BiTNodePtr T , vector<BiTNodePtr> &arr) {
	if(T!=nullptr) {
		InOrder_r_l(T->rchild , arr);
		arr.push_back(T);
		InOrder_r_l(T->lchild , arr);
	}
}

bool symmetry_tree(BiTNodePtr T) {
	vector<BiTNodePtr> arr_1; //arr_1中存放左根右指针。 
	vector<BiTNodePtr> arr_2; //arr_1中存放右根左指针。
	
	InOrder_l_r(T , arr_1);
	InOrder_r_l(T , arr_2);
	
	for(int i = 0 ; i < arr_1.size() ; ++i) {
		if(arr_1[i]->data != arr_2[i]->data) 
			return false; //左根右遍历不等于右根左遍历，return false。 
			
		if(arr_1[i] == T)
			if(arr_2[i] != T)
				return false; //左根右遍历中树根位置不等于右根左遍历树根位置，return false。 
	}
	
	return true;
}

int main() {
	BiTNodePtr T = new BiTNode[6]();
	create_tree(&T[0] , 7 , &T[1] , &T[2]);
	create_tree(&T[1] , 7 , &T[3] , &T[4]);
	create_tree(&T[2] , 7 , &T[5] , nullptr);
	create_tree(&T[3] , 7 , nullptr , nullptr);
	create_tree(&T[4] , 7 , nullptr , nullptr);
	create_tree(&T[5] , 7 , nullptr , nullptr);

	if(symmetry_tree(T)) cout << "this tree is symmetrical.";
	else cout << "this tree isn't symmetrical.";

	return 0;
}
