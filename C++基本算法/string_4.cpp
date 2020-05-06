#include <iostream>
#include <string>
using namespace std;
void test_1(const char * p){
	cout << p << endl;
}
void test_2(const char p []){
	cout << p << endl;
}
void test_3(string p){
	cout << p << endl;
}
int main(){
	//3中字符串初始化形式： 
	char * p_1 = "I love you."; //警告 
	char p_2 [] = "I hate you";
	string p_3 = "I forgive you";
	
	//测试类型兼容性
	test_1(p_1);
	test_1(p_2);
	/*
	test_1(p_3);错误 
	*/
	
	test_2(p_1);
	test_2(p_2);
	/*
	test_2(p_3);错误 
	*/
	
	test_3(p_1);
	test_3(p_2);
	test_3(p_3);
		
	return 0;
}
