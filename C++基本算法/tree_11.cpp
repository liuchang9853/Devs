/*
题目：请实现两个函数，分别用来序列化和反序列化二叉树。序列化就是二叉树转链表，反序列化就是
链表转二叉树。
（1）可以使用中序序列和先序序列来反序列化；也可以将二叉树序列化为中序序列和先序序列。但
有两个链表（中序序列 和 先序序列）要考虑。
（2）若如下：
     1
    /\
   2  3
  /  /\
 4  5  6
在序列化二叉树时将所有的nullptr都转化为链表的一个元素，则可以用一个先序（或中序）链表
就可以解答该题。
该二叉树的（先序）序列化结果是：1 2 4 null null null 3 5 null null 6 null null
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct BiTNode {
	int data;
	BiTNode *lchild , *rchild;
} BiTNode , *BiTNodePtr;

//序列化 
void serialization(BiTNodePtr T , vector<int> & list) {
	if(T) {
		list.push_back(T->data);
		serialization(T->lchild , list);
		serialization(T->rchild , list);
	} else list.push_back(-1);
}

//反序列化 
void deserialization(vector<int> & list , BiTNodePtr &T , int & index) {
	if(list.size() <= 0) return;

	T = new BiTNode();
	T->data = list[index];

	if(index < list.size() - 1 && list[++index] != -1)
		deserialization(list , T->lchild , index);
	else T->lchild = nullptr;

	if(index < list.size() - 1 && list[++index] != -1)
		deserialization(list , T->rchild , index);
	else T->rchild = nullptr;
	/*
	1.这个代码的难点在于函数头部的 & index，之所以要设置引用，是因为在递归时要有这样的
	考虑：哪些参数要求递归一次，递增一次，即不会因子递归的return而还原（如index）；
	哪些参数要求	在子递归中比在父函数大，即随着子递归的return而还原（如T）；
	又有哪些参数不论如何递归都不变（如list）。
	
	这里是一个树要依据一个线性链表的变化而变化，因此要设置&index ，也要设置&T。
	
	2.理解起来并不难，就是设置头节点、初始化data；若list中的下一元素非空，表明有
	lchild，则把关系传递出去，否则lchild=nullptr；同理可以设置rchild。 
	*/
}

//先序遍历验证
void visit(BiTNodePtr T) {
	cout << T->data << ends;
}

void PreOrder(BiTNodePtr T) {
	if(T!=nullptr) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
} 

//构建函数
void create_tree(BiTNodePtr ptr , int data , BiTNode * lchild , BiTNode * rchild) {
	ptr->data = data;
	ptr->lchild = lchild;
	ptr->rchild = rchild;
}

int main() {
	//1.验证序列化
	BiTNodePtr T = new BiTNode[6]();

	create_tree(&T[0] , 1 , &T[1] , &T[2]);
	create_tree(&T[1] , 2 , &T[3] , nullptr);
	create_tree(&T[2] , 3 , &T[4] , &T[5]);
	create_tree(&T[3] , 4 , nullptr , nullptr);
	create_tree(&T[4] , 5 , nullptr , nullptr);
	create_tree(&T[5] , 6 , nullptr , nullptr);
	
	vector<int> list;
	
	serialization(T , list);
	for(int i = 0 ; i < list.size() ; ++i) cout << list[i] << ends;
	
	cout << endl;

	//1.验证反序列化
	T = nullptr;
	int index = 0;
	deserialization(list , T , index);
	PreOrder(T);
	
	return 0;
}
