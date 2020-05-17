/*
��Ŀ����ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ����һ�ö�������
���ľ���һ������ô���ǶԳƵġ�
��1���ж�����ұ�����dataֵ �Ƿ���� �Ҹ��������dataֵ��
��2���ж����ֱ�������£�����λ���Ƿ���ͬ��ΪӦ��ȫ����ֵ������� 
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct BiTNode {
	int data;
	BiTNode *lchild , *rchild;
} BiTNode , *BiTNodePtr;

//��������
void create_tree(BiTNodePtr ptr , int data , BiTNode * lchild , BiTNode * rchild) {
	ptr->data = data;
	ptr->lchild = lchild;
	ptr->rchild = rchild;
}

//�Գ��ж� 
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
	vector<BiTNodePtr> arr_1; //arr_1�д�������ָ�롣 
	vector<BiTNodePtr> arr_2; //arr_1�д���Ҹ���ָ�롣
	
	InOrder_l_r(T , arr_1);
	InOrder_r_l(T , arr_2);
	
	for(int i = 0 ; i < arr_1.size() ; ++i) {
		if(arr_1[i]->data != arr_2[i]->data) 
			return false; //����ұ����������Ҹ��������return false�� 
			
		if(arr_1[i] == T)
			if(arr_2[i] != T)
				return false; //����ұ���������λ�ò������Ҹ����������λ�ã�return false�� 
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
