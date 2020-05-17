/*
题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
*/
#include <iostream>
using namespace std;
void clockwise_print_matrix(int** ptr, int rowNum, int colNum) {
	if (!ptr) return;

	if (rowNum == 1) {
		for (int j = 0; j < colNum; ++j) cout << ptr[0][j] << ends;
		return;
	}
	if (colNum == 1) {
		for (int i = 0; i < rowNum; ++i) cout << ptr[i][0] << ends;
		return;
	}
	for (int j = 0; j < colNum - 1; ++j) cout << ptr[0][j] << ends;
	for (int i = 0; i < rowNum - 1; ++i) cout << ptr[i][colNum - 1] << ends;
	for (int j = colNum - 1; j > 0; --j) cout << ptr[rowNum - 1][j] << ends;
	for (int i = rowNum - 1; i > 0; --i) cout << ptr[i][0] << ends;

	if (rowNum - 2 == 0 || colNum - 2 == 0) return;

	int ** ptr_next = new int * [rowNum - 2];
	int * ptr_next_ptr = (int *)malloc((rowNum - 2) * (colNum - 2) * sizeof(int));
	for (int i = 0; i < (rowNum - 2) * (colNum - 2); ++i)
		if (i % (colNum - 2) == 0)
			ptr_next[i / (colNum - 2)] = &ptr_next_ptr[i];
	for (int i = 1; i < rowNum - 1; ++i)
		for (int j = 1; j < colNum - 1; ++j)
			ptr_next[i - 1][j - 1] = ptr[i][j];
	clockwise_print_matrix(ptr_next, rowNum - 2 , colNum - 2);
	free(ptr_next_ptr); //注意要动态空间回收 
	delete [] ptr_next;

	/*
	1.这里要注意的地方是：malloc 和 free ；new 和 delete。
	实际上，本题中能用malloc和free的地方都可以用new和delete，反之也成立。
	2.二者的区别是malloc和free是C中的库函数。而new和delete是C++引入的关键字。
	3.之所以引入new和delete，是因为malloc和free对自定义的类的动态内存空间不友好，
	自定义的类创建时调用构造函数，消亡时调用析构函数，malloc和free只是简单的创建
	所需的空间，暴力回收空间，不在编译器的范畴，所以也就不理会构造函数和析构函数。
	但对于内部数据类型而言，还是可以使用的。
	4.之所以不淘汰malloc和free，是因为C语言只支持该法创建和回收动态内存。
	5.总之，能用new和delete就用，尽量替代malloc和free。
	*/
}

int main() {
	int rowNum = 4 , colNum = 5; 
	int ** arr = new int * [rowNum];//[4][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,4,6,8},{0,3,6,9,12}}
	int * arr_ptr = (int *)malloc(rowNum * colNum * sizeof(int));
	for (int i = 0; i < rowNum * colNum; ++i)
		if (i % colNum == 0) arr[i / colNum] = &arr_ptr[i];
	for (int i = 0; i < rowNum; ++i)
		for (int j = 0; j < colNum; ++j)
			arr[i][j] = i * j;

	clockwise_print_matrix(arr, rowNum, colNum);

	return 0;
}
/*
这里采用的是：二维数组_3 中的动态二维数组构建方法。
模板：
T * * arr = new T * [rowNum];
T * arr_ptr = new T[rowNum * colNum]; //构建第一维指针数组 
for (int i = 0; i < rowNum * colNum; ++i)
	if (i % colNum == 0) arr[i / colNum] = &arr_ptr[i]; //为第一维指针数组赋值 
for (int i = 0; i < rowNum; ++i)
	for (int j = 0; j < colNum; ++j)
		arr[i][j] = val_i_j; //为元素赋值
fun(arr); //使用
delete arr_ptr; //回收第二维空间
delete arr; //回收第一维空间 
*/ 
