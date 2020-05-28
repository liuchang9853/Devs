/*
map内部的实现原理是红黑树，会实现按key的自动排序。
unordered_map内部的实现原理是hash表，搜索的时间开销为o(1)，无序。这里的无序不是说
可以自己定义序（比如输入a,b,c，则输出a,b,c）。而是真的无序（输入a,b,c，则可能输出c,b,a）。 
*/
#include <iostream>
#include <unordered_map> //无序 map 容器
using namespace std;
int main() {
	//（1）初始化
	unordered_map<char , int> um_1{{'a' , 1} , {'c' , 3} , {'b' , 2}}; 
	/*
	并不表示当前um_1中的顺序是a,c,b。因为我们不知道内部的hash机制，所以可能是c,a,b的顺序。
	实际上，以hash机制建立的一系列unordered_，其目的不在于序，而在于时间开销。 
	*/
	unordered_map<char , int> um_2(um_1);
	
	um_1.emplace('a' , 2); 
	//（2）添加，因hash(key)指向同一空间，若该空间中已有val，则不执行该语句。重赋值um_1['a'] = 2;  
	um_1.emplace('r' , 3);
	
	//（3）遍历
	for(unordered_map<char , int>::iterator it = um_1.begin() ; it != um_1.end() ; ++it)
		cout << it->first << ends << it->second << endl;
		
	/*
	常见方法还有： 
	（4）um_1.empty()
	（5）um_1.size()
	（6）um_1.find(key) 
	（7）um_1.erase(key||um_1.find(key))
	（8）um_1.clear()
	（9）um_1.swap(um_2) 
	*/ 
	
	return 0;
}
