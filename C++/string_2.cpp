//#include<cstring>

#include <iostream>
#include <cstring>
using namespace std;
int main () {
	char str1[11] = "Hello";
	char str2[11] = "World";
	char str3[11];
	int len;

	//���� str1 �� str3 �� ����str3�� 
	strcpy( str3, str1);
	cout << "strcpy(str3 , str1) : " << str3 << endl;

	char s [ ] = "abcdefgh" , *p = s;
	p += 3;
	printf("%d\n" , strlen(strcpy(p , "ABCD"))); //���ƺ󣬷���p�����4
	/*
	strcpy������֮���ַ���ΪabcABCD������pָ���λ����A��
	���Լ��㳤�ȵ�ʱ��ǰ�����������������С�
	*/

	//���� str1 �� str2
	strcat(str1 , str2);
	cout << "strcat(str1 , str2) : " << str1 << endl;

	//���Ӻ�str1 ���ܳ���
	len = strlen(str1);
	cout << " strlen(str1) : " << len << endl;
	
	//�Ƚϣ���str1=str2��i=0����str1<str2��i<0����str1>str2��i>0�� 
	int i = strcmp(str1 , str2);
	cout << i;
	
	return 0;
}
