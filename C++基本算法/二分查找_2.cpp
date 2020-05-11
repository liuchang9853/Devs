/*
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
分析：
因为是两段排序数组，故想用二分查找法。
二分查找法关注的是low,high,mid。
对于此，有几种情况：
{2,3,4,5,6} 把0个（所有）元素搬到数组的末尾。（容易忽略）
{4,5,6,2,3} 把若干个元素搬到数组末尾。
{1,1,0,1,1,1,1}递增（减）数组中最易被忽略的是这样的含若干相同元素值的数组。
*/
#include <iostream>
using namespace std;
int binSearch(const int *Array , int start , int end) {
	int low = start,high = end;
	int mid = low + (high - low) / 2;
	
	if(Array[low] < Array[high]) return low; //{2,3,4,5,6}
	else if(Array[low] == Array[mid] == Array[high]) { //{1,1,0,1,1,1,1}
		//注意bool == bool == bool也是正确的。 
		for(; Array[low] == Array[high] && low != high; ++low);
		return low;
	}
	else { //{4,5,6,2,3}、{5,6,2,3,4}
		while(low < high - 1) {
			if(Array[mid] < Array[low] || Array[mid] < Array[high]) high = mid;
			if(Array[mid] > Array[low] || Array[mid] > Array[high]) low = mid;
			mid = low + (high - low) / 2;
		}
		return Array[low] < Array[high] ? low : high;
	}
}
int main() {
	int arr_1 [] = {2,3,4,5,6};
	int arr_2 [] = {1,1,0,1,1,1,1};
	int arr_3 [] = {5,6,2,3,4};
	cout << binSearch(arr_1,0,4) << ends;
	cout << binSearch(arr_2,0,6) << ends;
	cout << binSearch(arr_3,0,4);
	return 0;
}
