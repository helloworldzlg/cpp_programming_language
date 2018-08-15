//
// Created by zlg on 18-8-14.
//
#include <iostream>
#include <set>

using namespace std;

template <typename T>
void DisplayContents(const T& Input)
{
    for (auto iElement = Input.cbegin(); iElement != Input.cend(); ++iElement)
    {
        cout << *iElement << endl;
    }
    cout << endl;
}

template <typename T>
struct SortDescending
{
    bool operator()(const T& lhs, const T& rhs)
    {
        return (lhs > rhs);
    }
};

// 构造set对象
void example_01()
{
    set<int> setInts1;
    multiset<int> msetInts1;

    set<int, SortDescending<int>> setInts2;
    multiset<int, SortDescending<int>> msetInts2;

    set<int> setInts3(setInts1);
    multiset<int> msetInts3(msetInts1);
}

// set对象插入元素
void example_02()
{
    set<int> setInts;
    multiset<int> msetInts;

    setInts.insert(60);
    setInts.insert(-1);
    setInts.insert(2000);

    DisplayContents(setInts);

    msetInts.insert(setInts.cbegin(), setInts.cend());
    msetInts.insert(2000);
    DisplayContents(msetInts);

    cout << "msetInts 2000 count: " << msetInts.count(2000) << endl;
}

// set对象删除元素
void example_03()
{
    set<int> setInts;
    multiset<int> msetInts;

    setInts.insert(60);
    setInts.insert(-1);
    setInts.insert(2000);

    DisplayContents(setInts);

    msetInts.insert(setInts.cbegin(), setInts.cend());
    msetInts.insert(2000);
    DisplayContents(msetInts);

    //删除有3种方式
    // 1.提供key
    // 2.提供特定的迭代器
    // 3.提供迭代器的区域
    setInts.erase(2000);
    DisplayContents(setInts);
    setInts.erase(setInts.cbegin());
    DisplayContents(setInts);
    setInts.erase(setInts.cbegin(), setInts.cend());
    DisplayContents(setInts);
}

// set对象查找元素
void example_04()
{
    set<int> setInts;
    multiset<int> msetInts;

    setInts.insert(60);
    setInts.insert(-1);
    setInts.insert(2000);

    DisplayContents(setInts);

    msetInts.insert(setInts.cbegin(), setInts.cend());
    msetInts.insert(2000);
    DisplayContents(msetInts);

    auto iElement = msetInts.find(2000);
    if (iElement != msetInts.end())
        cout << "find 2000 success" << endl;
    else
        cout << "can't find 2000" << endl;
}


int main()
{
    example_04();
    return 0;
}
