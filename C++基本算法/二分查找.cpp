#include <iostream>
using namespace std;
int binSearch(const int *Array , int start , int end , int key) {
	int low = start,high = end,mid;
	while(end <= high) {
		mid=low + (high - low) / 2;
		if(key == Array[mid])  return mid;
		else if(key > Array[mid]) low = mid + 1;
		else if(key < Array[mid]) high = mid - 1;
	}
	return -1;
}
int main() {
	int array [] = {1,3,5,6,7,9,100,111,200};
	cout << binSearch(array,0,8,111);
	return 0;
}
