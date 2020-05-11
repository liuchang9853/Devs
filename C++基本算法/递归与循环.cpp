/*
��Ŀ��дһ������������n����쳲�������Fibonacci�����еĵ�n�
Fibonacci(n)=
0 n=0;
1 n=1;
Fibonacci(n - 2) + Fibonacci(n - 1) n>1;
��1���ݹ鷨�������࣬��Ч�ʵ͡�Ƶ�����ٺ�������ռ䣬��ʱ�䡢�ռ��϶�ʮ�ֵ�Ч��
��2��ѭ������Ч�ʸߣ����Ὺ�ٶ���Ŀռ䣬�����뷱����
*/
#include <iostream>
using namespace std;
//�ݹ鷨
long long int Fibonacci_1(int n) {
	return n < 2 ? n : Fibonacci_1(n-2) + Fibonacci_1(n-1);
}

//ѭ����
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
������̨�����⣺
һֻ����һ�ο�������һ��̨�ף�Ҳ��������2��̨�ס������������һ��n��̨���ܹ��ж���
��������
�ⷨ��
��f(n)Ϊn��̨�׵����������� 
����һ����һ��̨�ף���f(n-1)��������
����һ��������̨�ף���f(n-2)��������
�ã�f(n) = f(n-2) + f(n-1)����쳲�������
��ο�������쳲��������У�ֻҪf(n)����Fibonacci(n)���ǡ�f()������ʲô���ص�֪�� 
*/
