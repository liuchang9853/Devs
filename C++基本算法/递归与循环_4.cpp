/*
��Ŀ������һ�����֣����ǰ������¹����������Ϊ�ַ�����0�����"a"��1��
���"b"��������11�����"l"��������25�����"z"��һ�����ֿ����ж�����롣
����12258��5�ֲ�ͬ�ķ��룬���Ƿֱ���"bccfi"��"bwfi"��"bczi"��"mcfi"��
"mzi"������ʵ��һ��������������һ�������ж����ֲ�ͬ�ķ��뷽����
������
���͵Ļ����������⡣
5�����֣�ȫ��1λ�����ɵõ�1�ַ��뷽ʽ��++count�� 
���ô���Ϊ2�������ڴ�ͷ��ʼ����������ֵ�������10С��25�ģ��ɵ�һ�ַ��뷽ʽ��++count��
���ڴ�ͷ��ʼ�����������Ӵ��ڵݹ顣 
*/
#include <iostream>
#include <string>
using namespace std;

//�ݹ����
int translation(string num , int start) {
	int count = 0;
	for(int i = start ; i + 1 <= num.length() - 1 ; ++i)
		if(num.substr(i,2).compare("10") >= 0 && num.substr(i,2).compare("25") <= 0)
			++count;
	for(int i = start ; i + 1 <= num.length() - 3 ; ++i)
		if(num.substr(i,2).compare("10") >= 0 && num.substr(i,2).compare("25") <= 0)
			count += translation(num , i + 2);
	return count;
}

//��������
int num_translator(string num) {
	for(int i = 0 ; i < num.length() ; ++i)
		if(int(num[i]) < 48 || int(num[i]) > 57) return 0;
	return translation(num , 0) + 1;
	/*
	1��ʾnumȫ��1Ԫ�黮��ʱ��һ�ַ�������
	num.length - (count - 1) * 2 - 1��2Ԫ�����Ԫ���ڻ���ֹͣ�±ꡣ���統������2Ԫ��ʱ��
	��Ԫ�����»���5-2-1=2��ֹͣ������
	*/
}

int main() {
	string num = "12222";
	cout << num_translator(num);
	return 0;
}
