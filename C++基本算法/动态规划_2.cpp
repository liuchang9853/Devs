/*
��Ŀ������ַ������ҳ�һ����Ĳ������ظ��ַ������ַ��������������ַ����ĳ��ȡ�
�����ַ�����ֻ������'a'��'z'���ַ���
f(i)=
f(i-1)+1����a[i]������f(i-1)�С�
i-�ϴ�a[i]���ֵ�λ�ã���a[i]����f(i-1)�С�
����hash[26]�����ڴ����ĸ��һ�γ��ֵ�λ�á�
*/
#include <iostream>
#include <string>
using namespace std;

string find_substr(string str) {
	int * hash = new int [26];
	string subStr = "";
	string maxSubStr = "";

	for(int i = 0 ; i < 26 ; ++i) hash[i] = -1;

	for(int i = 0 ; i < str.length() ; ++i) {
		if(hash[int(str[i]) - 97] < 0) {
			subStr += str[i];
		} else {
			int subLen = subStr.length();
			subStr = str.substr(hash[int(str[i]) - 97] + 1 , i - hash[int(str[i]) - 97]);
			for(int j = hash[int(str[i]) - 97] ; j >= i - subLen ; --j) hash[int(str[j]) - 97] = -1;
		}
		hash[int(str[i]) - 97] = i;
		if(subStr.length() >= maxSubStr.length()) maxSubStr = subStr;
	}
	return maxSubStr;
}
int main() {
	string str = "arabcaacfr";
	string maxSubStr = find_substr(str);
	cout << maxSubStr << ends << maxSubStr.length();
	return 0;
}
