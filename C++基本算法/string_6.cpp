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
	��������
	str_1!=str_2
	str_3=str_4
	str_5=str_6
	str_3=str_5
	ԭ��C/C++���ַ��������ŵ�һ���������ڴ����򣬵��ַ�����ֵ��char * �� string��ָ������
	�ı���ʱ����Щָ���ָ����ڴ����򣬼���ָ��ͬһ���ڴ�����
	����ֵ���������͵ı�����ͬ����������Ϊ������Կ��ٿռ䣬��char����Ԫ�����ַ���Ԫ�أ���
	һ���������顣 
	*/
	
	/*
	* str_3 = "I hate you.";������д���Ǵ���ġ�str_3���Ա����¸�ֵ������ָ���������const��
	
	��ͬ�ڣ�
	int i = 0;
	int * ptr = &i;
	* ptr = 1;
	���ǳ����ġ� 
	*/  
	return 0;
}
