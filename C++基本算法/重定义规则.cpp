/*
��Ŀ������һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ
�ӳ���������������С��һ����������������{3, 32, 321}�����ӡ����3����
�����ųɵ���С����321323��
�������ض�����򣬼��ض���һ�ֱȴ�С�Ĺ����������к���k,m,n��Ԫ�أ���
km>mk�������m����mn>nm�������n��-> nӦ�ŵ����λ��
km>mk�������m��-> m�ŵ��θ�λ ��
k�ŵ����λ��

�ڶ���Ӧע����ǣ�k��m��n����int����km��mn����Ͽ�����һ����������Ͳ����ٰ�int�洢�����ˣ�
��Ҫ��km��mn����ϴ洢Ϊstring����string��������km��mk��Ĵ�С��ϵ����ȫ�������ַ�����С��
��������
*/
#include <iostream>
#include <stdlib.h> //�ṩvoid qsort(void *arrPtr,arrLen,sizeof(arrElem),int (*cmp)(const void *,const void *)); 
#include <string> //�����ṩto_string();
using namespace std;

int cmp(const void * a , const void * b) {
	//ǿ������ת��Ϊ���֣�����ת�ַ���
	string arg1 = to_string(* (const int *) a);
	string arg2 = to_string(* (const int *) b);

	string mn = arg1 + arg2;
	string nm = arg2 + arg1;

	//cmp����1�����򣻷���-1��������mn.compare(nm) > 0����m>n����֮m<=n��
	if(mn.compare(nm) >= 0) return 1;
	else return -1;
}

string min_reg(int arr[] , int length) {
	qsort(arr,length,sizeof(int),cmp); //ע����cmpû������
	string str = "";
	for(int i = 0 ; i < length ; ++i) str += to_string(arr[i]);
	return str;
}

int main() {
	int arr_1[] = {3, 32, 321};
	string str_1 = min_reg(arr_1 , 3);

	int arr_2[] = {3, 5, 1, 4, 2};
	string str_2 = min_reg(arr_2 , 5);

	int arr_3[] = {3, 323, 32123};
	string str_3 = min_reg(arr_3 , 3);

	int arr_4[] = {1, 11, 111};
	string str_4 = min_reg(arr_4 , 3);

	cout << str_1 << endl << str_2 << endl << str_3 << endl << str_4 << endl;
	return 0;
}
/*
������ص�������qsort()��qsort()���ص�����cmp����ơ�
*/
