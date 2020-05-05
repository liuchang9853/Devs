//#include<string>

#include <iostream>
#include <string>
using namespace std;
int main(){
	string str_1;
	cin >> str_1; //I love you.
	cout << str_1; //I
	/*
	cin不接受空格和换行
	*/ 
	
	getline(cin , str_1); //I love you.
	cout << str_1; //I love you.
	/*
	getline()接受含空格的字符串
	或
	一个空格，此时等同于getchar()，用途：
	string input , enter;
	getline(cin , enter);
	getline(cin , input);
	*/ 
	
	string str_2 = "I love you.";
	string str_3 = str_2; //复制 
	
	string str_3 = str_2 + "Eileen Hong."; //连接 
	
	string str_3.size(); //字符串长度 
	
	return 0;
}
