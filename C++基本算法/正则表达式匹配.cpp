/*
��Ŀ����ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ���
�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬����"aa.a"��"ab*a"����ƥ�䡣
*/
#include <iostream>
using namespace std;
bool match(char patternArr[] , char charArr[]) {
	int i = 0 , j = 0;
	while(patternArr[i] != '\0' && charArr[j] != '\0') {
		if((charArr[j] == patternArr[i] || patternArr[i] == '.') && patternArr[i + 1] == '*') {
			//���� 'ch_1','*' not match 'ch_2','*' ��Ӧ�� '.','*'��
			char ch = charArr[j];

			for( ; charArr[j + 1] == ch ; ++j);

			i += 2; //ʹ���� 'ch','*' ����������
			j += 1;

			continue; //Ӧ�� 'ch_1','*','ch_2','*'��
		}

		if(patternArr[i] == '.') {
			++i;
			++j;

			continue; //Ӧ�� '.','ch','*'
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
	char charArr_1[] = {'a','a','z','b','b','b','c','g','k','d','e','\0'}; //ƥ��
	char charArr_2[] = {'a','a','z','b','b','c','c','g','k','d','e','\0'}; //��ƥ��

	match(patternArr , charArr_1) == true ? cout << "charArr_1 matches patternArr" : cout << "charArr_1 doesn't match patternArr." ;
	cout << endl;
	match(patternArr , charArr_2) == true ? cout << "charArr_2 matches patternArr" : cout << "charArr_2 doesn't match patternArr." ;

	return 0;
}
