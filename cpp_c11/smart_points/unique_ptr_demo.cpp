//
// Created by zlg on 18-8-14.
//
#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
    Test(int a = 100) : m_a(a)
    { cout << "Test constructor" << endl; }

    ~Test()
    { cout << "Test destructor" << endl; }

public:
    int m_a;
};

// unique_ptr 标准用法
void example_01()
{
    unique_ptr<Test> uptr1(new Test());
}

// 多个unique_ptr指针指向同一个对象,不允许
void example_02()
{
    unique_ptr<Test> uptr1(new Test());
    //unique_ptr<Test> uptr2(uptr1); //error
}

// unique_ptr指针指向另外的对象
void example_03()
{
    unique_ptr<Test> uptr1(new Test(100));
    unique_ptr<Test> uptr2 = move(uptr1);
//    cout << uptr1->m_a << endl; //error uptr1 has released ownship
    cout << uptr2->m_a << endl;
}

int main()
{
//    example_01();
//    example_02();
    example_03();

    return 0;
}