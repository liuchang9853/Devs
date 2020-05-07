#include <iostream>
using namespace std; 
void matrix_1(int mat[][3]){}
void matrix_2(int mat[3][3]){}

void matrix_3(int row , int (*mat)[3]){cout << mat[row-1][0];}

int main(){
	int mat_1[][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int mat_2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	/*
	赋值的两种方式，可以省略第一维的val，但不能省略第二及更高维的val。 
	*/
	
	matrix_1(mat_1);
	matrix_2(mat_1); 
	matrix_3(3,mat_1);
	 
	return 0;
}
