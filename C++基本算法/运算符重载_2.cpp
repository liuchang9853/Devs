//=运算符重载函数

#include <iostream>
#include <cstring>
using namespace std;

class CMyString {
	public :
		CMyString(char * pData = nullptr);
		//带默认形参值的函数，注意关键字nullptr属于C++11中新增定义
		CMyString(const CMyString & str);
		~CMyString(void);
		CMyString & operator=(const CMyString &str);
		void show () {
			cout << m_pData;
		}
	private :
		char *m_pData;
};
CMyString::CMyString(char *pData) {
	if(pData == nullptr) {
		m_pData = new char[1];
		m_pData[0] = '\0';
		/*
		倘若没有这一语句，析构函数可能出错。 
		*/ 
	} else {
		int length = strlen(pData); 
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
		/*
		（1） 
		首先要明白，若数据成员中有指针类型的数据，则要保证，该指针最终所指向的
		内存空间是不共享的，除非有特殊声明。这就是对象的封闭性。 
		该语句与：
		m_pData = pData;
		的区别在于，该语句让m_pData指向一个新开辟的length+1的char空间，把pData
		所指空间中的字符串复制到该char空间中。 实现了对象的封闭性。而m_pData = pData;
		则只是简单的把pData中存放的地址赋值于m_pData，对象不封闭。
		（2）其次还可以得知，#include<cstring>下的函数，操作的不是char数组名，而是
		char * ptr。 
		*/ 
	}
}
CMyString::~CMyString()
{
    delete[] m_pData;
}
CMyString::CMyString(const CMyString &str) {
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}
CMyString & CMyString::operator = (const CMyString & str) {
	/*
	1.该函数必须返回一个引用才行，实际上，所有的运算符重载函数都要返回一个引用才行。
	因为只有返回引用才允许连等、连加等操作。

	传入的参数也应该是引用，为避免调用复制构造函数而无谓浪费。
	*/

	if(this == &str)
		return *this;
	/*
	2.之所以是this == &str，而非this == str，是因为this是指向当前对象的指针。
	*this是对象本身。
	int &i = j;中，i是j的别名，i和j表示相同空间中的内容。故该句表示，return对象本身，
	函数返回：&对象。
	*/

	delete []m_pData;
	m_pData = nullptr;
	/*
	3.已知：
	int *p=new int [表达式];
	delete [] p;
	其中p是一个指向动态数组空间的指针。

	实际上：
	char * p = nullptr;
	delete [] p;
	return 0;
	也可以，即只要是p是一个指针，就可以用delete语句回收其指向的空间。
	delete不和new关键字共生，而与指针共存。

	这一步旨在释放本对象的内存，若赋值前未释放原有内存，将造成内存泄漏。
	这也指出了2的重要性，若this == &str，若没有步骤2，则在回收this所指
	空间的同时，也将回收&str空间。
	*/

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData , str.m_pData);
	/*
	4.首先，strlen()和strcpy()等函数属于#include<cstring>，对char数组操作。
	其次，之所以+1是因为要为char类型string最后一个固定元素"\0"开辟空间。
	*/

	return *this;
}
int main() {
	char * p_1 = "I love you.";
	char * p_2 = "I hate you.";
	char * p_3 = "I forgive you.";
	CMyString str_1(p_1);
	CMyString str_2(p_2);
	CMyString str_3(p_3);
	str_1=str_2=str_3;
	str_1.show();
	return 0;
}
