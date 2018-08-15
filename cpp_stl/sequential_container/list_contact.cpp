//
// Created by zlg on 18-8-15.
//
#include <iostream>
#include <list>

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

struct ContactItem
{
    string m_strName;
    string m_strNum;
    string m_strDisplayInfo;

    ContactItem(const string& strName, const string& strNum)
    {
        m_strName = strName;
        m_strNum  = strNum;
        m_strDisplayInfo = strName + ": " + strNum;
    }

    bool operator == (const ContactItem& itemToCmp) const
    {
        return (itemToCmp.m_strName == this->m_strName);
    }

    bool operator < (const ContactItem& itemToCmp) const
    {
        return (this->m_strName < itemToCmp.m_strName);
    }

    operator const char*() const
    {
        return m_strDisplayInfo.c_str();
    }
};

// 按num升序排列
bool MySort(const ContactItem& item1, const ContactItem& item2)
{
    return (item1.m_strNum < item2.m_strNum);
}

int main()
{
    list<ContactItem> contacts;

    contacts.push_back(ContactItem("wh", "1234"));
    contacts.push_back(ContactItem("zlg", "3452"));
    contacts.push_back(ContactItem("zhang", "5264"));
    contacts.push_back(ContactItem("li", "2346"));
    contacts.push_back(ContactItem("gui", "7654"));
    contacts.push_back(ContactItem("liu", "3456"));

    DisplayContents(contacts);

    contacts.sort();
    DisplayContents(contacts);

    contacts.sort(MySort);
    DisplayContents(contacts);

    contacts.remove(ContactItem("zlg", ""));
    DisplayContents(contacts);

    return 0;
}
