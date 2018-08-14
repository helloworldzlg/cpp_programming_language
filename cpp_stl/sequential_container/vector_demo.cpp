//
// Created by zlg on 18-8-14.
//
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVec(vector<T> &t)
{
    for (int i = 0; i < t.size(); ++i)
        cout << "t[" << i << "] = " << t[i] << endl;
}

// 构造vector对象
void example_01()
{
    vector<int> vecInts1;
    printVec(vecInts1);

    vector<int> vecInts2(10);
    printVec(vecInts2);

    vector<int> vecInts3(10, 90);
    printVec(vecInts3);

    vector<int> vecInts4(vecInts1);
    printVec(vecInts4);

    vector<int> vecInts5(vecInts3.cbegin(), vecInts3.cbegin()+5);
    printVec(vecInts5);
}

// 插入元素
void example_02()
{
    vector<int> vecInts;

    //从尾部插入元素
    for (int i = 0; i < 10; ++i)
        vecInts.push_back(10*i);
    printVec(vecInts);

    //从指定位置插入元素
    vecInts.insert(vecInts.cbegin()+5, 100);
    vecInts.insert(vecInts.cbegin()+6, 4, 100);
    printVec(vecInts);
}

// 删除元素
void example_03()
{
    vector<int> vecInts;

    //从尾部插入元素
    for (int i = 0; i < 15; ++i)
        vecInts.push_back(10*i);
    printVec(vecInts);

    //从尾部删除元素
    for (int i = 0; i < 5; ++i)
        vecInts.pop_back();
    printVec(vecInts);

    //删除指定位置元素
    for (int i = 0; i < 5; ++i)
        vecInts.erase(vecInts.cbegin());
    printVec(vecInts);
}

// 访问元素
void example_04()
{
    vector<int> vecInts;

    //从尾部插入元素
    for (int i = 0; i < 10; ++i)
        vecInts.push_back(10*i);

    //使用下标的方式访问元素
    for (int i = 0; i < vecInts.size(); ++i)
        cout << "vecInts[" << i << "] = " << vecInts[i] << endl;

    //使用迭代器的方式访问元素
    vector<int>::iterator itInt = vecInts.begin();
    while (itInt != vecInts.end())
    {
        cout << *itInt << endl;
        itInt++;
    }
}

// 观察大小和容量
void example_05()
{
    vector<int> vecInts;

    for (int i = 0; i < 32; ++i)
    {
        cout << "capacity: " << vecInts.capacity() << endl;
        cout << "size: " << vecInts.size() << endl;
        vecInts.push_back(i);
    }
}

int main()
{
    example_05();
    return 0;
}