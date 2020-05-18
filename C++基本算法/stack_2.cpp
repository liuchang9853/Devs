/*
题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、5
是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
4、3、5、1、2就不可能是该压栈序列的弹出序列。
*/
#include <iostream>
#include <stack>
using namespace std;

template<typename T>
int length(const T & arr) {
	return sizeof(arr)/sizeof(arr[0]);
}

template <typename T>
bool stack_order_match(T arr_ori [] , T arr_mat []) {
	if(length(arr_ori) != length(arr_mat)) return false;

	stack<T> sta_ori;
	for(int i = 0 , j = 0; j < length(arr_mat) ; ) {
		if(sta_ori.size() > 0 && sta_ori.top() == arr_mat[j]) {
			sta_ori.pop();
			++j;
		} else {
			if(i == length(arr_ori)) return false;
			
			sta_ori.push(arr_ori[i]);
			++i;
		}
	}
	
	return true;
}
int main() {
	char ch_1[] = {'a','b','c','d','e'};
	char ch_2[] = {'d','e','c','b','a'};
	char ch_3[] = {'d','c','e','a','b'};

	if(stack_order_match(ch_1 , ch_2)) cout << "ch_2 matches ch_1";
	else cout << "ch_2 doesn't match ch_1";

	cout << endl;

	if(stack_order_match(ch_1 , ch_3)) cout << "ch_3 matches ch_1";
	else cout << "ch_3 doesn't match ch_1";

	return 0;
}
