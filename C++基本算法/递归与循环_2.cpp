/*
��Ŀ������һ���ַ�������ӡ�����ַ������ַ����������С����������ַ���abc��
���ӡ�����ַ�a��b��c�������г����������ַ���abc��acb��bac��bca��cab��cba��
��1����nλ����Ϊ1��n-1���̶���һλ��ȫ���к�n-1λ��
��2���Ժ�n-1λ��Ҳ����Ϊ1��n-2��ȫ���к�n-2λ���ݹ顣
*/
#include <iostream>
using namespace std;
void permutations(char str_change [] , int start , int strLen) {
	if(strLen == 0) return;

	for(int i = start ; i < strLen ; ++i) {
		//������ͷ 
		char * str_change_fixed = new char[strLen];
		for(int i = 0 ; i < strLen ; ++i) str_change_fixed[i] = str_change[i];
		
		//�̶���Ԫ
		char ch = str_change[i];
		str_change[i] = str_change[start];
		str_change[start] = ch;
		
		//�ݹ�
		permutations(str_change , start + 1 , strLen);
		
		//������β 
		for(int i = 0 ; i < strLen ; ++i) str_change[i] = str_change_fixed[i];
		
		/*
		��������������ѵĲ��֣�ԭ������֮ǰû�и����һ�����⣺����ʲôʱ��ʲô�����
		������������Σ����ﶨ�����£���Ϊ�˸��ݹ���ô��ݹ�ϵ���ı�ĳЩ����ʱ����Ҫ����
		�Ƿ�Ҫ����Щ���ݺ͵ݹ�������˹���һ�������Σ��Ա�֤��Щ���ݿ��Բ���ĳ�εݹ��Ӱ
		�죬������ĳ�εݹ��Ӱ����ѭ���׵ݹ�ṹ���Ļ���Ҫ��
		��Ȼ��Ҳ�п��ܳ�����tree_11������������Ҫ�󣬼���Ҫ�ݹ�ı�����ݡ���Ͳ���Ҫ����
		���ˣ���Ҫʹ��&��ָ�������Ρ� 
		*/ 
	}

	if(start == strLen) {
		for(int i = 0 ; i < strLen ; ++i) cout << str_change[i] << ends;
		cout << endl;
	}
}

void start_permutations(char str [] , int strLen) {
	char * str_change = new char[strLen];
	for(int i = 0 ; i < strLen ; ++i) str_change[i] = str[i];
	permutations(str_change , 0 , strLen);
	delete str_change;
	/*
	������������Ҫ�ԣ�
	1.����������main�����е��õݹ����ʱ�Ĳ������롣���main��ֻҪ���������������ݹ���
	Ҫ����4��������
	2.��������������Դ�ʹ���ǲ���������˼�����ݹ�����Ҫʲô������Ҫ�������������ÿ
	�ݹ�һ�ξͱ仯�ģ����ǳ־ò���ģ����仯������ô�仯�ģ��ȵȡ�
	*/
}

int main() {
	char str [] = {'a','b','c','d'};
	start_permutations(str , 4);
	return 0;
}
