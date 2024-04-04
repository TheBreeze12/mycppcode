
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// #include<vector>

using namespace std;
template <class T>
class Node
{
public:
    T val;
    Node<T> *next;

public:
    Node<T>() { next = nullptr; };
    Node<T>(T e, Node<T> *ptr = nullptr) : val(e), next(ptr){};
};

template <class T>
class list
{
private:
    Node<T> *head;
    int size = 0;

public:
    list<T>()
    {
        Node<T> *s = new Node<T>();
        head = s;
    }
    ~list()
    {
        Node<T> *p = head;
        while (p != nullptr)
        {
            Node<T> *s = p;
            p = p->next;
            delete s;
        }
        head = nullptr;
        size = 0;
    }
    list<T> &operator=(list<T> &l2)
    {
        while (size)
        {
            deletem(size - 1);
        }
        for (int i = 0; i < l2.getsize(); i++)
        {
            this->insertback(l2.geti(i)->val);
        }
        return *this;
    }
    void insertfront(T e)
    {

        Node<T> *s = new Node<T>(e);
        s->next = head->next;
        head->next = s;
        size++;
    }

    void insertback(T e)
    {
        Node<T> *p = head;
        while (p->next != nullptr)
            p = p->next;
        Node<T> *s = new Node<T>(e);
        p->next = s;
        size++;
    }

    Node<T> *geti(int i)
    {
        if (i < -1 || i >= size)
            return nullptr;
        int j = -1;
        Node<T> *p = head;
        while (j < i)
        {
            j++;
            p = p->next;
        }
        return p;
    }

    void insert(int i, T e)
    {
        if (i < 0 || i >= size)
            return;
        Node<T> *s = geti(i - 1);
        Node<T> *temp = new Node<T>(e);
        temp->next = s->next;
        s->next = temp;
        size++;
    }
    void deletem(int i)
    {
        Node<T> *p = geti(i - 1);
        Node<T> *s = geti(i);
        p->next = s->next;
        delete s;
        size--;
    }

    bool getielement(int i, T &e)
    {
        if (i < 0 || i >= size)
            return 0;
        e = geti(i)->val;
        return 1;
    }

    bool seti(int i, T e)
    {
        if (i < 0 || i >= size)
            return 0;
        geti(i)->val = e;
        return 1;
    }

    int getsize()
    {
        return size;
    }
    // 总结的1和2  两种遍历算法  while停止后  插入删除时用p->next在等号前面；
    void printall()
    {
        // Node<T> *p = head->next;
        // while (p != nullptr)
        // {
        //     cout << p->val << ' ';
        //     p = p->next;
        // }
        // cout << endl;

        Node<T> *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
            cout << p->val << ' ';
        }
        cout << endl;
    }

    void sort()
    {
        auto data = new T[size];
        Node<T> *p = head->next;
        for (int i = 0; p != nullptr; p = p->next, i++)
        {
            data[i] = p->val;
        }
        for (int i = 0; i < size - 1; i++)
        {
            int index = i;
            for (int j = i + 1; j < size; j++)
            {
                if (data[j] < data[index])
                    index = j;
            }
            swap(data[index], data[i]);
        }
        p = head->next;
        for (int i = 0; p != nullptr; p = p->next, i++)
        {
            p->val = data[i];
        }
        delete[] data;
    }
    void merge(list<T> &l1, list<T> &l2, list<T> &l3)
    {

        Node<T> *p = l1.head->next;
        Node<T> *s = l2.head->next;
        for (; p != nullptr && s != nullptr;)
        {
            if (p->val < s->val)
            {
                l3.insertback(p->val);
                p = p->next;
            }
            else if (p->val >= s->val)
            {
                l3.insertback(s->val);
                s = s->next;
            }
            // else if (p->val == s->val)
            // {
            //     p = p->next;
            // }
        }
        while (p != nullptr)
        {
            l3.insertback(p->val);
            p = p->next;
        }
        while (s != nullptr)
        {
            l3.insertback(s->val);
            s = s->next;
        }
    }
    void delecf()
    {
        Node<T> *p = head->next, *s;
        while (p->next != nullptr)
        {
            s = p->next;

            if (s->val == p->val)
            {
                p->next = s->next;
                delete s;
            }
            else
            {
                p = p->next;
            }
        }
    }
};

template <class T>
list<T> &inter(list<T> &l1, list<T> &l2)
{
    static list<T> l;

    for (int i = 0; i < l1.getsize(); i++)
    {
        for (int j = 0; j < l2.getsize(); j++)
        {
            T a = l1.geti(i)->val;
            T b = l2.geti(j)->val;

            if (l1.geti(i)->val == l2.geti(j)->val)
                l.insertback(a);
        }
    }
    return l;
}

void f()
{
    list<int> l1;
    list<int> l2;
    list<int> l3;
    int a;
    string s;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> a)
    {
        l1.insertback(a);
    }
    getline(cin, s);
    stringstream ss2(s);

    while (ss2 >> a)
    {
        l2.insertback(a);
    }
    l1.sort();
    l2.sort();
    l1.merge(l1, l2, l3);
    l3.delecf();
    l3.printall();
}

int main()
{

    // l1.insertback(1);
    // l1.insertback(4);
    // l1.insertback(6);
    // l1.insertback(3);
    // l1.insertback(4);
    // l1.insertback(9);
    // l2.insertback(5);
    // l2.insertback(7);
    // l2.insertback(3);
    // l2.insertback(4);
    // l2.insertback(8);
    // l2.insertback(9);
    f();
}