/*
题目：用两个栈实现队列。
入队：逐元素入stack1。
出队：
	逐元素出stack2。
		若stack2不为空，直接pop()。
		若stack2为空，将stack1中的所有元素逐一入stack2，再pop()。
*/
#include <iostream>
#include <stack>

using namespace std;
//题目给出的CQueue
template <typename T> class CQueue {
	public:
		CQueue(void);
		~CQueue(void);
		void appendTail(const T& node);
		T deleteHead();
	private:
		stack<T> stack1;
		stack<T> stack2;
};
//stack->queue
template <typename T> CQueue<T>::CQueue(void) {}

template <typename T> CQueue<T>::~CQueue(void) {}

template<typename T> void CQueue<T>::appendTail(const T& element) {
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead() {
	if(stack2.size()<= 0) {
		while(stack1.size()>0) {
			T& data = stack1.top(); //注意1
			stack1.pop();
			stack2.push(data);
		}
	}

	if(stack2.size() == 0)
		exit(1);
	/*
	exit（0）：正常运行程序并退出程序；
	exit（1）：非正常运行导致退出程序；
	*/

	T head = stack2.top(); //注意2
	stack2.pop();

	return head;
}
/*
注意1 和 注意2的区别在于&。原因是：由T& data = stack1.top();语句可看出top()内部的机制
是指针，而stack1.pop();的作用则是回收空间 并 --ptr。这里不用引用也可以。
*/
int main() {
	CQueue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	char head_1 = queue.deleteHead();

	queue.appendTail('c');
	queue.appendTail('d');
	queue.appendTail('e');
	queue.appendTail('f');
	char head_2 = queue.deleteHead();
	char head_3 = queue.deleteHead();

	cout << head_1 << ends << head_2 << ends << head_3 << endl;
	return 0;
}
