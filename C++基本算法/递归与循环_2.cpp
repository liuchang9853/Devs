/*
题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。
（1）把n位划分为1和n-1。固定第一位，全排列后n-1位。
（2）对后n-1位，也划分为1和n-2，全排列后n-2位。递归。
*/
#include <iostream>
using namespace std;
void permutations(char str_change [] , int start , int strLen) {
	if(strLen == 0) return;

	for(int i = start ; i < strLen ; ++i) {
		//三明治头 
		char * str_change_fixed = new char[strLen];
		for(int i = 0 ; i < strLen ; ++i) str_change_fixed[i] = str_change[i];
		
		//固定首元
		char ch = str_change[i];
		str_change[i] = str_change[start];
		str_change[start] = ch;
		
		//递归
		permutations(str_change , start + 1 , strLen);
		
		//三明治尾 
		for(int i = 0 ; i < strLen ; ++i) str_change[i] = str_change_fixed[i];
		
		/*
		这个三明治是最难的部分，原因在于之前没有搞清楚一个问题：到底什么时候、什么情况下
		构建这个三明治？这里定义如下：当为了给递归调用传递关系而改变某些数据时，就要考虑
		是否要在这些数据和递归调用两端构建一个三明治，以保证这些数据可以不受某次递归的影
		响，而不受某次递归的影响是循环套递归结构求解的基本要求。
		当然，也有可能出现如tree_11中所述的那种要求，即需要递归改变的数据。这就不需要三明
		治了，而要使用&、指针来传参。 
		*/ 
	}

	if(start == strLen) {
		for(int i = 0 ; i < strLen ; ++i) cout << str_change[i] << ends;
		cout << endl;
	}
}

void start_permutations(char str [] , int strLen) {
	char * str_change = new char[strLen];
	for(int i = 0 ; i < strLen ; ++i) str_change[i] = str[i];
	permutations(str_change , 0 , strLen);
	delete str_change;
	/*
	启动函数的重要性：
	1.可以缩减在main函数中调用递归进程时的参数输入。这里，main中只要输入两个参数，递归体
	要输入4个参数。
	2.设计启动函数可以促使我们产生这样的思考：递归体需要什么？它需要的这个东西是是每
	递归一次就变化的，还是持久不变的？若变化又是怎么变化的？等等。
	*/
}

int main() {
	char str [] = {'a','b','c','d'};
	start_permutations(str , 4);
	return 0;
}
