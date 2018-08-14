//
// Created by zlg on 18-8-14.
//
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test
{
public:
    Test(int a = 100) : m_a(a)
    {}

    ~Test()
    { cout << "Test destructor" << endl; }

public:
    int m_a;
};

// auto_ptr标准用法
void example_01()
{
    cout << __func__ << " start!" << endl;

    std::auto_ptr<Test> aptr1(new Test(100));

    cout << __func__ << " end!" << endl;
    return;
}

// 多个auto_ptr指针指向同一个对象时
void example_02()
{
    cout << __func__ << " start!" << endl;

    std::auto_ptr<Test> aptr1(new Test(100));
    std::auto_ptr<Test> aptr2(aptr1);

    cout << __func__ << " end!" << endl;
    return;
}

// auto_ptr Issue1: 值传递时浅拷贝
void Fun(std::auto_ptr<Test> p)
{
    cout << p->m_a << endl;
}

void example_03()
{
    cout << __func__ << " start!" << endl;

    std::auto_ptr<Test> aptr1(new Test(100));
    Fun(aptr1);
//    cout << aptr1->m_a << endl; //error: aptr1 is released in Fun()

    cout << __func__ << " end!" << endl;
    return;
}

// auto_ptr Issue2: 不能应用在集合对象上
void example_04()
{
    cout << __func__ << " start!" << endl;

//    std::auto_ptr<Test> aptr1(new Test[5]); //error: Test[5] need delete[]

    cout << __func__ << " end!" << endl;
    return;
}

// auto_ptr Issue3: 不能和标准容器(vector, list, map....)一起使用
void example_05()
{
    cout << __func__ << " start!" << endl;

    std::auto_ptr<vector<Test>> aptr1(new vector<Test>);

    cout << __func__ << " end!" << endl;
    return;
}

int main(int argc, char** argv)
{
    example_01();
    example_02();
    example_03();
    example_04();

    return 0;
}