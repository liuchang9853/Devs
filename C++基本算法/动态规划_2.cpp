/*
题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
假设字符串中只包含从'a'到'z'的字符。
f(i)=
f(i-1)+1：当a[i]不处于f(i-1)中。
i-上次a[i]出现的位置：当a[i]处于f(i-1)中。
设置hash[26]，用于存放字母上一次出现的位置。
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
