//#include<cstring>，该头文件下的函数参数大多为char * ptr。

#include <iostream>
#include <cstring>
using namespace std;
int main () {
	char str1[11] = "Hello"; //字符串赋值形式
	char str2[11] = "World";
	char str3[11];
	int len;

	//复制 str1 到 str3 ， 返回str3。 
	strcpy( str3, str1);
	cout << "strcpy(str3 , str1) : " << str3 << endl;

	char s [ ] = "abcdefgh" , *p = s;
	p += 3;
	printf("%d\n" , strlen(strcpy(p , "ABCD"))); //复制后，返回p，输出4
	/*
	strcpy复制完之后，字符串为abcABCD，但是p指向的位置是A，
	所以计算长度的时候前面三个不会算入其中。
	*/

	//连接 str1 和 str2
	strcat(str1 , str2);
	cout << "strcat(str1 , str2) : " << str1 << endl;

	//连接后，str1 的总长度
	len = strlen(str1);
	cout << " strlen(str1) : " << len << endl;
	
	//比较，若str1=str2，i=0；若str1<str2，i<0；若str1>str2，i>0； 
	int i = strcmp(str1 , str2);
	cout << i;
	
	/*
	每一string结尾处都是'\0'，不论该string的定义是char *、char []还是string。
	在#include<cstring>中，strlen(str)输出的str的用户定义字符个数，但实际上str包含两个部分：用户定义字符 和 '\0'。
	若有：char str[5] = "loveU";则出错，因为char[]方式定义，必须把最后一个元素留给'\0'。
	*/
	return 0;
}
