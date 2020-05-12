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
	MatrixElem matrix[3][4] = { {},{},{} };
};

struct String {
	const char* str;
	int length;
	int strPtr;
};
/*
1.最重要的经验就是上面这三个struct，即要养成 封装对象 的习惯。
MatrixElem 和 Matrix，最开始没有后者，但path()函数中就要引入具体的数值3和4，
泛化能力弱，而且也不符合对象理解的习惯。
若没有String，则在传char *参数时，就要同时传递str和strLen，参数列表复杂，不仅
易出错，且属于同一对象的属性被分别考虑。
能写成class、struct、enum、union等具有封装意义的形式，就一定要写成这样的形式。

2.能不定义全局变量，就不定义。比如，写成：
struct Matrix{
... 
} m; 
远不及在需要m的地方定义m好，只把Matrix这一struct类的定义放到全局空间就行。

3.Matrix中成员具有初值。 
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

//核心
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
			注意在递归中，这样的形式：
			stack.push();
			++ptr;
			递归函数(stack,ptr);
			--ptr 
			stack.pop();
			即递归函数需要的参数，若为进入递归函数而改变，则递归函数结束后，
			应恢复。 
			*/ 
		}
}

//启动函数
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
	//初始化m
	Matrix m;
	char arr[3][4] = { {'a','b','t','g'},{'c','f','c','s'},{'j','d','e','h'} };
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j) {
			m.matrix[i][j].row = i;
			m.matrix[i][j].col = j;
			m.matrix[i][j].data = arr[i][j];
		}

	//初始化str
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
