/*
题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
字能排成的最小数字321323。
分析：重定义规则，即重定义一种比大小的规则，设数组中含有k,m,n三元素，若
km>mk，则输出m；若mn>nm，则输出n；-> n应放到最高位。
km>mk，则输出m；-> m放到次高位 。
k放到最低位。

第二点应注意的是，k、m、n都是int，但km、mn等组合可能是一个大数，这就不能再按int存储计算了，
故要把km、mn等组合存储为string，按string操作。而km和mk间的大小关系，完全可以用字符串大小来
来衡量。
*/
#include <iostream>
#include <stdlib.h> //提供void qsort(void *arrPtr,arrLen,sizeof(arrElem),int (*cmp)(const void *,const void *)); 
#include <string> //用于提供to_string();
using namespace std;

int cmp(const void * a , const void * b) {
	//强制类型转换为数字，数字转字符串
	string arg1 = to_string(* (const int *) a);
	string arg2 = to_string(* (const int *) b);

	string mn = arg1 + arg2;
	string nm = arg2 + arg1;

	//cmp返回1，则降序；返回-1，则升序。mn.compare(nm) > 0，即m>n；反之m<=n。
	if(mn.compare(nm) >= 0) return 1;
	else return -1;
}

string min_reg(int arr[] , int length) {
	qsort(arr,length,sizeof(int),cmp); //注意是cmp没有括号
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
本题的重点所在是qsort()。qsort()的重点在于cmp的设计。
*/
