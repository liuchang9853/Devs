/*
��Ŀ������һ������8�����ֵ����飬�ж���û�п��ܰ���8�����ֱַ�ŵ��������8�������ϣ�
ʹ����������������Ե����ϵ�4������ĺͶ���ȡ�
�ⷨ������ͼ����ʵ�ʾ�����vexȫ������ѡ��������������С� 
*/
#include <iostream>
using namespace std;
void square(int * vexArr , int vexArrLen , int start) {
	for(int i = start ; i < vexArrLen ; ++i) {
		int * vexArr_fixed = new int [vexArrLen];
		for(int j = 0 ; j < vexArrLen ; ++j) vexArr_fixed[j] = vexArr[j];
		int ch = vexArr[start];
		vexArr[start] = vexArr[i];
		vexArr[i] = ch;
		square(vexArr , vexArrLen , start + 1);
		for(int j = 0 ; j < vexArrLen ; ++j) vexArr[j] = vexArr_fixed[j];
		delete vexArr_fixed;
	}
	if(start == vexArrLen)
		if(vexArr[0]+vexArr[1]+vexArr[2]+vexArr[3] == vexArr[4]+vexArr[5]+vexArr[6]+vexArr[7])
			if(vexArr[0]+vexArr[2]+vexArr[4]+vexArr[6] == vexArr[1]+vexArr[3]+vexArr[7]+vexArr[7])
				if(vexArr[0]+vexArr[1]+vexArr[4]+vexArr[5] == vexArr[2]+vexArr[3]+vexArr[6]+vexArr[7]) {
					for(int i = 0 ; i < 8 ; ++ i) cout << vexArr[i] << ends;
					cout << endl;
				}
}
void square_start(int * numArr , int numArrLen) {
	int * vexArr = new int [numArrLen];
	int vexArrLen = numArrLen;
	for(int i = 0 ; i < vexArrLen ; ++i) vexArr[i] = numArr[i];
	square(vexArr , vexArrLen , 0);
	delete vexArr;
}
int main() {
	int numArr [8] = {1,2,3,4,5,6,7,8};
	square_start(numArr , 8);
	return 0;
}
/*
�ݹ���ѭ��_2 �� �ݹ���ѭ��_3��ʵ����һ�����⡣��ȫ�������⡣�������ĵ����˻ʺ����⣺
��8 ��8�Ĺ����������ϰڷ�8���ʺ�ʹ�䲻���໥�����������������ʺ󲻵ô���ͬһ�С�
ͬһ�л���ͬһ���Խ����ϡ����ж����ַ��������İڷ���
��row:0~7;col:0~7����ʱ������һ��row_col[8]���±��ʾ�ʺ��rowIndex��Ԫ��ֵ��ʾ�ʺ�
��colIndex�����磺
row_col[0] = 2 
row_col[1] = 5 
row_col[2] = 1 
row_col[3] = 6 
row_col[4] = 0 
row_col[5] = 3 
row_col[6] = 7 
row_col[7] = 4
�ͷֱ��ʾÿ���ʺ����ڵ��к��С�ֻҪԪ��ֵΪ0~7�Ҳ��ȣ��������˻ʺ���ͬһ�л��С�
��ʱ����ȫ�������⡣�ٿ��ǲ���ͬһ�Խ����ϣ�ת��Ϊ��row_col[i]-i != row_col[j]-j��
����ȫ���м���������Ļ������⡣ 
*/
