/*
��Ŀ����ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬
�ַ�����+100������5e2������-123������.1416������-1E-16������3.������ʾ��ֵ��
����12e���� ��1a3.14������1.2.3������+-5������12e+5.4������.e+5�������ǡ� 
*/
#include <iostream>
using namespace std;
bool if_elem_num(char elem){
	if(elem >= '0' && elem <= '9') return true;
	else return false;
} 
bool if_number(char * num) {
	bool if_signed = false; //�Ƿ���������
	bool if_dot = false; //�Ƿ�С����
	bool if_exp = false; //�Ƿ�ָ��

	for (int i = 0 ; num[i] != '\0' ; ) {
		if(i==0 && (num[i] == '+' || num[i] == '-')) { //��ʾ�������з��ţ�ֻ����'+-','0~9'��'+-','.' 
			if_signed = true;
			if(!(if_elem_num(num[i + 1]) || num[i + 1] == '.')) return false;
			++i;
		}
		
		if(if_dot == false && num[i] == '.') { //��ʾ��������С���㣻ֻ����С����ǰ �� ���һ���������
			if_dot = true;
			if((i == 0 || !if_elem_num(num[i - 1])) && (!if_elem_num(num[i + 1]))) return false;
			++i; 
			
			continue; //Ӧ�� '.','\0' 
		}
		
		if(if_exp == false && (num[i] == 'e' || num[i] == 'E')) {//��ʾ��������e��'e'ǰ�������� ������'e','+-','0~9' 
			if_exp = true;
			if((i==0 || !if_elem_num(num[i - 1])) || (!((num[i + 1] == '+' || num[i + 1] == '-') && if_elem_num(num[i + 2])))) return false;
			i += 3; 
			
			continue; //Ӧ��'e','+','num','.' 
		}
		
		if(!if_elem_num(num[i])) return false;
		else ++i;
	}
	
	return true; 
}
int main() {
	//����
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

	//����
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
