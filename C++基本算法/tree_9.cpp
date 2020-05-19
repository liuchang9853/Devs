/*
��Ŀ������һ�ö�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
*/
#include <iostream>
#include <vector>
using namespace std;

typedef struct BiTNode {
	int data;
	BiTNode * lchild , * rchild;
} BiTNode , * BiTNodePtr;

//��ӡ·��
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
	���͵ĵݹ������Ρ��ѵ�ǰ�ڵ�ѹ��ջ�������Ƿ����㲢�õ�һ����������Ű�����
	��ϵ���ݸ����ĺ��ӡ�����ٵ����ýڵ㡣 
	*/
}

//��������
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
