/*
��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
�������We%20are%20happy.����
��1����ͷ��β������һ���ո񣬽��ո��������ַ�����ƶ�2B���ڿճ�����3B������"%20"��
�÷���ʱ�临�Ӷ�ΪO(n^2)��
��2����β��ͷ�����ͷ��β����һ�α�����ɨ����ո�������������չ���ո��� ��2B ��С�Ŀռ䡣
��β��ͷ�����ַ�����ƶ��������ո������"20%"��ʱ�临�Ӷ�ΪO(n)��
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

void place(char * str,int slen) {
	int blankNum = 0;
	for (int i=0; i<slen; ++i)
		if(str[i]==' ') ++blankNum;
	
	char *newstr = new char[slen + blankNum * 2]; 
	
	for(int ptr = slen - 1 , newptr = slen + blankNum * 2 - 1; ptr >= 0; --ptr) {
	
		if(str[ptr] == ' ') {
			newstr[newptr--] = '0';
			newstr[newptr--] = '2';
			newstr[newptr--] = '%';
			
			--blankNum;
			continue;
		}
		newstr[newptr--] = str[ptr];
	}
	cout << newstr;
}
int main() {
	string str;
	getline(cin , str);
	
	char * arr = new char[str.size()+1];
	strcpy(arr,str.c_str());
	
	place(arr,str.size()+1);
	
	return 0;
}
/*
1.char * arr = new char[str.size()+1];���Ҫע��ĵ��ǣ�Ҫ��string��ֵ��һ��char[]��Ҫ�ǵ�
char[]�ĳ�����str.size()+'\0'��ռ��1��Ԫ��λ��
2.
string str;
getline(cin , str);
char * arr = new char[str.size()+1];
strcpy(arr,str.c_str());
place(arr,str.size()+1);
������
��1���� char * arr = new char[str.size()+1]; д�� char *arr; �����strcpy�ⲽ����
��������arr�Ŀռ�߽�û�б�ȷ����Ҫ��ס����ָ��ָ��Ŀռ�߽�û��ȷ�����򽫵���һϵ��
�޷�Ԥ�ϵ��ĺ��������ָ�룬һ��һ��Ҫ���������ȷ����ָ��Ŀռ�߽硣
��2��strcpy(char * , const char *);Ҫע��ڶ�����������д��string���͵Ĳ�����string����
C++���е����ͣ�string!=const char *�����磺
string str= "I love you.";
char * str= "I love you.";
const char * str = "I love you.";
���߶���ı���ֵ����ȣ���string_6��
���������𣬼�string_4��
������ص��ǣ�#include<cstring>��C�µ�ͷ�ļ����������Ľ�����(const)char *��char []����
���ַ���������#include<string>��һC++�µ�ͷ�ļ����轫���ж����string����ʹ��c_str()����
ת��ΪC�µ�const char *��ʹ�á�
��3����ʹ��char *str��ص��ַ���ʱ��Ҫ��ס��str �� strlenһ���ǡ�������Ϊ��������str
�ĵط���һ��ҲҪ��strlen����Ϊֻ��str�����޷���֪��߽�ġ� 
��4��
A. ���鳤�ȣ�
template <class T>
int length(const T & arr) {
	return sizeof(arr)/sizeof(arr[0]);
}

B. string str��str�ĳ��ȣ�
str.length() �� str.size()

C. char * ptr���ȣ�
string str="I love you.";
char * ptr = new char[str.length()+1];
strcpy(ptr,str.c_str());
fun(str.length()+1,ptr);
��
char arr[] = "I love you.";
char * ptr = new char[length(arr)];
for(int i=0;i<length(arr);++i) ptr[i] = arr[i];
fun(length(arr),ptr);
*/
