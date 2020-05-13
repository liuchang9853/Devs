/*
��Ŀ��ʵ�ֺ���double Power(double base, int exponent)����base��exponent
�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
������
a^(n) =
a^(n/2) * a^(n/2)  ��nΪż��
a^[(n-1)/2] * a^[(n-1)/2] * a  ��nΪ����
*/
#include <iostream>
using namespace std;
//����
positiveExpPower(double base, int exponent) {
	if(exponent == 0) return 1;
	if(exponent == 1) return base;

	double result = positiveExpPower(base , exponent >> 1);
	result *= result;
	/*
	������ >>1 ����� /2 ��Ч�ʸ��ߡ�����Ҫ���ף������е����з��Ŷ�������߶�����࣬����
	���ǲ��������������
	��Ч�ʸߵ�ԭ�򣬿�������Ϊ�����ڴ淵�ظ����������Ƕ������������λ�������ֱ�Ӳ����ö�
	����������+��-��*��/��%�ȳ�����Ų������Ǹö�������תΪʮ���ƺ���������Ը�Ϊ���ӡ�
	*/
	if(exponent & 0x1) result *= base; //�� & 0x1 ���� % 2 == 1
	return result;
}
//��������
double power(double base, int exponent) {
	if(base == 0 && exponent <= 0) throw "zero error."; //base = 0 && exponent <= 0

	double result;
	if(exponent < 0) result = 1.0 / positiveExpPower(base , -exponent); //exponent < 0
	else result = positiveExpPower(base , exponent); //exponent >= 0

	return result;
}

int main() {
	try {

		cout << power(1 , 7) << endl;
		cout << power(2 , 16) << endl;
		cout << power(9 , 7) << endl;
		cout << power(-3 , 5) << endl;
		cout << power(5 , 0) << endl;

		cout << power(1 , -7) << endl;
		cout << power(2 , -16) << endl;
		cout << power(9 , -7) << endl;
		cout << power(-3 , -5) << endl;

		cout << power(0 , 12) << endl;
		cout << power(0 , -12) << endl;
		cout << power(0 , 0) << endl;
	} catch(const char * error) {
		cout << error;
	}
	return 0;
}
