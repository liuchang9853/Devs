/*
��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж���
�մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��
�������ж��������Ƿ��и�������
�������飺
1  2  8  9
2  4  9  12
4  7  10  13
6  8  11  15
����7������true������5������false��

�Զ�ά����Ĳ�����ɻ䣺���ҹ��ɣ�����һ���С�һ���в���������ά����Ҫ�����й��ɡ�
���ù��ɲ������У����������һ���С�һ���в�����
�����Ĺ����ǣ�
��1����4���ǵ�ֵ�Ƿ��й�ϵ��
��2������β���С����Ƿ��й�ϵ��
��3����Խǡ����Խ��Ƿ��й�ϵ��
��4�������ǡ�������������ء� 
*/
#include <iostream>
using namespace std;
bool search(int arr[][4],int row,int col,int key){
	if (key < arr[0][0] && key > arr[row-1][col-1]) return false;
	int i=0 , j=col-1;
	while ((arr[i][j]!=key)&&(!(i==row-1&&j==0))){
		if(key > arr[i][j]) ++i;
		else --j;
	}
	if (arr[i][j]==key) return true;
	return false;
}
int main(){
	int arr[][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	int key;
	cin >> key;
	const char * res = search(arr,4,4,key)==1?"true":"false";
	//"str"��const char *��char * ����ת��Ϊconst char *������֮���С� 
	cout << res;
	return 0;
} 
