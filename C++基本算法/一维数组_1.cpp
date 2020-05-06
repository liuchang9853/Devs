/*
题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，
但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，那么对应的输出是重复的数字2或者3。
（1）排序后查找。时间复杂度：O(nlogn)。
（2）建立Hash表，时间复杂度：O(n)；空间复杂度：O(n)。
（3）原地Hash，时间复杂度：O(n)；空间复杂度：O(1)。
采用法（3）。
*/
#include <iostream>
using namespace std;
bool duplicate(int numbers[], int length, int* duplication) {
	if(numbers == nullptr || length <= 0)
		return false;

	for(int i = 0; i < length; ++i) {
		if(numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	for(int i = 0; i < length; ++i) {
		while(numbers[i] != i) {
			if(numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				return true;
			}

			// 交换numbers[i]和numbers[numbers[i]]
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	
	return false;
}
/*
该代码的聪明之处在于：通过return这一传统方式 和 int* duplication方式实现了向被调函数
的传值操作。在main()中调用duplicate(int numbers[], int length, int* duplication)，向
其传递的第三个实参是在main()中定义的指向一int内存的地址。duplicate()函数运行结束，
return bool并修改了该内存中的int值。即回收duplication指针，不回收该int内存。 
*/
template <class T>
int length(const T & arr) {
	return sizeof(arr)/sizeof(arr[0]);
}
int main() {
	int numbers [] = {2, 3, 1, 0, 2, 5, 3};
	int len = length(numbers);
	int * duplication = new int;
	cout << duplicate(numbers , len , duplication) << endl;
	cout << * duplication << endl;
	/*
	输出：
	1
	2 
	*/ 
	for (int i=0;i<len;++i) cout << numbers[i];
	/*
	输出：
	0123253 
	由此看出，空间复杂度：O(1)，没有开辟新的空间。
	*/ 
	return 0;
}
