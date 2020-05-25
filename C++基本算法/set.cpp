/*
set是一个内部不含重复元素且自动有序的集合。
set内部使用红黑树实现的，在建立映射的过程中会自动实现升序。 
*/
#include <iostream>
#include <set>
using namespace std;
int main(){
	set<int> st; //1.set的初始化_1
	set<int> st_1{1,2,3}; //初始化_2
	set<int> st_2(st_1); //初始化_3
	
	for(int i = 0 ; i < 5 ; ++i) { //2.set的插入 
		st.insert((4 - i) % 3); //输入含重乱序1,0,2,1,0
	}
	
	for(set<int>::iterator it = st.begin() ; it != st.end() ; ++it) { //3.set的遍历，只能用iterator 
		cout << * it << ends; //输出0,1,2，实现去重后的自动排序 
	}
	cout << endl;
	
	set<int>::iterator it = st.find(2); //4.find(v)返回v的地址 
	cout << * it << endl;
	
	st.swap(st_1); //5.全部元素的交换
	 
	st.count(1); //6.count(val)返回值为val的元素个数
	 
	st.erase(st.find(2)); //7.清空指定元素，erase(ptr)与find(val)、begin()、end()组合使用
	st.erase(1); //清除全部值为1的元素 
	
	st.clear(); //8.全部清空
	
	cout << st.size(); //9.set长度 
	
	if(st.empty()) cout << "yes"; //10.是否为空 
	 
	return 0;
} 
