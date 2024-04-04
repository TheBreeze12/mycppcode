#include <iostream>
#include <string>
using namespace std;
// 用数组实现栈
int maxsize = 10;
template <class T>
class mystack
{
public:
    T *data;
    int top;
    T min;

public:
    mystack()
    {
        data = new T[maxsize];
        top = -1;
    }
    ~mystack()
    {
        delete[] data;
    }
    void push(T e)
    {
        if (top + 1 < maxsize)
        {
            top++;
            data[top] = e;
        }
    }
    void pop()
    {
        if (!empty())
            top--;
    }
    bool empty()
    {
        return top == -1;
    }
    T gettop()
    {
        T a;
        if (top != -1)
            a = data[top];
        return a;
    }
};
// 判断是否回文
bool fun(string str)
{
    mystack<char> s;
    int i = 0;
    while (i < str.length() / 2)
    {
        s.push(str[i]);
        i++;
    }
    if (str.length() % 2 == 1)
        i++;
    while (i < str.length())
    {
        if (s.empty())
            return 0;
        if (str[i] != s.gettop())
            return 0;
        s.pop();
        i++;
    }
    return 1;
}
// 用链表实现栈
template <class T>
class node
{
public:
    T val;
    node<T> *next;

public:
    node<T>()
    {
        next = nullptr;
    }
    node<T>(T e) : val(e), next(nullptr){};
};
template <class T>
class linkstack
{
    node<T> *head;

public:
    linkstack()
    {
        head = new node<T>();
    }
    ~linkstack()
    {
        node<T> *pre, *p;
        pre = head;
        p = pre->next;
        while (p != nullptr)
        {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }
    void push(T e)
    {
        node<T> *s = new node<T>(e);
        s->next = head->next;
        head->next = s;
    }
    bool empty()
    {
        return head->next == nullptr;
    }
    void pop()
    {
        if (!empty())
        {
            node<T> *s = head->next;
            head->next = s->next;
            delete s;
        }
    }
    T top()
    {
        return head->next->val;
    }
};
int main0()
{
    mystack<int> v;
    v.push(10);
    v.push(100);
    v.push(96);
    return 0;
    // string s;
    // cin >> s;
    // if (fun(s))
    //     cout << "回文" << endl;
    // else
    //     cout << "不回文" << endl;
}
// 用循环链表实现栈

template <class T>
class dlinkstack
{
    node<T> *rear;

public:
    dlinkstack() { rear = nullptr; }
    ~dlinkstack()
    {
        if (rear == nullptr)
            return;
        else if (rear->next == rear)
        {
            delete rear;
            return;
        }
        else
        {
            node<T> *pre, *p;
            pre = rear->next;
            p = pre->next;
            while (p != rear)
            {
                delete pre;
                pre = p;
                p = p->next;
            }
            delete pre;
            delete p;
        }
    }
    bool empty()
    {
        return rear == nullptr;
    }
    void push(T &e)
    {
        node<T> *s = new node<T>(e);
        if (empty())
        {
            rear = s;
            s->next = rear;
        }
        else
        {
            s->next = rear->next;
            rear->next = s;
        }
    }
    void pop()
    {
        node<T> *s = rear->next;

        if (empty())
            return;
        if (rear->next == rear)
        {
            s = rear;
            rear = nullptr;
            delete s;
        }
        else
        {
            rear->next = s->next;
            delete s;
        }
    }
    T top()
    {
        if (!empty())
            return rear->next->val;
        else
            return 0;
    }
    T bottom()
    {
        if (!empty())
            return rear->val;
        else
            return 0;
    }
};

int main1()
{
    linkstack<int> s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i);
    }
    for (int i = 1; i <= 5; i++)
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 1;
}

int main()
{
    dlinkstack<int> s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i);
    }
    for (int i = 1; i <= 5; i++)
    {
        cout << s.top() << endl
             << s.bottom() << endl;
        s.pop();
    }
    return 1;
}