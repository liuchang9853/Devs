/*
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
整数，判断数组中是否含有该整数。
例如数组：
1  2  8  9
2  4  9  12
4  7  10  13
6  8  11  15
查找7，返回true；查找5，返回false。

对二维数组的操作最忌讳：不找规律，按序一行行、一列列操作。即二维数组要找行列规律、
运用规律操作行列，不能死板的一行行、一列列操作。
常见的规律是：
（1）与4个角的值是否有关系。
（2）与首尾的行、列是否有关系。
（3）与对角、反对角是否有关系。
（4）下三角、上三角区域相关。 
*/
#include <iostream>
using namespace std;
bool search(int arr[][4],int row,int col,int key){
	if (key < arr[0][0] && key > arr[row-1][col-1]) return false;
	int i=0 , j=col-1;
	while ((arr[i][j]!=key)&&(!(i==row-1&&j==0))){
		if(key > arr[i][j]) ++i;
		else --j;
	}
	if (arr[i][j]==key) return true;
	return false;
}
int main(){
	int arr[][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int key;
	cin >> key;
	const char * res = search(arr,4,4,key)==1?"true":"false";
	//"str"是const char *，char * 可以转换为const char *；但反之则不行。 
	cout << res;
	return 0;
} 
