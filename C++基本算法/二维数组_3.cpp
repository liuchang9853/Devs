#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
T ** matrix(T ** arr , int rowNum , int colNum) {
	T ** row = new T * [rowNum]; //指向每一row的指针
	T * arrPtr = (T *)malloc(rowNum * colNum * sizeof(T)); //要保证满足数组的特点，即地址连续

	for (int i = 0 ; i < rowNum * colNum ; ++i)
		if (i % colNum == 0) row[i / colNum] = &arrPtr[i];

	return row;
}

int main() {
	char * * arr_1 = new char * ();
	arr_1 = matrix(arr_1 , 3 , 4);
	arr_1[0][0] = 'a';  
	arr_1[0][1] = 'b';
	arr_1[0][2] = 'c';
	arr_1[0][3] = 'd';
	cout << arr_1[0][0] << ends << arr_1[0][1] << ends << arr_1[0][2] << ends << arr_1[0][3] << endl;

	int * * arr_2 = new int * ();
	arr_2 = matrix(arr_2 , 2 , 2);
	arr_2[0][0] = 1;
	arr_2[0][1] = 2;
	arr_2[1][0] = 3;
	arr_2[1][1] = 4;
	cout << arr_2[0][0] << ends << arr_2[0][1] << ends << arr_2[1][0] << ends << arr_2[1][1];
	return 0;
}
/*
之所以可以按二维数组形式写，原因分析如下：
int * arr = new int[4];
arr[0];
已知这是可以的，即只要arr是指向数组的指针，就可以用arr[]。
在这里，实现二维数组的原理是开辟row*col个连续的T型空间：arrPtr = T [row*col] 
再开辟rowNum个T*空间：row = T * [rowNum]
让每一个row元素指向特定的arrPtr元素。
row指向连续空间，故可以row[]；row的每一元素也指向连续空间，故row[][]。 
row个T*空间， 

定义赋值、多维数组的理解参考：C++笔记 p57、61 
*/
