/*
题目：输入一个含有8个数字的数组，判断有没有可能把这8个数字分别放到正方体的8个顶点上，
使得正方体上三组相对的面上的4个顶点的和都相等。
解法：画出图后，其实质就是在vex全排列中选择符合条件的排列。 
*/
#include <iostream>
using namespace std;
void square(int * vexArr , int vexArrLen , int start) {
	for(int i = start ; i < vexArrLen ; ++i) {
		int * vexArr_fixed = new int [vexArrLen];
		for(int j = 0 ; j < vexArrLen ; ++j) vexArr_fixed[j] = vexArr[j];
		int ch = vexArr[start];
		vexArr[start] = vexArr[i];
		vexArr[i] = ch;
		square(vexArr , vexArrLen , start + 1);
		for(int j = 0 ; j < vexArrLen ; ++j) vexArr[j] = vexArr_fixed[j];
		delete vexArr_fixed;
	}
	if(start == vexArrLen)
		if(vexArr[0]+vexArr[1]+vexArr[2]+vexArr[3] == vexArr[4]+vexArr[5]+vexArr[6]+vexArr[7])
			if(vexArr[0]+vexArr[2]+vexArr[4]+vexArr[6] == vexArr[1]+vexArr[3]+vexArr[7]+vexArr[7])
				if(vexArr[0]+vexArr[1]+vexArr[4]+vexArr[5] == vexArr[2]+vexArr[3]+vexArr[6]+vexArr[7]) {
					for(int i = 0 ; i < 8 ; ++ i) cout << vexArr[i] << ends;
					cout << endl;
				}
}
void square_start(int * numArr , int numArrLen) {
	int * vexArr = new int [numArrLen];
	int vexArrLen = numArrLen;
	for(int i = 0 ; i < vexArrLen ; ++i) vexArr[i] = numArr[i];
	square(vexArr , vexArrLen , 0);
	delete vexArr;
}
int main() {
	int numArr [8] = {1,2,3,4,5,6,7,8};
	square_start(numArr , 8);
	return 0;
}
