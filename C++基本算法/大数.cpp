/*
��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
��ӡ��1��2��3��4��5һֱ������3λ����999��
*/ 
#include <iostream>
using namespace std;
struct bigData {
	int * numArr;
	int numLen;
	int index;
};
void with_carry(bigData &data , int carry) {
	data.numArr[data.index] += carry;
	if(data.numArr[data.index] == 10) {
		data.numArr[data.index] = 0;
		
		data.index -= 1;
		with_carry(data , 1);
		data.index += 1;
	}
}
void print_1_to_max(int n) {
	//������ʼ��
	bigData data;
	data.numArr = new int[n + 1](); //numArr[0]���ڴ�����λ��λ���ж��Ƿ������ϡ������ڱ��� 
	data.numLen = n;
	data.index = n;

	//����������� 
	for(int i = 0 ; i < 10 && data.numArr[0] == 0 ; ++i) {
		//i��0~9 ��Ӧ data.numArr[data.index]��1~10 
		++data.numArr[data.index];

		//�н�λ���Ƚ�λ
		if(data.numArr[data.index] == 10) {
			data.numArr[data.index] = 0;

			//�ݹ���ɫ���ı���
			data.index -= 1;
			with_carry(data , 1);
			data.index += 1;
			
			//ÿ����һ��λ��Ҫ��forѭ�����¿�ʼ�� 
			i = -1;
		}

		//��ӡ
		if(data.numArr[0] == 0) {
			int j = 0;
			for( ; data.numArr[j] == 0 ; ++j);
			for( ; j <= data.numLen ; ++j) cout << data.numArr[j];
			cout << ends;
		}
	}
}
int main() {
	int n;
	cin >> n;
	print_1_to_max(n);
	return 0;
}
