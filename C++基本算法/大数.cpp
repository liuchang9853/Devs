/*
题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
打印出1、2、3、4、5一直到最大的3位数即999。
*/ 
#include <iostream>
using namespace std;
struct bigData {
	int * numArr;
	int numLen;
	int index;
};
void with_carry(bigData &data , int carry) {
	data.numArr[data.index] += carry;
	if(data.numArr[data.index] == 10) {
		data.numArr[data.index] = 0;
		
		data.index -= 1;
		with_carry(data , 1);
		data.index += 1;
	}
}
void print_1_to_max(int n) {
	//大数初始化
	bigData data;
	data.numArr = new int[n + 1](); //numArr[0]用于存放最高位进位以判断是否输出完毕。这是哨兵。 
	data.numLen = n;
	data.index = n;

	//大数按序输出 
	for(int i = 0 ; i < 10 && data.numArr[0] == 0 ; ++i) {
		//i：0~9 对应 data.numArr[data.index]：1~10 
		++data.numArr[data.index];

		//有进位，先进位
		if(data.numArr[data.index] == 10) {
			data.numArr[data.index] = 0;

			//递归特色夹心饼干
			data.index -= 1;
			with_carry(data , 1);
			data.index += 1;
			
			//每进完一次位，要置for循环重新开始。 
			i = -1;
		}

		//打印
		if(data.numArr[0] == 0) {
			int j = 0;
			for( ; data.numArr[j] == 0 ; ++j);
			for( ; j <= data.numLen ; ++j) cout << data.numArr[j];
			cout << ends;
		}
	}
}
int main() {
	int n;
	cin >> n;
	print_1_to_max(n);
	return 0;
}
