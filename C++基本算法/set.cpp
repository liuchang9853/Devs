/*
set��һ���ڲ������ظ�Ԫ�����Զ�����ļ��ϡ�
set�ڲ�ʹ�ú����ʵ�ֵģ��ڽ���ӳ��Ĺ����л��Զ�ʵ������ 
*/
#include <iostream>
#include <set>
using namespace std;
int main(){
	set<int> st; //1.set�ĳ�ʼ��
	
	for(int i = 0 ; i < 5 ; ++i) { //2.set�Ĳ��� 
		st.insert((4 - i) % 3); //���뺬������1,0,2,1,0
	}
	
	for(set<int>::iterator it = st.begin() ; it != st.end() ; ++it) { //3.set�ı�����ֻ����iterator 
		cout << * it << ends; //���0,1,2��ʵ��ȥ�غ���Զ����� 
	}
	cout << endl;
	
	set<int>::iterator it = st.find(2); //4.find(v)����v�ĵ�ַ 
	cout << * it << endl;
	
	st.erase(st.find(2)); //5.���ָ��Ԫ�أ�erase(ptr)��find(val)��begin()��end()���ʹ��
	
	st.clear(); //6.ȫ�����
	
	cout << st.size(); //7.set���� 
	 
	return 0;
} 
