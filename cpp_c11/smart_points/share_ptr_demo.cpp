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
    { cout << "Test constructor" << endl; }

    ~Test()
    { cout << "Test destructor" << endl; }

public:
    int m_a;
};

// shared_ptr标准用法
void example_01()
{
    std::shared_ptr<Test> sptr1 = std::make_shared<Test>(100);
}

// 多个shared_ptr指针指向同一个对象
void example_02()
{
    std::shared_ptr<Test> sptr1 = std::make_shared<Test>(100);
    std::shared_ptr<Test> sptr2 = sptr1;
}

// shared_ptr feature1: 值传递时传递引用，不重新构造对象
void Fun(std::shared_ptr<Test> p)
{
    cout << p->m_a << endl;
}

void example_03()
{
    std::shared_ptr<Test> sptr1 = std::make_shared<Test>(100);
    Fun(sptr1);

    cout << sptr1->m_a << endl;
}

// shared_ptr feature2: 应用在集合对象上,自定义析构策略
void example_04()
{
    std::shared_ptr<Test> sptr1(new Test[5], [](Test* p){delete[] p;});
}

// shared_ptr feature3: 从shared_ptr创建shared_ptr
// only release memory one times
void example_05()
{
    shared_ptr<Test> sptr1 = make_shared<Test>(100);
    shared_ptr<Test> sptr2(sptr1);
    shared_ptr<Test> sptr3(sptr2);
}

// shared_ptr Issue1: 从裸指针创建shared_ptr
void example_06()
{
    Test* p = new Test(100);
    shared_ptr<Test> sptr1(p);  //will release p
    shared_ptr<Test> sptr2(p);  //will release p
}

// shared_ptr Issue2: 循环引用,无法释放内存
class B;
class A
{
public:
    A() : m_sptrB(nullptr)
    { cout<<" A is created"<<endl; }

    ~A()
    { cout<<" A is destroyed"<<endl; }

    shared_ptr<B> m_sptrB;
};

class B
{
public:
    B() : m_sptrA(nullptr)
    { cout<<" B is created"<<endl; }

    ~B()
    { cout<<" B is destroyed"<<endl; }

    shared_ptr<A> m_sptrA;
};

void example_07()
{
    shared_ptr<A> sprtA(new A);
    shared_ptr<B> sprtB(new B);
    sprtA->m_sptrB = sprtB;
    sprtB->m_sptrA = sprtA;
}

int main()
{
//    example_01();
//    example_02();
//    example_03();
//    example_04();
//    example_05();
//    example_06();
    example_07();
    return 0;
}