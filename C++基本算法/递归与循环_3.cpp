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
/*
递归与循环_2 和 递归与循环_3其实讲了一类问题。即全排列问题。最有名的当属八皇后问题：
在8 ×8的国际象棋盘上摆放8个皇后，使其不能相互攻击，即任意两个皇后不得处在同一行、
同一列或者同一条对角线上。问有多少种符合条件的摆法？
设row:0~7;col:0~7。这时，设置一个row_col[8]，下标表示皇后的rowIndex，元素值表示皇后
的colIndex。例如：
row_col[0] = 2 
row_col[1] = 5 
row_col[2] = 1 
row_col[3] = 6 
row_col[4] = 0 
row_col[5] = 3 
row_col[6] = 7 
row_col[7] = 4
就分别表示每个皇后所在的行和列。只要元素值为0~7且不等，就做到了皇后不在同一行或列。
这时就是全排列问题。再考虑不在同一对角线上，转化为：row_col[i]-i != row_col[j]-j。
就是全排列加输出条件的基本问题。 
*/
