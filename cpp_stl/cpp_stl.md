# c++标准库

## 1. 容器 container
* 容器
	概念：用来存储某种类型的数据
	分类：顺序容器、关联容器
	* 顺序容器
		* vector
		* deque
		* list、forward_list
	
	* 关联容器
		* set
		* multi_set
		* map
		* multi_map
		* unordered_set
		* unordered_multiset
		* unordered_map
		* unordered_multimap
	
	* 成员函数
		* 返回迭代器
		* begin/cbegin
		* end/cend
		* rbegin
		* rend
		* 返回元素引用
		* front
		* back
		* erase（删除区间时返回被删除元素后面的迭代器；也可删除一个或几个元素）
		* clear
		* push_back
		* pop_back

	上述容器从插入、删除、访问需要的时间进行对比，作为选型参考：
	
	1) vector
	vector底层由数组实现，从尾部插入和删除元素的速度最快，从中间位置插入和删除需要的时间与插入位置后面的元素
	个数成正比，插入操作可能引起整体扩容，此时比较影响性能。
	
	2) deque
	deque的底层实现为一个中央控制器和多个缓冲区，支持首尾快速插入和删除，也支持快速随机访问。
	
	3) list
	
	
	
## 2. 迭代器 iterator
	
## 3. 范型算法 algorthm

## 4. 适配器 adaptor

## 5. 函数对象 function object

## 6. 分配器 allocator