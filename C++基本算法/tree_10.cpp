/*
��Ŀ������һ�ö��������������ö���������ת����һ�������˫������Ҫ��
���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct BiTNode{
	int data;
	BiTNode * lchild , * rchild;
} BiTNode , * BiTNodePtr;

void InOrder(BiTNodePtr & T , vector <BiTNodePtr> & nodePtr) {
	if(T) {
		InOrder(T->lchild , nodePtr);
		nodePtr.push_back(T);
		InOrder(T->rchild , nodePtr);
	}
}

void double_list(BiTNodePtr & T) {
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
		if��continue��ʹ����Ϊ�˼��ٲ���Ҫ���жϡ�
		*/
	}
	T = * nodePtr.begin();
	nodePtr.clear();
}

//��������
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

	double_list(T);
	
	if(T) {
		BiTNodePtr ptr = T;
		for( ; ptr->rchild != nullptr ; ptr = ptr->rchild) cout << ptr->data << ends;
		cout << ptr->data << endl;
		
		for( ; ptr != T ; ptr = ptr->lchild) cout << ptr->data << ends;
		cout << ptr->data << endl;
	}

	return 0;
}
