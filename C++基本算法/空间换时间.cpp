/*
题目：丑数是因数只包含2,3,5的数字。默认1就是丑数。例如：4=2 ×2，为丑数；14=2 ×7，含因数7，不为丑数。
求按序的第1500个丑数。
（1）可以一个数一个数的判断，直到出现第1500个丑数，但问题是，时间开销太大。因为每一个数都要
判断是否能一直以{2,3,5}之一为因子除下去且余数为0。
即：
bool if_ugly(int num){
	while(num % 2 == 0) num /= 2;
	while(num % 3 == 0) num /= 3;
	while(num % 5 == 0) num /= 5;
	return (num == 1) ? true : false;
}
（2）也可以建一个1500个元素的数组，以空间换时间。因为每一个丑数都是之前的某个丑数 ×{2,3,5}。
故可以找出那个因子丑数。如何找？那个因子丑数的下标就是min(2*arr[j],3*arr[k],5*arr[z])中的j或k、z。 
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
	for(int i = 5 ; i < num ; ++i) { //赋值ugly[i]
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
