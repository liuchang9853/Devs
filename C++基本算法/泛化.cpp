/*
题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
奇数位于数组的前半部分，所有偶数位于数组的后半部分。
*/
#include <iostream>
using namespace std;

bool reg(int * arr , int * ptr) {
	if(* ptr % 2 == 1) return true;
	else return false;
	return true;
}

template <class T> //泛化提高了代码的重用性 
void list_with_double_ptr(T * arr , int length) {
	T * ptr_start = &arr[0];
	T * ptr_end = &arr[length - 1];

	while(ptr_start != ptr_end) { 
		for( ; ptr_start != ptr_end && reg(arr , ptr_start) ; ++ptr_start);
		if(ptr_start == ptr_end) return;
		else {
			T space = * ptr_end;
			* ptr_end = * ptr_start;
			* ptr_start = space;
		}

		for( ; ptr_end != ptr_start && !reg(arr , ptr_end) ; --ptr_end);
		if(ptr_start == ptr_end) return;
		else {
			T space = * ptr_start;
			* ptr_start = * ptr_end;
			*ptr_end = space;
		}
	}
	/*
	reg()使得这段代码的规则也是泛化的，若把问题改为能被3整除在前，不能被3整除在后；
	或者负数在前，正数在后，则修改reg()即可。 
	*/
}

int main() {
	int arr[7] = {1,4,55,2,3,4,7};
	list_with_double_ptr(arr , 7);
	for(int i = 0 ; i < 7 ; ++i) cout << arr[i] << ends;
	return 0;
}
