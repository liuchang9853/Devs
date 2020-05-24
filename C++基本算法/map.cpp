/*
map内部使用红黑树实现的，在建立映射的过程中会实现按key值大小的自动升序。
map用于实现两类型间的映射。 
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	map<char , int> mp1; //（1）实现char(key)->int(value)的映射
	map<string , int> mp2;
	for (int i = 0 ; i < 5 ; ++i) {
		mp1[char(90 - i)] = i; //数组形式赋值，z~v 映射为 0~4
		
		string str;
		str.push_back(char(122 - i)); //注意char型要转为string，不能如string str = char(i)，而只能用str.push_back()函数 
		str.push_back(char(90 - i));
		mp2[str] = i;
		
		/*
		mp1结果不是Z 0 -> V 4，而是V 4 -> Z 0
		mp2结果不是zZ 0 -> vV 4，而是vV 4 -> zZ
		即char、string均实现了按key值大小的自动升序 
		*/
	}
	
	for (map<char , int>::iterator it = mp1.begin() ; it != mp1.end() ; ++it) {
		cout << it->first << ends << it->second <<endl;
		//（2）遍历：it->first为key， it->second为value
	}
	
	for (map<string , int>::iterator it = mp2.begin() ; it != mp2.end() ; ++it) {
		cout << it->first << ends << it->second <<endl;
	}

	mp2.erase(mp2.find("wW")); //（3）清除：erase(ptr)与find(key)、begin()、end()函数结合使用
	mp2.erase("vV"); //清除：即erase(key) 
	for (map<string , int>::iterator it = mp2.begin() ; it != mp2.end() ; ++it) {
		cout << it->first << ends << it->second <<endl;
	}
	
	mp2.clear(); //（4）清空map 
	cout << mp2.size(); //（5）map大小 

	return 0;
}

