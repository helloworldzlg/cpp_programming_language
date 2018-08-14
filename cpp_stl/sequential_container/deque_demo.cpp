//
// Created by zlg on 18-8-14.
//
#include <iostream>
#include <deque>

using namespace std;

void printDeq(deque<int>& t)
{
    for (int i = 0; i < t.size(); ++i)
        cout << "t[" << i << "] = " << t[i] << endl;
}

// 构造deque对象
void example_01()
{
    deque<int> deqInts1;
    printDeq(deqInts1);

    deque<int> deqInts2(10);
    printDeq(deqInts2);

    deque<int> deqInts3(10, 90);
    printDeq(deqInts3);

    deque<int> deqInts4(deqInts3);
    printDeq(deqInts4);

    deque<int> deqInts5(deqInts3.cbegin(), deqInts3.cbegin()+5);
    printDeq(deqInts5);
}

// deque对象插入元素
void example_02()
{
    deque<int> deqInts1;

    //从头部插入元素
    for (int i = 0; i < 5; ++i)
        deqInts1.push_front(i*10);
    printDeq(deqInts1);

    //从尾部插入元素
    for (int i = 0; i < 5; ++i)
        deqInts1.push_back(i*10 + 1);
    printDeq(deqInts1);

    //从指定位置插入元素
    for (int i = 0; i < 5; ++i)
        deqInts1.insert(deqInts1.cbegin()+5, 100);
    printDeq(deqInts1);
}

// deque对象删除元素
void example_03()
{
    deque<int> deqInts1;

    //插入元素
    for (int i = 0; i < 15; ++i)
        deqInts1.push_back(i*10);
    printDeq(deqInts1);

    //从头部删除元素
    for (int i = 0; i < 5; ++i)
        deqInts1.pop_front();
    printDeq(deqInts1);

    //从尾部删除元素
    for (int i = 0; i < 5; ++i)
        deqInts1.pop_back();
    printDeq(deqInts1);

    //删除指定位置的元素
    for (int i = 0; i < 2; ++i)
        deqInts1.erase(deqInts1.cbegin()+2);
    printDeq(deqInts1);
}

// deque访问元素
void example_04()
{
    deque<int> deqInts1;

    //插入元素
    for (int i = 0; i < 10; ++i)
        deqInts1.push_back(i*10);
//    printDeq(deqInts1);

    //下标的方式访问
    for (int i = 0; i < deqInts1.size(); ++i)
        cout << "deqInts1[" << i << "] = " << deqInts1[i] << endl;

    //迭代器的方式访问
    deque<int>::iterator itInts = deqInts1.begin();
    while (itInts != deqInts1.end())
    {
        cout << *itInts << endl;
        itInts++;
    }
}

//观察大小
void example_05()
{
    deque<int> deqInts1;

    //插入元素
    for (int i = 0; i < 32; ++i)
    {
        cout << "size: " << deqInts1.size() << endl;
        deqInts1.push_back(i * 10);
    }
}

int main()
{
    example_05();
    return 0;
}