/*
题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
A B T G
C F C S
J D E H
回溯法类似于DFS：
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
	MatrixElem matrix[3][4];
};

struct String {
	const char * str;
	int length;
	int strPtr;
};

bool ifUnvisited(stack<MatrixElem> &stepStack , MatrixElem elem) {
	int staLen = int(stepStack.size());
	stack<MatrixElem> tempStack;
	for(int i = 0 ; i < staLen ; ++i) {
		tempStack.push(stepStack.top());
		stepStack.pop();
	}
	for(int i = 0 ; i < staLen ; ++i) {
		stepStack.push(tempStack.top());
		tempStack.pop();
		if(stepStack.top().data == elem.data ) return false;
	}
	return true;
}

//核心
void path(Matrix m , MatrixElem elem , String str , stack<MatrixElem> &stepStack) {
	if(str.strPtr >= str.length) {
		int staLen = int(stepStack.size());
		stack<MatrixElem> tempStack;
		for(int i = 0 ; i < staLen ; ++i) {
			tempStack.push(stepStack.top());
			stepStack.pop();
		}
		for(int i = 0 ; i < staLen ; ++i) {
			cout << tempStack.top().data << "(" << tempStack.top().row << "," << tempStack.top().col << ")" << ends;
			stepStack.push(tempStack.top());
			tempStack.pop();
		}

		cout << endl;
		return ;
	}

	bool top = true , left = true , bottom = true , right = true;
	if(elem.row == 0) top = false;
	if(elem.row == m.rowNum-1) bottom = false;
	if(elem.col == 0) left = false;
	if(elem.col == m.colNum-1) right = false;


	if(top)
		if(m.matrix[elem.row-1][elem.col].data == str.str[++str.strPtr] && ifUnvisited(stepStack , m.matrix[elem.row-1][elem.col])) {
			stepStack.push(m.matrix[elem.row-1][elem.col]);
			path(m , m.matrix[elem.row-1][elem.col] , str , stepStack);
			stepStack.pop();
		}
	if(left)
		if(m.matrix[elem.row][elem.col-1].data == str.str[++str.strPtr] && ifUnvisited(stepStack , m.matrix[elem.row][elem.col-1])) {
			stepStack.push(m.matrix[elem.row][elem.col-1]);
			path(m , m.matrix[elem.row][elem.col-1] , str , stepStack);
			stepStack.pop();
		}
	if(bottom)
		if(m.matrix[elem.row+1][elem.col].data == str.str[++str.strPtr] && ifUnvisited(stepStack , m.matrix[elem.row+1][elem.col])) {
			stepStack.push(m.matrix[elem.row+1][elem.col]);
			path(m , m.matrix[elem.row+1][elem.col] , str , stepStack);
			stepStack.pop();
		}
	if(right)
		if(m.matrix[elem.row][elem.col+1].data == str.str[++str.strPtr] && ifUnvisited(stepStack , m.matrix[elem.row][elem.col+1])) {
			stepStack.push(m.matrix[elem.row][elem.col+1]);
			path(m , m.matrix[elem.row][elem.col+1] , str , stepStack);
			stepStack.pop();
		}
}

//启动函数
void pathTraverse(Matrix m , String str) {
	stack<MatrixElem> stepStack;
	for(int i=0; i<3; ++i)
		for(int j=0; j<4; ++j)
			if(m.matrix[i][j].data == str.str[0]) {
				stepStack.push(m.matrix[i][j]);
				path(m , m.matrix[i][j] , str , stepStack);
				stepStack.pop();
			}
}

int main() {
	//初始化m
	Matrix m;
	char arr[3][4] = {{'a','b','t','g'},{'c','f','c','s'},{'j','d','e','h'}};
	for(int i=0; i<3; ++i)
		for(int j=0; j<4; ++j) {
			m.matrix[i][j].row = i;
			m.matrix[i][j].col = j;
			m.matrix[i][j].data = arr[i][j];
		}

	//初始化str
	String str_1;
	str_1.str = "bfce";
	str_1.length = 4;
	str_1.strPtr = -1;
	pathTraverse(m , str_1);

	String str_2;
	str_2.str = "abfd";
	str_2.length = 4;
	str_2.strPtr = -1;
	pathTraverse(m , str_2);

	return 0;
}
