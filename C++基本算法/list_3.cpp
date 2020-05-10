/*
��Ŀ��������ջʵ�ֶ��С�
��ӣ���Ԫ����stack1��
���ӣ�
	��Ԫ�س�stack2��
		��stack2��Ϊ�գ�ֱ��pop()��
		��stack2Ϊ�գ���stack1�е�����Ԫ����һ��stack2����pop()��
*/
#include <iostream>
#include <stack>

using namespace std;
//��Ŀ������CQueue
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
			T& data = stack1.top(); //ע��1
			stack1.pop();
			stack2.push(data);
		}
	}

	if(stack2.size() == 0)
		exit(1);
	/*
	exit��0�����������г����˳�����
	exit��1�������������е����˳�����
	*/

	T head = stack2.top(); //ע��2
	stack2.pop();

	return head;
}
/*
ע��1 �� ע��2����������&��ԭ���ǣ���T& data = stack1.top();���ɿ���top()�ڲ��Ļ���
��ָ�룬��stack1.pop();���������ǻ��տռ� �� --ptr�����ﲻ������Ҳ���ԡ�
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
