//#include<string>

#include <iostream>
#include <string>
using namespace std;
int main() {
	//1.��ʼ��
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

	string str_2 = "I love you."; //��Ч�ڣ�string str_2("I love you.");
	string str_3 = str_2; //���ƣ���Ч�ڣ�string str_3(str_2);

	//2.���ú���
	string str_4 = str_3 + "Eileen Hong."; //����
	str_4 = str_3.append(str_3); //ͬ��

	str_4.size(); //�ַ�������
	str_4.length(); //ͬ�ϣ�ע�⣬���ַ�����str�����������

	str_4.find("u"); //����str_4�е�һ��u���±�

	str_4.compare(str_3); //0:str_4=str_3;��:str_4<str_3;��:str_4>str_3;

	//3.����
	for(int i=0 ; str_4[i] ; ++i)
		cout << str_4[i];
	cout << endl;

	for(int i=0 ; i < str_4.length() ; ++i) //��i<str_4.size();
		cout <<str_4[i];

	return 0;
}
