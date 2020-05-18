/*
��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
������򷵻�true�����򷵻�false���������������������������ֶ�������ͬ��

������������BST�����ص�����С�Ҵ�
{5,7,6,9,11,10,8}��BST�ĺ����������ΪԤ������Ϊ�������У���8Ϊ���ڵ㡣
Ԥ������ΪBST������С�Ҵ󣬼�{5,7,6}����������{9,11,10}����������
������Ԥ�ȼ���Ļ����ϣ������Ŀ�����һ���У��Ϳ��Ե�֪��������BST����

{7,4,6,5}�Ͳ��ǡ�

�������й̶���˵�ǣ���B��ĳһA��ʲô��������A��B��Ӧ��������ô��ô��
�ⷨ����Ԥ��Bȷʵ��ĳһA��ʲô��Ȼ��������ֶ�Ӧ��ϵ��AҪ��B�����
���ʣ�ȥ����B�Ƿ������ˡ����ǣ�A���ڣ�����A�����ڡ�
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
