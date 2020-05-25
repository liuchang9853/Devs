#include <iostream>
using namespace std;
template<class ElemType>
int Partition(ElemType A[] , int low , int high) {
	ElemType pivot = A[low];
	while(low < high) {
		while(low < high && A[high] >= pivot) --high;
		A[low] = A[high];
		while(low < high && A[low] <= pivot) ++low;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

template<class ElemType>
void QuickSort(ElemType A[] , int low , int high) {
	if(low < high) {
		int pivotpos = Partition(A , low , high);
		QuickSort(A , low , pivotpos - 1);
		QuickSort(A , pivotpos + 1 , high);
	}
}
int main() {
	int arr [] = {19,1,15,7,20,17,5,6};
	QuickSort(arr , 0 , 7);
	for(int i=0;i<8;++i) cout << arr[i] << ends; 
	return 0;
}
