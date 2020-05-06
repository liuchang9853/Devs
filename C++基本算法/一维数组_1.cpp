/*
��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�
����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�
���磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}����ô��Ӧ��������ظ�������2����3��
��1���������ҡ�ʱ�临�Ӷȣ�O(nlogn)��
��2������Hash��ʱ�临�Ӷȣ�O(n)���ռ临�Ӷȣ�O(n)��
��3��ԭ��Hash��ʱ�临�Ӷȣ�O(n)���ռ临�Ӷȣ�O(1)��
���÷���3����
*/
#include <iostream>
using namespace std;
bool duplicate(int numbers[], int length, int* duplication) {
	if(numbers == nullptr || length <= 0)
		return false;

	for(int i = 0; i < length; ++i) {
		if(numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	for(int i = 0; i < length; ++i) {
		while(numbers[i] != i) {
			if(numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				return true;
			}

			// ����numbers[i]��numbers[numbers[i]]
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	
	return false;
}
/*
�ô���Ĵ���֮�����ڣ�ͨ��return��һ��ͳ��ʽ �� int* duplication��ʽʵ�����򱻵�����
�Ĵ�ֵ��������main()�е���duplicate(int numbers[], int length, int* duplication)����
�䴫�ݵĵ�����ʵ������main()�ж����ָ��һint�ڴ�ĵ�ַ��duplicate()�������н�����
return bool���޸��˸��ڴ��е�intֵ��������duplicationָ�룬�����ո�int�ڴ档 
*/
template <class T>
int length(const T & arr) {
	return sizeof(arr)/sizeof(arr[0]);
}
int main() {
	int numbers [] = {2, 3, 1, 0, 2, 5, 3};
	int len = length(numbers);
	int * duplication = new int;
	cout << duplicate(numbers , len , duplication) << endl;
	cout << * duplication << endl;
	/*
	�����
	1
	2 
	*/ 
	for (int i=0;i<len;++i) cout << numbers[i];
	/*
	�����
	0123253 
	�ɴ˿������ռ临�Ӷȣ�O(1)��û�п����µĿռ䡣
	*/ 
	return 0;
}
