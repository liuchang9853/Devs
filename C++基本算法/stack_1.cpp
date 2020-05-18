/*
题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。
在该栈中，调用min、push及pop的时间复杂度都是O(1)。
1.这种题目，是要求扩展原有stack的功能，而不是先实现原有stack，再扩展原有stack。
即，若使用原有stack的功能，直接调用#include<stack>即可。
2.本题思路是：同时构建主栈 和 辅栈。主栈用于实现基本的、常规的栈操作；辅栈用于
扩展主栈功能。
*/
#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;
template <typename T>
class stack_with_min {
	public :
		stack_with_min() {}
		~stack_with_min() {}

		void push(T val) {
			this->stack_main.push(val);
			if(this->stack_aux.size() > 0)
				if(val <= this->stack_aux.top()) this->stack_aux.push(val);
				else this->stack_aux.push(this->stack_aux.top());
			else this->stack_aux.push(val);
			/*
			该if else语句是代码的关键。
			若val小，则压入辅栈；若val大，则再次压入辅栈栈顶元素。
			这样：
			（1）保证了这个新定义的数据结构是一个栈，即满足先进后出，不论多小，
			只要被压到栈的下面，就不会在下一次出栈是被弹出。
			（2）辅助栈的这种设计，使得min一定在栈顶。
			*/
		}

		void pop() {
			assert(this->stack_main.size() > 0 && this->stack_aux.size() > 0);
			this->stack_main.pop();
			this->stack_aux.pop();
			/*
			1.模块化设计=良好的鲁棒性。这里的assert()语句就体现了这一点。在用
			stack时，我们常有if(i < stack.size) {...}的判断语句以防止越界出错。
			于是，在实现这个函数时，就不想加assert()——因为使用时已经做了预防。
			但，这样写出的代码鲁棒性不好。假如有人没有预防越界，就直接使用了这
			个代码，那就会导致崩溃。
			还有一个例子，是在写list时，我在main()中写的list是具有头结点的，所以
			在其对应的各种函数中就不去考虑头指针为nullptr的情形。这样写的代码，耦合性
			非常高，你写出的各种list方法是不能迁移的——如果有人使用了你的方法，但
			不像你一样在main()中那样为list初始化一个头结点，那程序就会崩溃。
			一个好习惯是：写代码就要写出可被直接调用的模块。要考虑各种输入。而不要
			把各种方法写的耦合。要保证随便拿出一个方法，就能迁移到别的代码中。

			2.assert(条件语句);如果条件为真，则运行后续。否则中断，打印错误。
			assert(this->stack_main.size() > 0 && this->stack_aux.size() > 0);
			不如：
			assert(this->stack_main.size() > 0);
			assert(this->stack_aux.size() > 0);
			因为下面这样的写法能打印出更具体的错误。
			assert()是常用的调试手段。
			*/
		}

		int size() {
			assert(this->stack_main.size() == this->stack_aux.size());
			return this->stack_main.size();
		}

		T & top() {
			assert(this->stack_main.size() > 0);
			return this->stack_main.top();
		}

		bool empty() {
			assert(this->stack_main.size() >= 0 && this->stack_aux.size() >= 0);
			if(this->stack_main.size() > 0 && this->stack_aux.size() > 0) return false;
			else return true;
		}

		T & min() {
			assert(this->stack_aux.size() > 0);
			return this->stack_aux.top();
		}

	private :
		stack<T> stack_main; //主栈
		stack<T> stack_aux; //辅栈
};
int main() {
	stack_with_min<int> stack;
	stack.push(20);
	stack.push(100);
	stack.push(15);
	stack.push(30);
	stack.push(60);
	stack.push(10);
	stack.push(0);
	cout << stack.min() << endl;
	
	stack.pop();
	cout << stack.min() << endl;
	
	stack.pop();
	cout << stack.min() << endl;
	
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	stack.pop();
	
	cout << stack.top() << endl;
	
	return 0;
}
