/*
��Ŀ������n���������ҳ�������С��k��������������4��5��1��6��2��7��3��8��8�����֣�
����С��4��������1��2��3��4��
1.��һ������ȡǰk��
2.���������ÿ���˼·�����������Ϳ�������_2��һ������mid��Ϊk��
3.����������multiset<int>arr���ڴ�ű���Arr[n]ʱ�������ĵ�ǰ��С��k�����֡���i<k��
����룻��i>k�������¶�����Arr[i]��arr�����ֵ����ʱarr���ֵλ��arr��β������arr.end()��ȡ��
�Ƚϣ���Arr[i]>=* (arr.end()-1)���滻arrβ��������++i��

�����ر������ں������ݴ���
*/
#include <iostream>
#include <set>
using namespace std;
void min_k(int arr [] , int length , int k) {
	if(length <= 0 || k > length || k <= 0) {
		cout << "error";
		return;
	}
	multiset<int> mul;
	for(int i = 0 ; i < k ; ++i) mul.insert(arr[i]);
	for(int i = k ; i < length ; ++i) {
		multiset<int>::iterator it = mul.end();
		--it;
		if(arr[i] < * it) {
			mul.erase(it);
			mul.insert(arr[i]);
		}
	}
	for(multiset<int>::iterator it = mul.begin() ; it != mul.end() ; ++it) cout<< * it << ends;
}
int main() {
	int arr[10] = {5,10,-1,0,13,5,4,2,0,11};
	int k = 2;
	min_k(arr , 10 , k);
	return 0;
}
