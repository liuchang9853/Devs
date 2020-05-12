/*
��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ�������
�ַ���·����·�����ԴӾ���������һ��ʼ��ÿһ�������ھ����������ҡ�
�ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���
�ø��ӡ������������3��4�ľ����а���һ���ַ�����bfce����·����·���е���
ĸ���»��߱�������������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ��
�ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
A B T G
C F C S
J D E H
���ݷ�������DFS��
(0,0)!=str[0],pass
(0,1)==str[0],next step:
	(0,1)->(0,0)?(0,0)!=str[1],pass
	(0,1)->(1,1)?(1,1)==str[1],next step:
		(1,1)->(0,1)?(0,1) has been used,pass
		...
*/
#include <iostream>
#include <stack>
using namespace std;

struct MatrixElem {
	int row;
	int col;
	char data;
};

struct Matrix {
	int rowNum = 3;
	int colNum = 4;
	MatrixElem matrix[3][4] = { {},{},{} };
};

struct String {
	const char* str;
	int length;
	int strPtr;
};
/*
1.����Ҫ�ľ����������������struct����Ҫ���� ��װ���� ��ϰ�ߡ�
MatrixElem �� Matrix���ʼû�к��ߣ���path()�����о�Ҫ����������ֵ3��4��
����������������Ҳ�����϶�������ϰ�ߡ�
��û��String�����ڴ�char *����ʱ����Ҫͬʱ����str��strLen�������б��ӣ�����
�׳���������ͬһ��������Ա��ֱ��ǡ�
��д��class��struct��enum��union�Ⱦ��з�װ�������ʽ����һ��Ҫд����������ʽ��

2.�ܲ�����ȫ�ֱ������Ͳ����塣���磬д�ɣ�
struct Matrix{
... 
} m; 
Զ��������Ҫm�ĵط�����m�ã�ֻ��Matrix��һstruct��Ķ���ŵ�ȫ�ֿռ���С�

3.Matrix�г�Ա���г�ֵ�� 
*/

bool ifUnvisited(stack<MatrixElem>& stepStack, MatrixElem elem) {
	int staLen = int(stepStack.size());
	stack<MatrixElem> tempStack;
	for (int i = 0; i < staLen; ++i) {
		tempStack.push(stepStack.top());
		stepStack.pop();
	}
	for (int i = 0; i < staLen; ++i) {
		stepStack.push(tempStack.top());
		tempStack.pop();
		if (stepStack.top().data == elem.data) return false;
	}
	return true;
}

//����
void path(Matrix m, MatrixElem elem, String &str, stack<MatrixElem>& stepStack) {
	if (str.strPtr >= str.length-1) {
		int staLen = int(stepStack.size());
		stack<MatrixElem> tempStack;
		for (int i = 0; i < staLen; ++i) {
			tempStack.push(stepStack.top());
			stepStack.pop();
		}
		for (int i = 0; i < staLen; ++i) {
			stepStack.push(tempStack.top());
			tempStack.pop();
			cout << stepStack.top().data << "(" << stepStack.top().row << "," << stepStack.top().col << ")" << ends;
		}

		cout << endl;
		return;
	}

	bool top = true, left = true, bottom = true, right = true;
	if (elem.row == 0) top = false;
	if (elem.row == m.rowNum - 1) bottom = false;
	if (elem.col == 0) left = false;
	if (elem.col == m.colNum - 1) right = false;

	if (top)
		if (str.strPtr < str.length && m.matrix[elem.row - 1][elem.col].data == str.str[str.strPtr + 1] && ifUnvisited(stepStack, m.matrix[elem.row - 1][elem.col])) {
			stepStack.push(m.matrix[elem.row - 1][elem.col]);
			++str.strPtr;
			path(m, m.matrix[elem.row - 1][elem.col], str, stepStack);
			--str.strPtr;
			stepStack.pop();
		}
	if (left)
		if (str.strPtr < str.length && m.matrix[elem.row][elem.col - 1].data == str.str[str.strPtr + 1] && ifUnvisited(stepStack, m.matrix[elem.row][elem.col - 1])) {
			stepStack.push(m.matrix[elem.row][elem.col - 1]);
			++str.strPtr;
			path(m, m.matrix[elem.row][elem.col - 1], str, stepStack);
			--str.strPtr;
			stepStack.pop();
		}
	if (bottom)
		if (str.strPtr < str.length && m.matrix[elem.row + 1][elem.col].data == str.str[str.strPtr + 1] && ifUnvisited(stepStack, m.matrix[elem.row + 1][elem.col])) {
			stepStack.push(m.matrix[elem.row + 1][elem.col]);
			++str.strPtr;
			path(m, m.matrix[elem.row + 1][elem.col], str, stepStack);
			--str.strPtr;
			stepStack.pop();
		}
	if (right)
		if (str.strPtr < str.length && m.matrix[elem.row][elem.col + 1].data == str.str[str.strPtr + 1] && ifUnvisited(stepStack, m.matrix[elem.row][elem.col + 1])) {
			stepStack.push(m.matrix[elem.row][elem.col + 1]);
			++str.strPtr;
			path(m, m.matrix[elem.row][elem.col + 1], str, stepStack);
			--str.strPtr;
			stepStack.pop();
			/*
			ע���ڵݹ��У���������ʽ��
			stack.push();
			++ptr;
			�ݹ麯��(stack,ptr);
			--ptr 
			stack.pop();
			���ݹ麯����Ҫ�Ĳ�������Ϊ����ݹ麯�����ı䣬��ݹ麯��������
			Ӧ�ָ��� 
			*/ 
		}
}

//��������
void pathTraverse(Matrix m, String &str) {
	stack<MatrixElem> stepStack;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			if (m.matrix[i][j].data == str.str[0]) {
				stepStack.push(m.matrix[i][j]);
				++str.strPtr;
				path(m, m.matrix[i][j], str, stepStack);
				--str.strPtr;
				stepStack.pop();
			}
}

int main() {
	//��ʼ��m
	Matrix m;
	char arr[3][4] = { {'a','b','t','g'},{'c','f','c','s'},{'j','d','e','h'} };
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j) {
			m.matrix[i][j].row = i;
			m.matrix[i][j].col = j;
			m.matrix[i][j].data = arr[i][j];
		}

	//��ʼ��str
	String str_1;
	str_1.str = "bfce";
	str_1.length = 4;
	str_1.strPtr = -1;
	cout << "the path of str_1 : "; 
	pathTraverse(m, str_1);

	String str_2;
	str_2.str = "abfb";
	str_2.length = 4;
	str_2.strPtr = -1;
	cout << "the path of str_2 : "; 
	pathTraverse(m, str_2);

	return 0;
}
