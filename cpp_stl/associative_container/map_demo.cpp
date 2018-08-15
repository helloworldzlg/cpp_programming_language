//
// Created by zlg on 18-8-14.
//
#include <iostream>
#include <map>

using namespace std;

typedef map<int, string> MAP_INT_STRING;
typedef multimap<int, string> MMAP_INT_STRING;

template <typename T>
void DisplayContents(const T& Input)
{
    for (auto iElement = Input.cbegin(); iElement != Input.cend(); ++iElement)
    {
        cout << iElement->first << " -> " << iElement->second << endl;
    }
    cout << endl;
}

template <typename KeyType>
struct ReverseSort
{
    bool operator()(const KeyType& key1, const KeyType& key2)
    {
        return (key1 > key2);
    }
};

// 构造map对象
void example_01()
{
    map<int, string> mapIntToStr1;
    map<int, string> mapIntToStr2(mapIntToStr1);
    map<int, string> mapIntToStr3(mapIntToStr1.cbegin(), mapIntToStr1.cend());
    map<int, string, ReverseSort<int>> mapIntToStr4(mapIntToStr1.cbegin(), mapIntToStr1.cend());

    multimap<int, string> mmapIntToStr1;
    multimap<int, string> mmapIntToStr2(mmapIntToStr1);
    multimap<int, string> mmapIntToStr3(mmapIntToStr1.cbegin(), mmapIntToStr1.cend());
    multimap<int, string, ReverseSort<int>> mmapIntToStr4(mmapIntToStr1.cbegin(), mmapIntToStr1.cend());
}

// map对象插入
void example_02()
{
    MAP_INT_STRING mapToStr;

    mapToStr.insert(MAP_INT_STRING::value_type(3, "three"));
    mapToStr.insert(make_pair(1, "one"));
    mapToStr.insert(pair<int, string>(2, "two"));
    mapToStr[4] = "four";
    DisplayContents(mapToStr);
}

// map对象元素删除
void example_03()
{
    MAP_INT_STRING mapToStr;

    mapToStr.insert(MAP_INT_STRING::value_type(3, "three"));
    mapToStr.insert(make_pair(1, "one"));
    mapToStr.insert(pair<int, string>(2, "two"));
    mapToStr[4] = "four";
    DisplayContents(mapToStr);

    mapToStr.erase(1);
    DisplayContents(mapToStr);

    mapToStr.erase(mapToStr.cbegin());
    DisplayContents(mapToStr);

    mapToStr.erase(mapToStr.cbegin(), mapToStr.cend());
    DisplayContents(mapToStr);
}

// map对象查找
void example_04()
{
    MAP_INT_STRING mapToStr;

    mapToStr.insert(MAP_INT_STRING::value_type(3, "three"));
    mapToStr.insert(make_pair(1, "one"));
    mapToStr.insert(pair<int, string>(2, "two"));
    mapToStr[4] = "four";
    DisplayContents(mapToStr);

    auto iElement = mapToStr.find(2);
    if (iElement != mapToStr.cend())
        cout << "2 find in mapToStr, velue: " << iElement->second << endl;
    else
        cout << "can't find 2 in mapToStr" << endl;
}

int main()
{
    example_04();

    return 0;
}
