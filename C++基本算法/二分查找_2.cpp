/*
��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ����������������һ����ת�������ת�������СԪ�ء�
��������{3, 4, 5, 1, 2}Ϊ{1, 2, 3, 4, 5}��һ����ת�����������СֵΪ1��
������
��Ϊ�������������飬�����ö��ֲ��ҷ���
���ֲ��ҷ���ע����low,high,mid��
���ڴˣ��м��������
{2,3,4,5,6} ��0�������У�Ԫ�ذᵽ�����ĩβ�������׺��ԣ�
{4,5,6,2,3} �����ɸ�Ԫ�ذᵽ����ĩβ��
{1,1,0,1,1,1,1}�������������������ױ����Ե��������ĺ�������ͬԪ��ֵ�����顣
*/
#include <iostream>
using namespace std;
int binSearch(const int *Array , int start , int end) {
	int low = start,high = end;
	int mid = low + (high - low) / 2;
	
	if(Array[low] < Array[high]) return low; //{2,3,4,5,6}
	else if(Array[low] == Array[mid] == Array[high]) { //{1,1,0,1,1,1,1}
		//ע��bool == bool == boolҲ����ȷ�ġ� 
		for(; Array[low] == Array[high] && low != high; ++low);
		return low;
	}
	else { //{4,5,6,2,3}��{5,6,2,3,4}
		while(low < high - 1) {
			if(Array[mid] < Array[low] || Array[mid] < Array[high]) high = mid;
			if(Array[mid] > Array[low] || Array[mid] > Array[high]) low = mid;
			mid = low + (high - low) / 2;
		}
		return Array[low] < Array[high] ? low : high;
	}
}
int main() {
	int arr_1 [] = {2,3,4,5,6};
	int arr_2 [] = {1,1,0,1,1,1,1};
	int arr_3 [] = {5,6,2,3,4};
	cout << binSearch(arr_1,0,4) << ends;
	cout << binSearch(arr_2,0,6) << ends;
	cout << binSearch(arr_3,0,4);
	return 0;
}
