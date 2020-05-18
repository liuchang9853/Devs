/*
��Ŀ����ʵ��һ����������֮����˳���ӡ������������һ�а��մ����ҵ�˳
���ӡ���ڶ��㰴�մ��ҵ����˳���ӡ���������ٰ��մ����ҵ�˳���ӡ��
�������Դ����ơ�
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

//������� Ptr_with_level �Ͷ�̬�����visit() 
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

//֮�ִ�ӡ 
void LevelOrder(BiTNodePtr T) {
	vector<Ptr_with_level> outPutArr; //�������

	queue<Ptr_with_level> BiTQueue; //��α�������

	Ptr_with_level root;  
	root.ptr = T;
	root.level = 0;
	BiTQueue.push(root);
	/*
	struct����Ķ�����д��root();��root(1,2);�������Ϊstruct����ֻ����
	��Ա�����ʸ�ֵ����һ�㲻ͬ���࣬��Ϊstruct�޹��캯�����ʣ�
	structType s;
	s.elem_1 = val_1;
	s.elem_2 = val_2;
	*/ 

	Ptr_with_level node;
	while(!BiTQueue.empty()) {
		node = BiTQueue.front();
		BiTQueue.pop();

		outPutArr.push_back(node); //�����Ķ�����Ԫֱ�ӽ����������

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

//��������
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
