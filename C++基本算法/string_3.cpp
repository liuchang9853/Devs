#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

template <class T>
int length(const T & arr) {
	return sizeof(arr)/sizeof(arr[0]);
}
int main() {
	//1.������ʽ��string��ʼ����������������ͷ�ļ�
	char str_1[3] = "st"; //��дΪstr[3] = "str";�������Ϊchar����Ҫ�����һ��Ԫ��Ϊ"\0"��
	char str_2[] = "I love you."; //���޳���
	char str_3[3];
	cin >> str_3;
	/*
	��1��
	��д��str_3="st"�����
	�������ַ�>3�����
	��2��
	char str[4] = "str";
	cin >> str; //����k
	cout << str; //���k r��k��r֮��Ŀո�ʵ����\0��
	*/

	//2.string���ͳ�ʼ����������ͷ�ļ�#include<string>
	string str_4 = "I love you.";
	
	//3.ָ�����ͳ�ʼ����
	const char * str_5 = "I love you.";

	//4.��ȡ����
	str_4.length();
	str_4.size();
	/*
	#include<string>ͷ�ļ��£�string������ַ�����
	�䳤����length()��size()��ȡ��
	*/

	length(str_2);
	/*
	������ͷ�ļ� �� #include<cstring>ͷ�ļ��¶�����ַ�����
	�䳤�����Լ����峤�Ⱥ�����ȡ��
	*/

	//5.�ַ��� �� char����֮���ת�� 
	string str =  "1234";
	cout << atoi(str.c_str());
	/*
	��1�� string->char[]
	#include<cstdlib>
	#include<cstring>
	#include<string>
	
	string str="I love you.";
	char * ch = new char[str.size()+1];
	strcpy(ch,str.c_str);
	
	�����͵õ�������ch[]��������str.size()+1�� 
	 
	��2��char[]->string
	string str = "";
	for(int i=0;char[i];++i) str += char[i];
	
	��3��
	int atoi(const char* str)��strתʮ�������֣���ȥǰ����0115->115��
	
	const char *c_str()��c_str()��������һ��ָ������C�ַ�����ָ�볣��, 
	�����뱾string����ͬ������Ϊ����c���Լ��ݣ���c������û��string���ͣ�
	�ʱ���ͨ��string�����ĳ�Ա����c_str()��string ����ת����c�е��ַ�����ʽ�� 
	*/
	return 0;
}
