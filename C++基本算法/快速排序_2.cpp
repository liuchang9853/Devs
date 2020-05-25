/*
��Ŀ����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���
������һ������Ϊ9������{1, 2, 3, 2, 2, 2, 5, 4, 2}����������2��������
������5�Σ��������鳤�ȵ�һ�룬������2��
��1����һ�ǿ��ŵ�˼·��ѡ���ᣬȻ��Ԫ�ط־��������ࡣ��ѡȡ������Ԫ���ǳ��ִ�������
����n/2��Ԫ�أ����Ԫ�ر�Ϊ��λ����
��2������������count��ɨ�����飬����ÿɨ��һ��Ԫ�أ��򽫸�Ԫ�غ�ͳ�Ƶ�Ԫ�е�Ԫ�رȽϣ�
��������ͬ����++count�������߲��ȣ���--count������cout == 0ʱ����һ��ɨ�赽��Ԫ�ؽ���
��ͳ�Ƶ�Ԫ�е�Ԫ�أ�++count�����õ���ͳ�Ƶ�Ԫ�е�Ԫ�ؾ��ǳ��ִ�������n/2��Ԫ�أ���ʱ
count>0��
*/
#include <iostream>
using namespace std;

//��һ
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
		
		//check���ڼ����Ƿ���λ��ȷΪ���ִ�����������һ�����������ʵ��ģ�黯�� 
		int mid_elem = A_change[mid] , check = 0;
		for(int i = 0 ; i < high - low + 1 ; ++i)
			if(A_change[i] == A_change[mid]) ++check;
			
		delete A_change;

		if(check > (high - low + 1) / 2) return mid_elem;
		else throw false;

	} else throw false;

	/*
	�ڸ������ʱ��Ҫ�ǵã�������Ҫ��Partition��������ΪPartition�����ǿ��ŵĺ������ڣ�
	��low��high��pivot���趨������ϸ˼�����Ѿ����˲��ܱ䶯�ĵز������磬Ҫ��pivot�ĳ�
	arr[mid]������arr[low]������arr[low]��arr[high]����ʱ�����úܸ��ӡ�
	���ԣ�������ţ����Ǹ���QuickSort������
	*/
}

//����
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
	//��������ʵ��ģ�黯�� 
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
