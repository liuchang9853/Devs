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
	��������
	8 12 8
	8 8
	8 8
	8 8 8
	��������֪��Ϊָ��Ĵ洢������unsigned long int������32λϵͳ�ϣ�sizeof(ָ��)=4��
	��64λϵͳ�ϣ�sizeof(ָ��)=8��sizeof()�Ķ������ֽڡ� 
	�������������
	��1��char * p_1��string p_3��p_1��p_3����ָ�룬���ﻹ����˵��ʲô���͵�ָ�룬����������ָ�룻
	char p_2 []��p_2������ָ�룬��p_1��p_3��������ġ�����sizeof(p_2)���12���ֽڣ�11���ַ���ռ��
	1��'\0'�� 
	��2����������Ϊ�����Ĳ������д���ʱ��������Զ��˻�Ϊͬ���͵�ָ�롣 
	*/
	return 0;
}
