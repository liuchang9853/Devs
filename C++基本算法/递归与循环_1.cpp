/*
题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
Fibonacci(n)=
0 n=0;
1 n=1;
Fibonacci(n - 2) + Fibonacci(n - 1) n>1;
（1）递归法，代码简洁，但效率低。频繁开辟函数所需空间，在时间、空间上都十分低效。
（2）循环法，效率高，不会开辟多余的空间，但代码繁复。
*/
#include <iostream>
using namespace std;
//递归法
long long int Fibonacci_1(int n) {
	return n < 2 ? n : Fibonacci_1(n-2) + Fibonacci_1(n-1);
}

//循环法
long long int Fibonacci_2(int n) {
	long long int F_0 = 0 , F_1 = 1;
	if(n == 0) return F_0;
	if(n == 1) return F_1;
	
	long long int F_n_2 = F_0, F_n_1 = F_1 , F_n = F_n_2 + F_n_1;
	for (int i = 2; i <= n; ++i) {
		F_n = F_n_2 + F_n_1;
		F_n_2 = F_n_1;
		F_n_1 = F_n;
	}
	
	return F_n;
}

int main() {
	cout << Fibonacci_1(10) << endl;
	cout << Fibonacci_2(10);
	return 0;
}
