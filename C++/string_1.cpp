//#include<string>

#include <iostream>
#include <string>
using namespace std;
int main(){
	string str_1;
	cin >> str_1; //I love you.
	cout << str_1; //I
	/*
	cin�����ܿո�ͻ���
	*/ 
	
	getline(cin , str_1); //I love you.
	cout << str_1; //I love you.
	/*
	getline()���ܺ��ո���ַ���
	��
	һ���ո񣬴�ʱ��ͬ��getchar()����;��
	string input , enter;
	getline(cin , enter);
	getline(cin , input);
	*/ 
	
	string str_2 = "I love you.";
	string str_3 = str_2; //���� 
	
	string str_3 = str_2 + "Eileen Hong."; //���� 
	
	string str_3.size(); //�ַ������� 
	
	return 0;
}
