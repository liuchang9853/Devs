/*
��Ŀ������ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�min������
�ڸ�ջ�У�����min��push��pop��ʱ�临�Ӷȶ���O(1)��
1.������Ŀ����Ҫ����չԭ��stack�Ĺ��ܣ���������ʵ��ԭ��stack������չԭ��stack��
������ʹ��ԭ��stack�Ĺ��ܣ�ֱ�ӵ���#include<stack>���ɡ�
2.����˼·�ǣ�ͬʱ������ջ �� ��ջ����ջ����ʵ�ֻ����ġ������ջ��������ջ����
��չ��ջ���ܡ�
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
			��if else����Ǵ���Ĺؼ���
			��valС����ѹ�븨ջ����val�����ٴ�ѹ�븨ջջ��Ԫ�ء�
			������
			��1����֤������¶�������ݽṹ��һ��ջ���������Ƚ���������۶�С��
			ֻҪ��ѹ��ջ�����棬�Ͳ�������һ�γ�ջ�Ǳ�������
			��2������ջ��������ƣ�ʹ��minһ����ջ����
			*/
		}

		void pop() {
			assert(this->stack_main.size() > 0 && this->stack_aux.size() > 0);
			this->stack_main.pop();
			this->stack_aux.pop();
			/*
			1.ģ�黯���=���õ�³���ԡ������assert()������������һ�㡣����
			stackʱ�����ǳ���if(i < stack.size) {...}���ж�����Է�ֹԽ�����
			���ǣ���ʵ���������ʱ���Ͳ����assert()������Ϊʹ��ʱ�Ѿ�����Ԥ����
			��������д���Ĵ���³���Բ��á���������û��Ԥ��Խ�磬��ֱ��ʹ������
			�����룬�Ǿͻᵼ�±�����
			����һ�����ӣ�����дlistʱ������main()��д��list�Ǿ���ͷ���ģ�����
			�����Ӧ�ĸ��ֺ����оͲ�ȥ����ͷָ��Ϊnullptr�����Ρ�����д�Ĵ��룬�����
			�ǳ��ߣ���д���ĸ���list�����ǲ���Ǩ�Ƶġ����������ʹ������ķ�������
			������һ����main()������Ϊlist��ʼ��һ��ͷ��㣬�ǳ���ͻ������
			һ����ϰ���ǣ�д�����Ҫд���ɱ�ֱ�ӵ��õ�ģ�顣Ҫ���Ǹ������롣����Ҫ
			�Ѹ��ַ���д����ϡ�Ҫ��֤����ó�һ������������Ǩ�Ƶ���Ĵ����С�

			2.assert(�������);�������Ϊ�棬�����к����������жϣ���ӡ����
			assert(this->stack_main.size() > 0 && this->stack_aux.size() > 0);
			���磺
			assert(this->stack_main.size() > 0);
			assert(this->stack_aux.size() > 0);
			��Ϊ����������д���ܴ�ӡ��������Ĵ���
			assert()�ǳ��õĵ����ֶΡ�
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
		stack<T> stack_main; //��ջ
		stack<T> stack_aux; //��ջ
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
