#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

template <class T>
int length(const T & arr) {
	return sizeof(arr)/sizeof(arr[0]);
}
int main() {
	//1.数组形式的string初始化，不用引入特殊头文件
	char str_1[3] = "st"; //若写为str[3] = "str";则错误，因为char数组要求最后一个元素为"\0"。
	char str_2[] = "I love you."; //不限长度
	char str_3[3];
	cin >> str_3;
	/*
	（1）
	若写成str_3="st"则出错。
	若输入字符>3则出错。
	（2）
	char str[4] = "str";
	cin >> str; //输入k
	cout << str; //输出k r。k与r之间的空格实际是\0。
	*/

	//2.string类型初始化，需引入头文件#include<string>
	string str_4 = "I love you.";
	
	//3.指针类型初始化。
	const char * str_5 = "I love you.";

	//4.获取长度
	str_4.length();
	str_4.size();
	/*
	#include<string>头文件下，string定义的字符串，
	其长度用length()、size()获取。
	*/

	length(str_2);
	/*
	无特殊头文件 或 #include<cstring>头文件下定义的字符串，
	其长度需自己定义长度函数获取。
	*/

	//5.字符串 和 char数组之间的转换 
	string str =  "1234";
	cout << atoi(str.c_str());
	/*
	（1） string->char[]
	#include<cstdlib>下：
	string.c_str()函数将字符串 转换为 char数组返回。
	 
	atoi(char数组)char数组转十进制数字，并去前导零0115->115。 
	（2）char[]->string
	string str = "";
	for(int i=0;char[i];++i) str += char[i];
	*/
	return 0;
}
