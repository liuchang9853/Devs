/*
multiset位于#include<set>中，是含重升序的集合。 
*/
#include <iostream>
#include <set>
using namespace std;
int main(){
	multiset<int> mul_1; //1.初始化_1，不赋值 
	multiset<int> mul_2{1,2,2,3,3,3,4,4}; //初始化_2，赋值 
	multiset<int> mul_3(mul_2); //初始化_3，调用multiset的复制构造函数
	
	mul_1.insert(2);//2.插入
	mul_1.insert(2);
	mul_1.insert(1);
	mul_1.insert(0);
	
	//3.遍历，iterator是定义在multiset类中static数据成员 
	for(multiset<int>::iterator it = mul_1.begin() ; it != mul_1.end() ; ++it){
		cout << * it << ends; //输出0122，即含重的的升序。 
	} 
	
	if(!mul_1.empty()) mul_1.erase(mul_1.find(0)); //4.erase(ptr)删除指定位置的元素 
	if(mul_1.size()) mul_1.erase(2); //erase(val)删除指定值的元素 
	
	mul_1.swap(mul_2); //5.交换
	
	mul_1.count(3); //6.count(val)返回val的个数
	
	mul_1.clear(); //7.清空 
}
