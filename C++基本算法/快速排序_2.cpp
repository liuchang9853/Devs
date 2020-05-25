/*
题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
出现了5次，超过数组长度的一半，因此输出2。
（1）法一是快排的思路，选枢轴，然后将元素分居枢轴两侧。若选取的枢轴元素是出现次数出现
超过n/2的元素，则该元素必为中位数。
（2）法二是设置count。扫描数组，若是每扫描一个元素，则将该元素和统计单元中的元素比较，
若二者相同，则++count；若二者不等，则--count。且若cout == 0时，下一次扫描到的元素将替
代统计单元中的元素，++count。最后得到的统计单元中的元素就是出现次数超过n/2的元素，此时
count>0。
*/
#include <iostream>
using namespace std;

//法一
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
ElemType QuickSort(ElemType A[] , int low , int high) {
	int start = low;
	int end = high;
	if(start <= end) {
		ElemType * A_change = new ElemType[high - low + 1];
		for(int i = low ; i <= high ; ++i) A_change[i] = A[i];
		
		int mid = (end - start) / 2;
		int pivotpos = Partition(A_change , start , end);
		while(pivotpos != mid) {
			if(pivotpos < mid) {
				start = pivotpos + 1;
				pivotpos = Partition(A_change , start , end);
			}

			if(pivotpos > mid) {
				end = pivotpos - 1;
				pivotpos = Partition(A_change , start , end);
			}
		}
		
		//check用于检验是否中位数确为出现次数超过长度一半的数。用于实现模块化。 
		int mid_elem = A_change[mid] , check = 0;
		for(int i = 0 ; i < high - low + 1 ; ++i)
			if(A_change[i] == A_change[mid]) ++check;
			
		delete A_change;

		if(check > (high - low + 1) / 2) return mid_elem;
		else throw false;

	} else throw false;

	/*
	在改造快排时，要记得，尽量不要改Partition函数，因为Partition函数是快排的核心所在，
	其low、high、pivot的设定，经仔细思考，已经到了不能变动的地步。比如，要把pivot改成
	arr[mid]而不是arr[low]，则在arr[low]和arr[high]交换时，会变得很复杂。
	所以，改造快排，就是改造QuickSort函数。
	*/
}

//法二
template<typename ElemType>
struct elem_count {
	ElemType elem;
	int count;
};

template<typename ElemType>
ElemType find_num(ElemType arr[] , int length) {
	if(length <= 0) throw false;
	elem_count<ElemType> package;
	package.elem = arr[0];
	package.count = 0;
	for(int i = 0 ; i < length ; ++i) {
		if(arr[i] == package.elem) ++package.count;
		else --package.count;
		if(package.count == -1) {
			package.elem = arr[i];
			package.count = 1;
		}
	}
	//检验用于实现模块化。 
	if(package.count > 0)
		return package.elem;
	else throw false;
}

int main() {
	int arr[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
	try {
		cout << QuickSort(arr , 0 , 8) << endl;
		cout << find_num(arr , 9) << endl;
	} catch(bool info) {
		cout << "false" << endl;
	}
	return 0;
}
