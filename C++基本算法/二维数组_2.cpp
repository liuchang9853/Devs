#include <iostream>
using namespace std; 
void matrix_1(int mat[][3]){}
void matrix_2(int mat[3][3]){}

void matrix_3(int row , int (*mat)[3]){cout << mat[row-1][0];}

int main(){
	int mat_1[][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int mat_2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	/*
	��ֵ�����ַ�ʽ������ʡ�Ե�һά��val��������ʡ�Եڶ�������ά��val�� 
	*/
	
	matrix_1(mat_1);
	matrix_2(mat_1); 
	matrix_3(3,mat_1);
	 
	return 0;
}
