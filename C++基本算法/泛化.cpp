/*
��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ������
����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
*/
#include <iostream>
using namespace std;

bool reg(int * arr , int * ptr) {
	if(* ptr % 2 == 1) return true;
	else return false;
	return true;
}

template <class T> //��������˴���������� 
void list_with_double_ptr(T * arr , int length) {
	T * ptr_start = &arr[0];
	T * ptr_end = &arr[length - 1];

	while(ptr_start != ptr_end) { 
		for( ; ptr_start != ptr_end && reg(arr , ptr_start) ; ++ptr_start);
		if(ptr_start == ptr_end) return;
		else {
			T space = * ptr_end;
			* ptr_end = * ptr_start;
			* ptr_start = space;
		}

		for( ; ptr_end != ptr_start && !reg(arr , ptr_end) ; --ptr_end);
		if(ptr_start == ptr_end) return;
		else {
			T space = * ptr_start;
			* ptr_start = * ptr_end;
			*ptr_end = space;
		}
	}
	/*
	reg()ʹ����δ���Ĺ���Ҳ�Ƿ����ģ����������Ϊ�ܱ�3������ǰ�����ܱ�3�����ں�
	���߸�����ǰ�������ں����޸�reg()���ɡ� 
	*/
}

int main() {
	int arr[7] = {1,4,55,2,3,4,7};
	list_with_double_ptr(arr , 7);
	for(int i = 0 ; i < 7 ; ++i) cout << arr[i] << ends;
	return 0;
}
