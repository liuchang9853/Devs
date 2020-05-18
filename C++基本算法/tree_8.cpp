/*
题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

二叉搜索树（BST）的特点是左小右大。
{5,7,6,9,11,10,8}是BST的后序遍历，因为预先视其为后序序列，则8为根节点。
预先视其为BST，则左小右大，即{5,7,6}是左子树，{9,11,10}是右子树。
在两次预先假设的基础上，迭代的考虑这一序列，就可以得知该序列是BST后序。

{7,4,6,5}就不是。

这种题有固定的说辞：若B是某一A的什么（即存在A与B对应），则怎么怎么。
解法就是预设B确实是某一A的什么，然后根据这种对应关系下A要求B满足的
性质，去倒推B是否果真如此。若是，A存在，否则，A不存在。
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct BiTNode {
	int data;
	BiTNode *lchild , *rchild;
} BiTNode , *BiTNodePtr;

bool if_bst_post(int * arr , int len) {
	if(len == 0) return true;
	
	int root = arr[len - 1];
	vector<int> larr;
	vector<int> rarr;
	int i = 0;
	for( ; arr[i] < root ; ++i) larr.push_back(arr[i]);
	for( ; arr[i] > root ; ++i) rarr.push_back(arr[i]);
	
	int * Larr = new int[larr.size()];
	int Llen = larr.size();
	larr.clear();
	for(int j = 0 ; j < Llen ; ++j) Larr[j] = larr[j];
	
	int * Rarr = new int[rarr.size()];
	int Rlen = rarr.size();
	rarr.clear();
	for(int j = 0 ; j < Rlen ; ++j) Rarr[j] = rarr[j];
	
	if(i != len - 1) {
		delete Larr;
		delete Rarr;
		return false;
	}
	
	if(if_bst_post(Larr , Llen) && if_bst_post(Rarr , Rlen)) {
		delete Larr;
		delete Rarr;
		return true;
	}
}

int main() {
	int arr_1[] = {5,7,6,9,11,10,8};
	int arr_2[] = {7,4,6,5};
	if(if_bst_post(arr_1 , 7)) cout << "arr_1 is bst_post";
	else cout << "arr_1 isn't bst_post";
	cout << endl;
	if(if_bst_post(arr_2 , 4)) cout << "arr_2 is bst_post";
	else cout << "arr_2 isn't bst_post";
	return 0;
}
