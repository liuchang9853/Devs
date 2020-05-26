/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
那么中位数就是所有数值排序之后中间两个数的平均值。
解析：因为数据是随时间进入内存的，数据规模不是既定的，而是持续增长的。
（1）如果在输出完成后，排序，找出中位数。这可想而知是最不经济的。
（2）如果利用快排的思路，找中位数，时间复杂度降了下来，但要求数据全部进入内存才能开始。
（3）如果我们设置两个堆，前一个是大顶堆，后一个是小顶堆。输入流数据从0开始做下标，遇到
偶下标则置入小顶堆，遇到奇下标则置入大顶堆，这样可以保证不论输入多少数据，总有数据数差值
为0或1。输入大顶堆时，若输入值大于小顶堆中的最小值，则两元素互换；同理，输入小顶堆时，若
输入值小于大顶堆中的最大值，则两元素互换。以此保证大顶堆中总是输入流中最小的一半，小顶堆
中总是输入流中最大的一半。这样，若输入数据数为偶数，则（大顶堆中的最大值+小顶堆中的最小值）/2
即为所求；若输入数据数是奇数，则大顶堆中的最大值即为所求。

先来回忆堆：堆排序就是把序列L[0~n-1]构建为一颗【完全二叉树】，然后调整成堆。（注意，这里
L->tree是这样实现的，选取L[0]为根节点，再选取L[1]、L[2]为子节点，以此类推。）
建堆：从下到上，伴随着从左到右的调整fnode、lnode、rnode三者，若要大顶，就把fnode换为三者
中的最大值；同理，若要小顶，就把fnode换为三者中的最小值。这样从底层到顶层后，还需要从上到下，
伴随着从右到左的按同样规则调整，直至全树的所有fnode都是大（小）顶。

插入：新元素插入完全二叉树的末尾，然后调整。

删除：删除指的是删除堆顶元素。删除时，先将堆顶元素与堆尾互换，然后调整[0~n-2]个元素形成
新堆，第n-1个元素即为要删除的元素（注意此时还没有删除，只是不再参与调整）。最后删除，是
L删除最后一个元素实现的。

堆（heap）的构建套路：
#include <vector>
#include <algorithm> //用于提供heap
#include <functional> //用于提供less()和greater()

vector<T> v{val_1,val_2,...,val_n};

make_heap(v.begin,v.end); //默认创建大顶堆
等效于：
make_heap(v.begin,v.end,less<T>());

make_heap(v.begin,v.end,greater<T>()); //创建小顶堆

pop_heap(v.begin,v.end,greater<T>()); //删除小顶堆堆顶（不是真的删除，而是移到了堆尾，也即v.back()。）
use v.back(); //在真正删除前使用
v.pop_back(); //真正删除

v.push_back(val); //v末添加元素，未添加至heap
use v;
push_heap(v.begin(),v.end(),greater<T>()); //向小顶堆插入元素
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
			if(((this->minHeap.size() + this->maxHeap.size()) & 1) == 0) { //等价于%2
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
这里之所以把获取数据流的中位数封装到一个类中，是因为可以定义一个对象，每输入一个数据
就调用一次函数成员以获取即时的中位数。这样，只要对象在main()中不被析构，则其数据始终
都能保存下来。
但若只是写了一个函数，那么是无法保存数据的。数据需要保存在main()中。
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
