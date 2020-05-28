/*
��Ŀ������������ֻ����2,3,5�����֡�Ĭ��1���ǳ��������磺4=2 ��2��Ϊ������14=2 ��7��������7����Ϊ������
����ĵ�1500��������
��1������һ����һ�������жϣ�ֱ�����ֵ�1500���������������ǣ�ʱ�俪��̫����Ϊÿһ������Ҫ
�ж��Ƿ���һֱ��{2,3,5}֮һΪ���ӳ���ȥ������Ϊ0��
����
bool if_ugly(int num){
	while(num % 2 == 0) num /= 2;
	while(num % 3 == 0) num /= 3;
	while(num % 5 == 0) num /= 5;
	return (num == 1) ? true : false;
}
��2��Ҳ���Խ�һ��1500��Ԫ�ص����飬�Կռ任ʱ�䡣��Ϊÿһ����������֮ǰ��ĳ������ ��{2,3,5}��
�ʿ����ҳ��Ǹ����ӳ���������ң��Ǹ����ӳ������±����min(2*arr[j],3*arr[k],5*arr[z])�е�j��k��z�� 
*/
#include <iostream>
using namespace std;
int if_ugly(int num) {
	int * ugly = new int[num]();
	ugly[0] = 1;
	ugly[1] = 2;
	ugly[2] = 3;
	ugly[3] = 4;
	ugly[4] = 5;

	int ptr_2 = -1 , ptr_3 = -1 , ptr_5 = -1;
	for(int i = 5 ; i < num ; ++i) { //��ֵugly[i]
		int j = ptr_2 + 1;
		int k = ptr_3 + 1;
		int z = ptr_5 + 1;
		for( ; 2 * ugly[j] <= ugly[i - 1] ; ++j);
		for( ; 3 * ugly[k] <= ugly[i - 1] ; ++k);
		for( ; 5 * ugly[z] <= ugly[i - 1] ; ++z);

		struct find_min {
			int val;
			int index;
		} find_min_arr[3];

		find_min_arr[0].val = 2 * ugly[j];
		find_min_arr[0].index = 2;

		find_min_arr[1].val = 3 * ugly[k];
		find_min_arr[1].index = 3;

		find_min_arr[2].val = 5 * ugly[z];
		find_min_arr[2].index = 5;

		for(int m = 0 ; m < 2 ; ++m) {
			if(find_min_arr[m].val < find_min_arr[m + 1].val) {
				find_min temp = find_min_arr[m];
				find_min_arr[m] = find_min_arr[m + 1];
				find_min_arr[m + 1] = temp;
			}
		}

		ugly[i] = find_min_arr[2].val;

		if(find_min_arr[2].index == 2) ptr_2 = j;
		else ptr_2 = j - 1;
		if(find_min_arr[2].index == 3) ptr_3 = k;
		else ptr_3 = k - 1;
		if(find_min_arr[2].index == 5) ptr_5 = z;
		else ptr_5 = z - 1;
	}

	return ugly[num - 1];
}
int main() {
	cout << if_ugly(1500);
	return 0;
}
