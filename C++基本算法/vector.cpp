#include <iostream>
#include <vector>
using namespace std;

void test(vector<int> &a) {}

int main() {
	int len;
	cin >> len;
	vector<int> a(len); //��1����ʼ��_1��vector<ElemTypr> arr(length)
	vector<int> b; //��ʼ��_2��vector<ElemTypr> arr
	vector< vector<int> > c; //��ʼ��_3�������ڶ�ά���飬�����г����ɱ�(һ�㲻��)

	test(a); //��2����������

	a.size(); //��3��arr.size()����̬����arr�ĳ��� 

	for(int i = 0 ; i < a.size() ; ++i) a[i] = 0; //��4������a

	for (int i = 0 ; i < len ; ++i) b.push_back(i); //��5��arr.push_back(v)ָ��bβ��v

	for (vector<int>::iterator it = b.begin() ; it != b.end(); ++it) {
		cout << * it << ends;
		/*
		��6�� 
		iterator��ָ�����ͣ�������*�ĺ��壩���ɼ�iterator��vector<class T>class�е�static��Ա�� 
		arr.begin()����arr��Ԫ��ַ
		arr.end()����arrĩԪ����һ����ַ������ҿ�
		*/
	}

	b.pop_back();//��7��arr.pop_back()ɾ��arrβ��Ԫ��
	
	b.insert(b.begin() + 1 , 9); //��8��arr.insert(start_addr,value)������ 
	
	b.erase(b.begin() , b.begin() + 2); //��9��ɾ��b[0,1]����[first,last)
	
	b.clear();//��10��arr.clear()�����arr
	 
	return 0;
}
/*
��11�� 
vector<char> ch[len] �� vector<char> ch(len) �Ĳ��
ǰ�߶�����һ��ch���飬ÿһԪ��Ϊһ��vector�ɱ����顣
���߶�����һ����Ϊlen��vector�ɱ䳤���顣
*/
