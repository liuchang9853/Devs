/*
题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
字符串“+100”、“5e2”、“-123”、“.1416”及“-1E-16”、“3.”都表示数值，
但“12e”、 “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”，“.e+5”都不是。 
*/
#include <iostream>
using namespace std;
bool if_elem_num(char elem){
	if(elem >= '0' && elem <= '9') return true;
	else return false;
} 
bool if_number(char * num) {
	bool if_signed = false; //是否有正负号
	bool if_dot = false; //是否含小数点
	bool if_exp = false; //是否含指数

	for (int i = 0 ; num[i] != '\0' ; ) {
		if(i==0 && (num[i] == '+' || num[i] == '-')) { //提示下文已有符号；只允许'+-','0~9'和'+-','.' 
			if_signed = true;
			if(!(if_elem_num(num[i + 1]) || num[i + 1] == '.')) return false;
			++i;
		}
		
		if(if_dot == false && num[i] == '.') { //提示下文已有小数点；只允许小数点前 或 后的一侧必有数字
			if_dot = true;
			if((i == 0 || !if_elem_num(num[i - 1])) && (!if_elem_num(num[i + 1]))) return false;
			++i; 
			
			continue; //应对 '.','\0' 
		}
		
		if(if_exp == false && (num[i] == 'e' || num[i] == 'E')) {//提示下文已有e；'e'前必有数字 。允许'e','+-','0~9' 
			if_exp = true;
			if((i==0 || !if_elem_num(num[i - 1])) || (!((num[i + 1] == '+' || num[i + 1] == '-') && if_elem_num(num[i + 2])))) return false;
			i += 3; 
			
			continue; //应对'e','+','num','.' 
		}
		
		if(!if_elem_num(num[i])) return false;
		else ++i;
	}
	
	return true; 
}
int main() {
	//正例
	char num_1 [] = {'1','2','\0'};
	char num_2 [] = {'1','2','.','0','\0'};
	char num_3 [] = {'.','1','2','\0'};
	char num_4 [] = {'2','e','+','2','.','\0'};
	char num_5 [] = {'-','1','2','e','+','7','\0'};

	if_number(num_1) == true ? cout << "num_1 is num" : cout << "num_1 isn't num";
	cout << endl;

	if_number(num_2) == true ? cout << "num_2 is num" : cout << "num_2 isn't num";
	cout << endl;

	if_number(num_3) == true ? cout << "num_3 is num" : cout << "num_3 isn't num";
	cout << endl;

	if_number(num_4) == true ? cout << "num_4 is num" : cout << "num_4 isn't num";
	cout << endl;

	if_number(num_5) == true ? cout << "num_5 is num" : cout << "num_5 isn't num";
	cout << endl;

	//反例
	char num_6 [] = {'-','-','2','e','+','7','\0'};
	char num_7 [] = {'-','1','2','e','6','7','\0'};
	char num_8 [] = {'-','1','2','e','6','.','\0'};
	char num_9 [] = {'-','1','a','5','6','7','\0'};
	char num_10 [] = {'-','1','2','e','+','7','e','-','5','\0'};
	char num_11 [] = {'e','1','2','e','+','7','e','-','5','\0'};

	if_number(num_6) == true ? cout << "num_6 is num" : cout << "num_6 isn't num";
	cout << endl;

	if_number(num_7) == true ? cout << "num_7 is num" : cout << "num_7 isn't num";
	cout << endl;

	if_number(num_8) == true ? cout << "num_8 is num" : cout << "num_8 isn't num";
	cout << endl;

	if_number(num_9) == true ? cout << "num_9 is num" : cout << "num_9 isn't num";
	cout << endl;

	if_number(num_10) == true ? cout << "num_10 is num" : cout << "num_10 isn't num";
	cout << endl;

	if_number(num_11) == true ? cout << "num_11 is num" : cout << "num_11 isn't num";
	cout << endl;
	return 0;
}
