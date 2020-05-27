/*
题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻
译成"b"，……，11翻译成"l"，……，25翻译成"z"。一个数字可能有多个翻译。
例如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和
"mzi"。请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。
分析：
典型的滑动窗口问题。
5个数字，全按1位处理，可得的1种翻译方式。++count。 
设置窗口为2，将窗口从头开始遍历，窗口值满足大于10小于25的，可得一种翻译方式，++count。
窗口从头开始遍历，设置子窗口递归。 
*/
#include <iostream>
#include <string>
using namespace std;

//递归过程
int translation(string num , int start) {
	int count = 0;
	for(int i = start ; i + 1 <= num.length() - 1 ; ++i)
		if(num.substr(i,2).compare("10") >= 0 && num.substr(i,2).compare("25") <= 0)
			++count;
	for(int i = start ; i + 1 <= num.length() - 3 ; ++i)
		if(num.substr(i,2).compare("10") >= 0 && num.substr(i,2).compare("25") <= 0)
			count += translation(num , i + 2);
	return count;
}

//启动函数
int num_translator(string num) {
	for(int i = 0 ; i < num.length() ; ++i)
		if(int(num[i]) < 48 || int(num[i]) > 57) return 0;
	return translation(num , 0) + 1;
	/*
	1表示num全按1元组划分时的一种翻译结果。
	num.length - (count - 1) * 2 - 1是2元组的首元窗口滑动停止下标。例如当有两个2元组时，
	首元窗口下滑至5-2-1=2处停止滑动。
	*/
}

int main() {
	string num = "12222";
	cout << num_translator(num);
	return 0;
}
