# c++标准库

## 1. IO库

## 2. 容器库
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
	插入：从尾部插入元素的速度最快，从中间插入需要的时间与插入位置后面的元素个数成正比，插入操作可能引起整体扩容，此时比较影响性能。
	删除：
	
	
	
	
	
* 迭代器

* 范型算法



## 3. 动态内存