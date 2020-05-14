/*
题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。
*/
#include <iostream>
using namespace std;
bool match(char patternArr[] , char charArr[]) {
	int i = 0 , j = 0;
	while(patternArr[i] != '\0' && charArr[j] != '\0') {
		if((charArr[j] == patternArr[i] || patternArr[i] == '.') && patternArr[i + 1] == '*') {
			//避免 'ch_1','*' not match 'ch_2','*' ；应对 '.','*'。
			char ch = charArr[j];

			for( ; charArr[j + 1] == ch ; ++j);

			i += 2; //使用完 'ch','*' ，故跳过。
			j += 1;

			continue; //应对 'ch_1','*','ch_2','*'。
		}

		if(patternArr[i] == '.') {
			++i;
			++j;

			continue; //应对 '.','ch','*'
		}

		if(charArr[j] != patternArr[i]) return false;
		else {
			++i;
			++j;
		}
	}
	if(patternArr[i] == '\0' && charArr[j] == '\0') return true;
	else return false;
}
int main() {
	char patternArr[] = {'a','a','.','b','*','c','.','.','d','*','e','\0'};
	char charArr_1[] = {'a','a','z','b','b','b','c','g','k','d','e','\0'}; //匹配
	char charArr_2[] = {'a','a','z','b','b','c','c','g','k','d','e','\0'}; //不匹配

	match(patternArr , charArr_1) == true ? cout << "charArr_1 matches patternArr" : cout << "charArr_1 doesn't match patternArr." ;
	cout << endl;
	match(patternArr , charArr_2) == true ? cout << "charArr_2 matches patternArr" : cout << "charArr_2 doesn't match patternArr." ;

	return 0;
}
