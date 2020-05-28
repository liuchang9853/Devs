/*
��Ŀ����һ��m ��n�����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ
����ֵ����0��������Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ�
�������ƶ�һ��ֱ���������̵����½ǡ�����һ�����̼��������������
�������õ�������ֵ�Ƕ��٣�
*/
#include <iostream>
using namespace std;

int max_val(int * * (&arr) , int rowNum , int colNum , int row , int col , int elemVal) {
	if(row == rowNum - 1 && col == colNum - 1) return arr[rowNum - 1][colNum - 1];
	
	int sum_col = 0 , sum_row = 0;
	if(col < colNum - 1) sum_col = elemVal + max_val(arr , rowNum , colNum , row , col + 1 , arr[row][col + 1]);
	if(row < rowNum - 1) sum_row = elemVal + max_val(arr , rowNum , colNum , row + 1 , col , arr[row + 1][col]);
	return (sum_col >= sum_row ? sum_col : sum_row);
}

void max_val_start(int * * (&arr) , int rowNum , int colNum) {
	if(!arr || rowNum == 0 || colNum == 0) return;
	cout << max_val(arr , rowNum , colNum , 0 , 0 , arr[0][0]);
}

int main() {
	int rowNum = 4;
	int colNum = 4;
	int * * arr = new int * [rowNum];
	for(int i = 0 ; i < rowNum ; ++i)
		arr[i] = new int[colNum];
	for(int i = 0 ; i < rowNum ; ++i)
		for(int j = 0 ; j < colNum ; ++j)
			cin >> arr[i][j];
	max_val_start(arr , rowNum , colNum);
	return 0;
}
