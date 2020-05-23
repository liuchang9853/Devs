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
/*
青蛙跳台阶问题：
一只青蛙一次可以跳上一级台阶，也可以跳上2级台阶。求该青蛙跳上一个n级台阶总共有多少
种跳法。
解法：
设f(n)为n级台阶的跳法函数。 
若第一次跳一级台阶，共f(n-1)种跳法；
若第一次跳两级台阶，共f(n-2)种跳法；
得：f(n) = f(n-2) + f(n-1)，即斐波那契。
如何看出这是斐波那契数列？只要f(n)满足Fibonacci(n)就是。f()具体是什么不必得知。 
*/
