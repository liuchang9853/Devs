/*
map�ڲ���ʵ��ԭ���Ǻ��������ʵ�ְ�key���Զ�����
unordered_map�ڲ���ʵ��ԭ����hash��������ʱ�俪��Ϊo(1)�����������������˵
�����Լ������򣨱�������a,b,c�������a,b,c�������������������a,b,c����������c,b,a���� 
*/
#include <iostream>
#include <unordered_map> //���� map ����
using namespace std;
int main() {
	//��1����ʼ��
	unordered_map<char , int> um_1{{'a' , 1} , {'c' , 3} , {'b' , 2}}; 
	/*
	������ʾ��ǰum_1�е�˳����a,c,b����Ϊ���ǲ�֪���ڲ���hash���ƣ����Կ�����c,a,b��˳��
	ʵ���ϣ���hash���ƽ�����һϵ��unordered_����Ŀ�Ĳ������򣬶�����ʱ�俪���� 
	*/
	unordered_map<char , int> um_2(um_1);
	
	um_1.emplace('a' , 2); 
	//��2����ӣ���hash(key)ָ��ͬһ�ռ䣬���ÿռ�������val����ִ�и���䡣�ظ�ֵum_1['a'] = 2;  
	um_1.emplace('r' , 3);
	
	//��3������
	for(unordered_map<char , int>::iterator it = um_1.begin() ; it != um_1.end() ; ++it)
		cout << it->first << ends << it->second << endl;
		
	/*
	�����������У� 
	��4��um_1.empty()
	��5��um_1.size()
	��6��um_1.find(key) 
	��7��um_1.erase(key||um_1.find(key))
	��8��um_1.clear()
	��9��um_1.swap(um_2) 
	*/ 
	
	return 0;
}
