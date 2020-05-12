#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
T ** matrix(T ** arr , int rowNum , int colNum) {
	T ** row = new T * [rowNum]; //ָ��ÿһrow��ָ��
	T * arrPtr = (T *)malloc(rowNum * colNum * sizeof(T)); //Ҫ��֤����������ص㣬����ַ����

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
֮���Կ��԰���ά������ʽд��ԭ��������£�
int * arr = new int[4];
arr[0];
��֪���ǿ��Եģ���ֻҪarr��ָ�������ָ�룬�Ϳ�����arr[]��
�����ʵ�ֶ�ά�����ԭ���ǿ���row*col��������T�Ϳռ䣺arrPtr = T [row*col] 
�ٿ���rowNum��T*�ռ䣺row = T * [rowNum]
��ÿһ��rowԪ��ָ���ض���arrPtrԪ�ء�
rowָ�������ռ䣬�ʿ���row[]��row��ÿһԪ��Ҳָ�������ռ䣬��row[][]�� 
row��T*�ռ䣬 

���帳ֵ����ά��������ο���C++�ʼ� p57��61 
*/
