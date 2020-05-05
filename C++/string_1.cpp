//#include<string>

#include <iostream>
#include <string>
using namespace std;
int main() {
	//1.初始化
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

	string str_2 = "I love you."; //等效于：string str_2("I love you.");
	string str_3 = str_2; //复制，等效于：string str_3(str_2);

	//2.常用函数
	string str_4 = str_3 + "Eileen Hong."; //连接
	str_4 = str_3.append(str_3); //同上

	str_4.size(); //字符串长度
	str_4.length(); //同上，注意，两种方法若str含汉字则出错

	str_4.find("u"); //返回str_4中第一个u的下标

	str_4.compare(str_3); //0:str_4=str_3;负:str_4<str_3;正:str_4>str_3;

	//3.遍历
	for(int i=0 ; str_4[i] ; ++i)
		cout << str_4[i];
	cout << endl;

	for(int i=0 ; i < str_4.length() ; ++i) //或i<str_4.size();
		cout <<str_4[i];

	return 0;
}
