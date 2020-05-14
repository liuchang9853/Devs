#include <iostream>
#include <vector>
using namespace std;

void test(vector<int> &a) {}

int main() {
	int len;
	cin >> len;
	vector<int> a(len); //（1）初始化_1：vector<ElemTypr> arr(length)
	vector<int> b; //初始化_2：vector<ElemTypr> arr
	vector< vector<int> > c; //初始化_3：类似于二维数组，但行列长均可变(一般不用)

	test(a); //（2）参数传递

	a.size(); //（3）arr.size()，动态数组arr的长度 

	for(int i = 0 ; i < a.size() ; ++i) a[i] = 0; //（4）遍历a

	for (int i = 0 ; i < len ; ++i) b.push_back(i); //（5）arr.push_back(v)指在b尾补v

	for (vector<int>::iterator it = b.begin() ; it != b.end(); ++it) {
		cout << * it << ends;
		/*
		（6） 
		iterator是指针类型（类似于*的含义），可见iterator是vector<class T>class中的static成员。 
		arr.begin()返回arr首元地址
		arr.end()返回arr末元的下一个地址，左闭右开
		*/
	}

	b.pop_back();//（7）arr.pop_back()删除arr尾部元素
	
	b.insert(b.begin() + 1 , 9); //（8）arr.insert(start_addr,value)，插入 
	
	b.erase(b.begin() , b.begin() + 2); //（9）删除b[0,1]，即[first,last)
	
	b.clear();//（10）arr.clear()，清空arr
	 
	return 0;
}
/*
（11） 
vector<char> ch[len] 和 vector<char> ch(len) 的差别：
前者定义了一个ch数组，每一元素为一个vector可变数组。
后者定义了一个长为len的vector可变长数组。
*/
