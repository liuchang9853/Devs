/*
题目：实现函数double Power(double base, int exponent)，求base的exponent
次方。不得使用库函数，同时不需要考虑大数问题。
方法：
a^(n) =
a^(n/2) * a^(n/2)  当n为偶数
a^[(n-1)/2] * a^[(n-1)/2] * a  当n为奇数
*/
#include <iostream>
using namespace std;
//核心
positiveExpPower(double base, int exponent) {
	if(exponent == 0) return 1;
	if(exponent == 1) return base;

	double result = positiveExpPower(base , exponent >> 1);
	result *= result;
	/*
	用右移 >>1 替代除 /2 ，效率更高。首先要明白，语言中的所有符号都是设计者定义的类，所以
	我们才能重载运算符。
	而效率高的原因，可能是因为机器内存返回给编译器的是二进制数，因此位运算符是直接操作该二
	进制数，而+、-、*、/、%等常规符号操作的是该二进制数转为十进制后的数，所以更为复杂。
	*/
	if(exponent & 0x1) result *= base; //用 & 0x1 代替 % 2 == 1
	return result;
}
//启动函数
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
