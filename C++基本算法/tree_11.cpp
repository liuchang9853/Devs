/*
��Ŀ����ʵ�������������ֱ��������л��ͷ����л������������л����Ƕ�����ת���������л�����
����ת��������
��1������ʹ���������к����������������л���Ҳ���Խ����������л�Ϊ�������к��������С���
������������������ �� �������У�Ҫ���ǡ�
��2�������£�
     1
    /\
   2  3
  /  /\
 4  5  6
�����л�������ʱ�����е�nullptr��ת��Ϊ�����һ��Ԫ�أ��������һ�����򣨻���������
�Ϳ��Խ����⡣
�ö������ģ��������л�����ǣ�1 2 4 null null null 3 5 null null 6 null null
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct BiTNode {
	int data;
	BiTNode *lchild , *rchild;
} BiTNode , *BiTNodePtr;

//���л� 
void serialization(BiTNodePtr T , vector<int> & list) {
	if(T) {
		list.push_back(T->data);
		serialization(T->lchild , list);
		serialization(T->rchild , list);
	} else list.push_back(-1);
}

//�����л� 
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
	1.���������ѵ����ں���ͷ���� & index��֮����Ҫ�������ã�����Ϊ�ڵݹ�ʱҪ��������
	���ǣ���Щ����Ҫ��ݹ�һ�Σ�����һ�Σ����������ӵݹ��return����ԭ����index����
	��Щ����Ҫ��	���ӵݹ��б��ڸ������󣬼������ӵݹ��return����ԭ����T����
	������Щ����������εݹ鶼���䣨��list����
	
	������һ����Ҫ����һ����������ı仯���仯�����Ҫ����&index ��ҲҪ����&T��
	
	2.������������ѣ���������ͷ�ڵ㡢��ʼ��data����list�е���һԪ�طǿգ�������
	lchild����ѹ�ϵ���ݳ�ȥ������lchild=nullptr��ͬ���������rchild�� 
	*/
}

//���������֤
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

//��������
void create_tree(BiTNodePtr ptr , int data , BiTNode * lchild , BiTNode * rchild) {
	ptr->data = data;
	ptr->lchild = lchild;
	ptr->rchild = rchild;
}

int main() {
	//1.��֤���л�
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

	//1.��֤�����л�
	T = nullptr;
	int index = 0;
	deserialization(list , T , index);
	PreOrder(T);
	
	return 0;
}
