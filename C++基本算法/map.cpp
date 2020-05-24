/*
map�ڲ�ʹ�ú����ʵ�ֵģ��ڽ���ӳ��Ĺ����л�ʵ�ְ�keyֵ��С���Զ�����
map����ʵ�������ͼ��ӳ�䡣 
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	map<char , int> mp1; //��1��ʵ��char(key)->int(value)��ӳ��
	map<string , int> mp2;
	for (int i = 0 ; i < 5 ; ++i) {
		mp1[char(90 - i)] = i; //������ʽ��ֵ��z~v ӳ��Ϊ 0~4
		
		string str;
		str.push_back(char(122 - i)); //ע��char��ҪתΪstring��������string str = char(i)����ֻ����str.push_back()���� 
		str.push_back(char(90 - i));
		mp2[str] = i;
		
		/*
		mp1�������Z 0 -> V 4������V 4 -> Z 0
		mp2�������zZ 0 -> vV 4������vV 4 -> zZ
		��char��string��ʵ���˰�keyֵ��С���Զ����� 
		*/
	}
	
	for (map<char , int>::iterator it = mp1.begin() ; it != mp1.end() ; ++it) {
		cout << it->first << ends << it->second <<endl;
		//��2��������it->firstΪkey�� it->secondΪvalue
	}
	
	for (map<string , int>::iterator it = mp2.begin() ; it != mp2.end() ; ++it) {
		cout << it->first << ends << it->second <<endl;
	}

	mp2.erase(mp2.find("wW")); //��3�������erase(ptr)��find(key)��begin()��end()�������ʹ��
	mp2.erase("vV"); //�������erase(key) 
	for (map<string , int>::iterator it = mp2.begin() ; it != mp2.end() ; ++it) {
		cout << it->first << ends << it->second <<endl;
	}
	
	mp2.clear(); //��4�����map 
	cout << mp2.size(); //��5��map��С 

	return 0;
}

