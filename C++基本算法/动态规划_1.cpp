/*
��Ŀ������һ������Ϊn���ӣ�������Ӽ���m�Σ�m��n����������n>1����m��1����
ÿ�ε����ӵĳ��ȼ�Ϊk[0]��k[1]��������k[m]��k[0]*k[1]*��*k[m]���ܵ�����
���Ƕ��٣���ÿ�γ�Ҳ�����������統���ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ
2��3��3�����Σ���ʱ�õ����ĳ˻�18��

��̬�滮����˼�룺
��f(n)���ȼ�����f(i) o f(n-i)
��f(i)���ȼ�����f(1) o f(i-1)
��f(i-1)���ȼ�����f(2) o f(k)
��f(1)��f(2)��f(k)����ֱ����ã���f(i)����
ͬ��f(n-i)Ҳͬ�����
���f(n)Ҳ�����

������������Ž⡣�����⻯Ϊ�����⣬������������Ž⡣����������Ž�ϳ�
��������Ž⡣
*/

#include <iostream>
using namespace std;
int cutRope(int n) {
	int * subLen = new int[n + 1];
	for (int i = 0 ; i < n + 1 ; ++i) subLen[i] = 0;

	subLen[1] = 1;
	subLen[2] = 2;
	subLen[3] = 3;

	//��nȡ1,2,3����Ŀ����1,2,3
	if(n == 1) return subLen[1];
	if(n == 2) return subLen[2];
	if(n == 3) return subLen[3];

	//���򣬾�Ҫ��subLen[1]��subLen[2]��subLen[3]��Ϊ��֪����cutRope(n)
	//Ҫ��ס������m >= 1
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
