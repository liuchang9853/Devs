#include <iostream>
#include <string>
using namespace std;
int main() {
	char str_1[] = "I love you.";
	char str_2[] = "I love you.";
	char * str_3 = "I love you.";
	char * str_4 = "I love you.";
	string str_5 = "I love you.";
	string str_6 = "I love you.";

	const char * arr = (str_1 == str_2 ? "str_1=str_2" : "str_1!=str_2");
	const char * ptr = (str_3 == str_4 ? "str_3=str_4" : "str_3!=str_4");
	const char * str = (str_5 == str_6 ? "str_5=str_6" : "str_5!=str_6");

	const char * ptr_str = (str_3 == str_5 ? "str_3=str_5" : "str_3!=str_5");

	cout << arr << endl << ptr << endl << str << endl << ptr_str;
	/*
	输出结果：
	str_1!=str_2
	str_3=str_4
	str_5=str_6
	str_3=str_5
	原因：C/C++把字符串常量放到一个单独的内存区域，当字符串赋值给char * 或 string等指针类型
	的变量时，这些指针均指向该内存区域，即均指向同一个内存区域。
	但赋值给数组类型的变量则不同，编译器会为数组各自开辟空间，以char类型元素视字符串元素，逐
	一复制入数组。 
	*/
	
	/*
	* str_3 = "I hate you.";这样的写法是错误的。str_3可以被重新赋值，但其指向的内容是const。
	
	不同于：
	int i = 0;
	int * ptr = &i;
	* ptr = 1;
	这是成立的。 
	*/  
	return 0;
}
