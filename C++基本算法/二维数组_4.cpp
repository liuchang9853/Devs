/*
��Ŀ������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�
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
	free(ptr_next_ptr); //ע��Ҫ��̬�ռ���� 
	delete [] ptr_next;

	/*
	1.����Ҫע��ĵط��ǣ�malloc �� free ��new �� delete��
	ʵ���ϣ�����������malloc��free�ĵط���������new��delete����֮Ҳ������
	2.���ߵ�������malloc��free��C�еĿ⺯������new��delete��C++����Ĺؼ��֡�
	3.֮��������new��delete������Ϊmalloc��free���Զ������Ķ�̬�ڴ�ռ䲻�Ѻã�
	�Զ�����ഴ��ʱ���ù��캯��������ʱ��������������malloc��freeֻ�Ǽ򵥵Ĵ���
	����Ŀռ䣬�������տռ䣬���ڱ������ķ��룬����Ҳ�Ͳ���ṹ�캯��������������
	�������ڲ��������Ͷ��ԣ����ǿ���ʹ�õġ�
	4.֮���Բ���̭malloc��free������ΪC����ֻ֧�ָ÷������ͻ��ն�̬�ڴ档
	5.��֮������new��delete���ã��������malloc��free��
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
������õ��ǣ���ά����_3 �еĶ�̬��ά���鹹��������
ģ�壺
T * * arr = new T * [rowNum];
T * arr_ptr = new T[rowNum * colNum]; //������һάָ������ 
for (int i = 0; i < rowNum * colNum; ++i)
	if (i % colNum == 0) arr[i / colNum] = &arr_ptr[i]; //Ϊ��һάָ�����鸳ֵ 
for (int i = 0; i < rowNum; ++i)
	for (int j = 0; j < colNum; ++j)
		arr[i][j] = val_i_j; //ΪԪ�ظ�ֵ
fun(arr); //ʹ��
delete arr_ptr; //���յڶ�ά�ռ�
delete arr; //���յ�һά�ռ� 
*/ 
