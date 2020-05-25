/*
题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8这8个数字，
则最小的4个数字是1、2、3、4。
1.法一，排序，取前k。
2.法二，利用快排思路，基本做法和快速排序_2中一样，把mid改为k。
3.法三，构建multiset<int>arr用于存放遍历Arr[n]时，读到的当前最小的k个数字。若i<k，
则读入；若i>k，则用新读到的Arr[i]与arr的最大值（此时arr最大值位于arr的尾部，用arr.end()获取）
比较，若Arr[i]>=* (arr.end()-1)则替换arr尾部；否则++i。

法三特别适用于海量数据处理。
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
