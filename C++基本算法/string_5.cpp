#include <iostream>
#include <string>
using namespace std;
int test_1(const char * p) {
	return sizeof(p);
}
int test_2(const char p []) {
	return sizeof(p);
}
int test_3(string p) {
	return sizeof(p);
}
int main() {
	char * p_1 = "I love you.";
	char p_2 [] = "I hate you.";
	string p_3 = "I forgive you."; 
	
	cout << sizeof(p_1) << ends << sizeof(p_2) << ends << sizeof(p_3) << endl;

	cout << test_1(p_1) << ends << test_1(p_2) << endl;

	cout << test_2(p_1) << ends << test_2(p_2) << endl;

	cout << test_3(p_1) << ends << test_3(p_2) << ends << test_3(p_3) << endl;

	/*
	输出结果：
	8 12 8
	8 8
	8 8
	8 8 8
	分析：已知因为指针的存储类型是unsigned long int，故在32位系统上，sizeof(指针)=4；
	在64位系统上，sizeof(指针)=8。sizeof()的度量是字节。 
	上述结果表明：
	（1）char * p_1和string p_3中p_1和p_3均是指针，这里还不能说是什么类型的指针，但不是数组指针；
	char p_2 []中p_2是数组指针，和p_1与p_3是有区别的。这里sizeof(p_2)输出12个字节，11个字符所占，
	1个'\0'。 
	（2）当数组作为函数的参数进行传递时，数组就自动退化为同类型的指针。 
	*/
	return 0;
}
