#include <iostream>
#include <string>
#include <fstream>
// #include<list>
using namespace std;

class node
{
public:
    int *data;
    node *next;
    int col;

public:
    node() { next = nullptr; };
    node(int n)
    {
        data = new int[n];
        next = nullptr;
        col = n;
    }

    // node(int *a, int n)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         data[i] = a[i];
    //     }
    //     next = nullptr;
    //     col = n;
    // }
};

class list
{
public:
    node *head;

public:
    list()
    {
        head = new node();
    }
    ~list()
    {
        node *pre = head, *p = head->next;
        while (p != nullptr)
        {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }
    void pushback(node &n)
    {
        auto s = new node(n.col);
        for (int i = 0; i < n.col; i++)
        {
            s->data[i] = n.data[i];
        }
        node *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = s;
    }
};

void printall(node *p1, node *p2, fstream &fout)
{
    // cout << 111 << endl;
    for (int i = 0; i < p1->col; i++)
        fout << p1->data[i] << ' ';
    for (int i = 0; i < p2->col; i++)
        fout << p2->data[i] << ' ';
    fout << endl;
}
void f1(string fn)
{
    fstream fout("abc.out", ios::out);
    int n;
    int m;
    int val;
    fstream fin(fn);
    fin >> n;
    fin >> m;
    list l1;
    list l2;
    for (int i = 0; i < n; i++)
    {
        node n(m);
        for (int i = 0; i < m; i++)
        {
            fin >> val;
            n.data[i] = val;
        }
        // n.print();
        l1.pushback(n);
    }
    fin >> n;
    fin >> m;
    for (int i = 0; i < n; i++)
    {
        node n(m);
        for (int i = 0; i < m; i++)
        {
            fin >> val;
            n.data[i] = val;
        }
        //  n.print();
        l2.pushback(n);
    }

    fin >> n;
    fin >> m;
    node *p1 = l1.head->next;
    node *p2 = l2.head->next;
    // (*p1).print();
    while (p1 != nullptr)
    {
        // cout << 222 << endl;
        while (p2 != nullptr)
        {
            // cout << 333 << endl;
            int k = (*p1).data[n - 1];
            //  cout << k << endl;
            int yu = (*p2).data[m - 1];
            // cout << yu << endl;

            if (k == yu)
            {
                // cout << 444 << endl;
                printall(p1, p2, fout);
            }
            p2 = p2->next;
        }
        p1 = p1->next;
        p2 = l2.head->next;
    }
    fout.close();
    fin.close();
}

int main()
{
    f1("in.txt");
}
