/*
题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
积是多少？（每段长也是整数）例如当绳子的长度是8时，我们把它剪成长度分别为
2、3、3的三段，此时得到最大的乘积18。

动态规划基本思想：
求f(n)，等价于求f(i) o f(n-i)
求f(i)，等价于求f(1) o f(i-1)
求f(i-1)，等价于求f(2) o f(k)
因f(1)、f(2)、f(k)都可直接求得，故f(i)可求。
同理，f(n-i)也同理可求。
最后，f(n)也求出。

即求问题的最优解。将问题化为子问题，求子问题的最优解。子问题的最优解合成
问题的最优解。
*/

#include <iostream>
using namespace std;
int cutRope(int n) {
	int * subLen = new int[n + 1];
	for (int i = 0 ; i < n + 1 ; ++i) subLen[i] = 0;

	subLen[1] = 1;
	subLen[2] = 2;
	subLen[3] = 3;

	//若n取1,2,3则按题目返回1,2,3
	if(n == 1) return subLen[1];
	if(n == 2) return subLen[2];
	if(n == 3) return subLen[3];

	//否则，就要将subLen[1]、subLen[2]、subLen[3]作为已知量求cutRope(n)
	//要记住：段数m >= 1
	for(int i = 4 ; i <= n ; ++i) {
		int max = 0;
		for(int j = 1 ; j <= i / 2 ; ++j)
			if(max < subLen[j] * subLen[i - j]) max = subLen[j] * subLen[i - j];
		subLen[i] = max;
	}
	
	return subLen[n];
}
int main() {
	cout << cutRope(8);
	return 0;
}
