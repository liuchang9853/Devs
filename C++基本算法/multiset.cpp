/*
multisetλ��#include<set>�У��Ǻ�������ļ��ϡ� 
*/
#include <iostream>
#include <set>
using namespace std;
int main(){
	multiset<int> mul_1; //1.��ʼ��_1������ֵ 
	multiset<int> mul_2{1,2,2,3,3,3,4,4}; //��ʼ��_2����ֵ 
	multiset<int> mul_3(mul_2); //��ʼ��_3������multiset�ĸ��ƹ��캯��
	
	mul_1.insert(2);//2.����
	mul_1.insert(2);
	mul_1.insert(1);
	mul_1.insert(0);
	
	//3.������iterator�Ƕ�����multiset����static���ݳ�Ա 
	for(multiset<int>::iterator it = mul_1.begin() ; it != mul_1.end() ; ++it){
		cout << * it << ends; //���0122�������صĵ����� 
	} 
	
	if(!mul_1.empty()) mul_1.erase(mul_1.find(0)); //4.erase(ptr)ɾ��ָ��λ�õ�Ԫ�� 
	if(mul_1.size()) mul_1.erase(2); //erase(val)ɾ��ָ��ֵ��Ԫ�� 
	
	mul_1.swap(mul_2); //5.����
	
	mul_1.count(3); //6.count(val)����val�ĸ���
	
	mul_1.clear(); //7.��� 
}
