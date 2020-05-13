/*
题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

5种位运算：
与 &
或 |
异或 ^

左移 9 << 3 = 72 对unsigned、+、-左移，后补0即可。
右移 9 >> 3 = 1 对unsigned、+右移，前补0；对-右移，前补1。
左移 和 右移运算是机器位相关的，本机是64位，故 9 << 3 = 72；若对于一个4bit机器讲，
9 << 3在机器中的二进制运算是：1001 << 3 -> 1000 即8。

位运算符操作的是十进制数（不论是unsigned还是int），转化为内在的二进制运算。
最终输出的也是十进制数。所以使用位运算符时，不用自己写十进制->二进制的转换函数。
*/
#include <iostream>
using namespace std;
int binFun_1(int n) { //输入的还是十进制数9
	int count = 0;
	unsigned int flag = 1;
	while (flag) {
		if (n & flag)
			count++;

		flag = flag << 1;
	}

	return count;
}

int binFun_2(int n) {
	int count = 0;

	while (n) {
		++count;
		n = (n - 1) & n;
	}

	return count;
}
int main() {
	cout << binFun_1(9) << ends << binFun_2(9);
	return 0;
}
