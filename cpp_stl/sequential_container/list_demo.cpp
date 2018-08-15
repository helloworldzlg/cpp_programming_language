//
// Created by zlg on 18-8-14.
//
#include <iostream>
#include <list>

using namespace std;

void printList(list<int>& t)
{
    int i = 0;
    list<int>::const_iterator cIter = t.cbegin();
    while (cIter != t.cend())
    {
        cout << "t[" << i << "] = " << *cIter << endl;
        i++;
        cIter++;
    }
    cout << endl;
}

// 构造list对象
void example_01()
{
    list<int> listInts1;
    printList(listInts1);

    list<int> listInts2(10);
    printList(listInts2);

    list<int> listInts3(10, 100);
    printList(listInts3);

    list<int> listInts4(listInts3);
    printList(listInts4);

    list<int> listInts5(listInts3.cbegin(), listInts3.cend());
    printList(listInts5);
}

// 插入元素
void example_02()
{
    list<int> listInts;

    //从头部插入元素
    for (int i = 0; i < 10; ++i)
        listInts.push_front((9-i)*10);
    printList(listInts);

    //从尾部插入元素
    for (int i = 0; i < 10; ++i)
        listInts.push_back(i*10 + 100);
    printList(listInts);

    //从指定位置插入元素
    for (int i = 0; i < 5; ++i)
        listInts.insert(listInts.cbegin(), 200);
    printList(listInts);
}

// 删除元素
void example_03()
{
    list<int> listInts;

    for (int i = 0; i < 15; ++i)
        listInts.push_back(i*10);
    printList(listInts);

    //从头部删除元素
    for (int i = 0; i < 5; ++i)
        listInts.pop_front();

    //从尾部删除元素
    for (int i = 0; i < 5; ++i)
        listInts.pop_back();

    //从指定位置删除元素
    for (int i = 0; i < 2; ++i)
        listInts.erase(listInts.cbegin());
}

// 反转list
void example_04()
{
    list<int> listInts;

    for (int i = 0; i < 15; ++i)
        listInts.push_back(i*10);
    printList(listInts);

    listInts.reverse();
    printList(listInts);
}

// 排序list
bool MySort(const int& lsh, const int& rsh)
{
    return (lsh > rsh);
}

void example_05()
{
    list<int> listInts;

    listInts.push_back(10);
    listInts.push_back(60);
    listInts.push_back(30);
    listInts.push_back(-10);
    listInts.push_back(40);
    listInts.push_back(90);

    listInts.sort();
    printList(listInts);

    listInts.sort(MySort);
    printList(listInts);
}

int main()
{
    example_05();
    return 0;
}
