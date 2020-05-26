/*
��εõ�һ���������е���λ����������������ж�����������ֵ����ô
��λ������������ֵ����֮��λ���м����ֵ��������������ж���ż������ֵ��
��ô��λ������������ֵ����֮���м���������ƽ��ֵ��
��������Ϊ��������ʱ������ڴ�ģ����ݹ�ģ���Ǽȶ��ģ����ǳ��������ġ�
��1������������ɺ������ҳ���λ����������֪������õġ�
��2��������ÿ��ŵ�˼·������λ����ʱ�临�ӶȽ�����������Ҫ������ȫ�������ڴ���ܿ�ʼ��
��3������������������ѣ�ǰһ���Ǵ󶥶ѣ���һ����С���ѡ����������ݴ�0��ʼ���±꣬����
ż�±�������С���ѣ��������±�������󶥶ѣ��������Ա�֤��������������ݣ�������������ֵ
Ϊ0��1������󶥶�ʱ��������ֵ����С�����е���Сֵ������Ԫ�ػ�����ͬ������С����ʱ����
����ֵС�ڴ󶥶��е����ֵ������Ԫ�ػ������Դ˱�֤�󶥶�����������������С��һ�룬С����
������������������һ�롣������������������Ϊż�����򣨴󶥶��е����ֵ+С�����е���Сֵ��/2
��Ϊ��������������������������󶥶��е����ֵ��Ϊ����

��������ѣ���������ǰ�����L[0~n-1]����Ϊһ�š���ȫ����������Ȼ������ɶѡ���ע�⣬����
L->tree������ʵ�ֵģ�ѡȡL[0]Ϊ���ڵ㣬��ѡȡL[1]��L[2]Ϊ�ӽڵ㣬�Դ����ơ���
���ѣ����µ��ϣ������Ŵ����ҵĵ���fnode��lnode��rnode���ߣ���Ҫ�󶥣��Ͱ�fnode��Ϊ����
�е����ֵ��ͬ����ҪС�����Ͱ�fnode��Ϊ�����е���Сֵ�������ӵײ㵽����󣬻���Ҫ���ϵ��£�
�����Ŵ��ҵ���İ�ͬ�����������ֱ��ȫ��������fnode���Ǵ�С������

���룺��Ԫ�ز�����ȫ��������ĩβ��Ȼ�������

ɾ����ɾ��ָ����ɾ���Ѷ�Ԫ�ء�ɾ��ʱ���Ƚ��Ѷ�Ԫ�����β������Ȼ�����[0~n-2]��Ԫ���γ�
�¶ѣ���n-1��Ԫ�ؼ�ΪҪɾ����Ԫ�أ�ע���ʱ��û��ɾ����ֻ�ǲ��ٲ�������������ɾ������
Lɾ�����һ��Ԫ��ʵ�ֵġ�

�ѣ�heap���Ĺ�����·��
#include <vector>
#include <algorithm> //�����ṩheap
#include <functional> //�����ṩless()��greater()

vector<T> v{val_1,val_2,...,val_n};

make_heap(v.begin,v.end); //Ĭ�ϴ����󶥶�
��Ч�ڣ�
make_heap(v.begin,v.end,less<T>());

make_heap(v.begin,v.end,greater<T>()); //����С����

pop_heap(v.begin,v.end,greater<T>()); //ɾ��С���ѶѶ����������ɾ���������Ƶ��˶�β��Ҳ��v.back()����
use v.back(); //������ɾ��ǰʹ��
v.pop_back(); //����ɾ��

v.push_back(val); //vĩ���Ԫ�أ�δ�����heap
use v;
push_heap(v.begin(),v.end(),greater<T>()); //��С���Ѳ���Ԫ��
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
template<class T>
class data_stream_mid {
	public :
		data_stream_mid() {
			make_heap(maxHeap.begin() , maxHeap.end() , less<T>());
			make_heap(minHeap.begin() , minHeap.end() , greater<T>());
		}
		void Insert(T data) {
			if(((this->minHeap.size() + this->maxHeap.size()) & 1) == 0) { //�ȼ���%2
				this->maxHeap.push_back(data);
				push_heap(this->maxHeap.begin() , this->maxHeap.end() , less<T>());
				if(this->minHeap.size() && this->maxHeap[0] > this->minHeap[0]) {
					pop_heap(this->maxHeap.begin() , this->maxHeap.end() , less<T>());
					T max_data = this->maxHeap.back();
					this->maxHeap.pop_back();
					
					pop_heap(this->minHeap.begin() , this->minHeap.end() , greater<T>());
					T min_data = this->minHeap.back();
					this->minHeap.pop_back();
					
					maxHeap.push_back(min_data);
					push_heap(this->maxHeap.begin() , this->maxHeap.end() , less<T>());
					
					minHeap.push_back(max_data);
					push_heap(this->minHeap.begin() , this->minHeap.end() , greater<T>());
				}
			} else {
				this->minHeap.push_back(data);
				push_heap(this->minHeap.begin() , this->minHeap.end() , greater<T>());
				if(this->maxHeap.size() && this->minHeap[0] < this->maxHeap[0]) {
					pop_heap(this->minHeap.begin() , this->minHeap.end() , greater<T>());
					T min_data = this->minHeap.back();
					this->minHeap.pop_back();
					
					pop_heap(this->maxHeap.begin() , this->maxHeap.end() , less<T>());
					T max_data = this->maxHeap.back();
					this->maxHeap.pop_back();
					
					minHeap.push_back(max_data);
					push_heap(this->minHeap.begin() , this->minHeap.end() , greater<T>());
					
					maxHeap.push_back(min_data);
					push_heap(this->maxHeap.begin() , this->maxHeap.end() , less<T>());
				}
			}
		}
		
		T mid_data(){
			if(((this->minHeap.size() + this->maxHeap.size()) & 1) == 0) return (this->minHeap[0] + this->maxHeap[0]) / 2;
			else return this->maxHeap[0];
		}
	private :
		vector<T> maxHeap;
		vector<T> minHeap;
};
/*
����֮���԰ѻ�ȡ����������λ����װ��һ�����У�����Ϊ���Զ���һ������ÿ����һ������
�͵���һ�κ�����Ա�Ի�ȡ��ʱ����λ����������ֻҪ������main()�в�����������������ʼ��
���ܱ���������
����ֻ��д��һ����������ô���޷��������ݵġ�������Ҫ������main()�С�
*/
int main() {
	data_stream_mid<int> m;
	m.Insert(8);
	m.Insert(12);
	m.Insert(0);
	cout << m.mid_data() << endl;
	
	m.Insert(7);
	cout << m.mid_data() << endl;
	
	m.Insert(9);
	m.Insert(17);
	cout << m.mid_data() << endl;
	return 0;
}
