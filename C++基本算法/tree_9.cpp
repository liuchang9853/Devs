/*
题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct BiTNode {
	int data;
	BiTNode * lchild , * rchild;
} BiTNode , * BiTNodePtr;

//打印路径
void PreOrder(BiTNodePtr T , vector<BiTNodePtr> & path_node , int key) {
	if(T) {
		path_node.push_back(T);
		
		if(T->lchild == nullptr && T->rchild == nullptr) {
			int val = 0;
			for(int i = 0 ; i < path_node.size() ; ++i) val += path_node[i]->data;
			if(val == key) {
				for(vector<BiTNodePtr>::iterator it = path_node.begin() ; it != path_node.end() ; ++it)
					cout << (* it)->data << ends;
				cout << endl;
			}
		}
		
		PreOrder(T->lchild , path_node , key);
		PreOrder(T->rchild , path_node , key);
		
		path_node.pop_back();
	}
	/*
	典型的递归三明治。把当前节点压入栈，计算是否满足并得到一个结果。接着把这种
	关系传递给它的孩子。最后再弹出该节点。 
	*/
}

//构建函数
void create_tree(BiTNodePtr ptr , int data , BiTNode * lchild , BiTNode * rchild) {
	ptr->data = data;
	ptr->lchild = lchild;
	ptr->rchild = rchild;
}

int main() {
	BiTNodePtr T = new BiTNode[5]();

	create_tree(&T[0] , 10 , &T[1] , &T[2]);
	create_tree(&T[1] , 5 , &T[3] , &T[4]);
	create_tree(&T[2] , 12 , nullptr , nullptr);
	create_tree(&T[3] , 4 , nullptr , nullptr);
	create_tree(&T[4] , 7 , nullptr , nullptr);

	vector<BiTNodePtr> path_node;
	PreOrder(T , path_node , 22);

	return 0;
}
