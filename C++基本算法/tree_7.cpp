/*
题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
其他行以此类推。
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct BiTNode {
	int data;
	BiTNode * lchild , * rchild;
} BiTNode , * BiTNodePtr;

struct Ptr_with_level {
	BiTNodePtr ptr;
	int level;
};

//用于输出 Ptr_with_level 型动态数组的visit() 
void visit(vector<Ptr_with_level> & outPutArr) {
	int i = 0;
	vector<int> oddArr;
	while(i < outPutArr.size()) {
		for( ; i < outPutArr.size() && outPutArr[i].level % 2 == 0 ; ++i) cout << outPutArr[i].ptr->data << ends;
		cout << endl;

		for( ; i < outPutArr.size() && outPutArr[i].level % 2 == 1 ; ++i) oddArr.push_back(outPutArr[i].ptr->data);
		for(int j = oddArr.size() - 1 ; j >= 0 ; --j) cout << oddArr[j] << ends;
		oddArr.clear();
		cout << endl;
	}
	oddArr.clear();
}

//之字打印 
void LevelOrder(BiTNodePtr T) {
	vector<Ptr_with_level> outPutArr; //输出数组

	queue<Ptr_with_level> BiTQueue; //层次遍历队列

	Ptr_with_level root;  
	root.ptr = T;
	root.level = 0;
	BiTQueue.push(root);
	/*
	struct定义的对象，若写成root();或root(1,2);则错误，因为struct对象只能用
	成员符访问赋值。这一点不同于类，因为struct无构造函数。故：
	structType s;
	s.elem_1 = val_1;
	s.elem_2 = val_2;
	*/ 

	Ptr_with_level node;
	while(!BiTQueue.empty()) {
		node = BiTQueue.front();
		BiTQueue.pop();

		outPutArr.push_back(node); //弹出的队列首元直接进入输出数组

		if(node.ptr->lchild!=nullptr) {
			Ptr_with_level lchild_node;
			lchild_node.ptr = node.ptr->lchild;
			lchild_node.level = node.level + 1;
			BiTQueue.push(lchild_node);
		}
		if(node.ptr->rchild!=nullptr) {
			Ptr_with_level rchild_node;
			rchild_node.ptr = node.ptr->rchild;
			rchild_node.level = node.level + 1;
			BiTQueue.push(rchild_node);
		}
	}

	visit(outPutArr);
	outPutArr.clear();
}

//构建函数
void create_tree(BiTNodePtr ptr , int data , BiTNode * lchild , BiTNode * rchild) {
	ptr->data = data;
	ptr->lchild = lchild;
	ptr->rchild = rchild;
}
 
int main() {
	BiTNodePtr T = new BiTNode[15]();
	create_tree(&T[0] , 1 , &T[1] , &T[2]);
	create_tree(&T[1] , 2 , &T[3] , &T[4]);
	create_tree(&T[2] , 3 , &T[5] , &T[6]);
	create_tree(&T[3] , 4 , &T[7] , &T[8]);
	create_tree(&T[4] , 5 , &T[9] , &T[10]);
	create_tree(&T[5] , 6 , &T[11] , &T[12]);
	create_tree(&T[6] , 7 , &T[13] , &T[14]);
	create_tree(&T[7] , 8 , nullptr , nullptr);
	create_tree(&T[8] , 9 , nullptr , nullptr);
	create_tree(&T[9] , 10 , nullptr , nullptr);
	create_tree(&T[10] , 11 , nullptr , nullptr);
	create_tree(&T[11] , 12 , nullptr , nullptr);
	create_tree(&T[12] , 13 , nullptr , nullptr);
	create_tree(&T[13] , 14 , nullptr , nullptr);
	create_tree(&T[14] , 15 , nullptr , nullptr);
	
	LevelOrder(T);
	 
	return 0;
}
