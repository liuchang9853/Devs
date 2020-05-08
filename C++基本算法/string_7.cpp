/*
题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
则输出“We%20are%20happy.”。
（1）从头到尾，遇到一个空格，将空格后的所有字符向后移动2B，在空出来的3B中输入"%20"，
该法的时间复杂度为O(n^2)。
（2）从尾到头（或从头到尾）第一次遍历，扫描出空格个数，先向后拓展：空格数 ×2B 大小的空间。
从尾到头，把字符向后移动，遇到空格后，输入"20%"。时间复杂度为O(n)。
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

void place(char * str,int slen) {
	int blankNum = 0;
	for (int i=0; i<slen; ++i)
		if(str[i]==' ') ++blankNum;
	
	char *newstr = new char[slen + blankNum * 2]; 
	
	for(int ptr = slen - 1 , newptr = slen + blankNum * 2 - 1; ptr >= 0; --ptr) {
	
		if(str[ptr] == ' ') {
			newstr[newptr--] = '0';
			newstr[newptr--] = '2';
			newstr[newptr--] = '%';
			
			--blankNum;
			continue;
		}
		newstr[newptr--] = str[ptr];
	}
	cout << newstr;
}
int main() {
	string str;
	getline(cin , str);
	
	char * arr = new char[str.size()+1];
	strcpy(arr,str.c_str());
	
	place(arr,str.size()+1);
	
	return 0;
}
/*
1.char * arr = new char[str.size()+1];语句要注意的点是：要把string赋值给一个char[]，要记得
char[]的长度是str.size()+'\0'所占的1个元素位。
2.
string str;
getline(cin , str);
char * arr = new char[str.size()+1];
strcpy(arr,str.c_str());
place(arr,str.size()+1);
分析：
（1）把 char * arr = new char[str.size()+1]; 写成 char *arr; 则会在strcpy这步出错，
问题在于arr的空间边界没有被确定。要记住，若指针指向的空间边界没有确定，则将导致一系列
无法预料到的后果。操作指针，一定一定要尽可能早的确定其指向的空间边界。
（2）strcpy(char * , const char *);要注意第二个参数不能写成string类型的参数。string属于
C++特有的类型，string!=const char *。例如：
string str= "I love you.";
char * str= "I love you.";
const char * str = "I love you.";
三者定义的变量值都相等，见string_6。
但又有区别，见string_4。
这里的重点是：#include<cstring>是C下的头文件，所操作的仅限于(const)char *、char []定义
的字符串；对于#include<string>这一C++下的头文件，需将其中定义的string类型使用c_str()方法
转换为C下的const char *再使用。
（3）在使用char *str相关的字符串时，要记住：str 和 strlen一起考虑。比如作为参数，传str
的地方，一般也要传strlen。因为只传str，是无法得知其边界的。 
（4）
A. 数组长度：
template <class T>
int length(const T & arr) {
	return sizeof(arr)/sizeof(arr[0]);
}

B. string str中str的长度：
str.length() 或 str.size()

C. char * ptr长度：
string str="I love you.";
char * ptr = new char[str.length()+1];
strcpy(ptr,str.c_str());
fun(str.length()+1,ptr);
或
char arr[] = "I love you.";
char * ptr = new char[length(arr)];
for(int i=0;i<length(arr);++i) ptr[i] = arr[i];
fun(length(arr),ptr);
*/
