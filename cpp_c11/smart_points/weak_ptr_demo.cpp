//
// Created by zlg on 18-8-14.
//
#include <iostream>
#include <memory>

using namespace std;

// weak_ptr标准使用
// 与 shared_ptr搭配，解决循环引用无法释放内存的问题
class B;
class A
{
public:
    A() : m_a(5)
    { cout<<" A is created"<<endl; }

    ~A()
    { cout<<" A is destroyed"<<endl; }

    void printSpb();

    int m_a;
    weak_ptr<B> m_sptrB;
};

class B
{
public:
    B() : m_b(10)
    { cout<<" B is created"<<endl; }

    ~B()
    { cout<<" B is destroyed"<<endl; }

    int m_b;
    weak_ptr<A> m_sptrA;
};

void A::printSpb()
{
    if (!m_sptrB.expired())
    {
        cout << m_sptrB.lock()->m_b << endl;
    }
}

void example_01()
{
    shared_ptr<A> sptrA = make_shared<A>();
    shared_ptr<B> sptrB = make_shared<B>();
    sptrA->m_sptrB = sptrB;
    sptrB->m_sptrA = sptrA;
    sptrA->printSpb();
}

int main()
{
    example_01();

    return 0;
}