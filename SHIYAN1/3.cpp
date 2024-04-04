#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxl = 100;
template <class T>
class cqueue
{
public:
    int size;
    T *data;
    int first, rear;

public:
    cqueue()
    {
        size = 0;
        data = new T[maxl];
        first = rear = 0;
    }
    ~cqueue() { delete[] data; }
    bool empty()
    {
        return first == rear;
    }
    bool push(T e)
    {
        if ((rear + 1) % maxl == first)
            return 0;
        rear = (rear + 1) % maxl;
        data[rear] = e;
        size++;
        return 1;
    }
    bool pop()
    {
        if (first == rear)
        {
            return 0;
        }
        first = (first + 1) % maxl;
        size--;
        return 1;
    }
    T &front()
    {
        if (first != rear)
        {
            int head = (first + 1) % maxl;
            return data[head];
        }
        // return pa(-1,-1);
        static T t;
        return t;
    }
    void print()
    {
        if (first < rear)
        {
            for (int i = (first + 1) % maxl; i <= rear; i++)
            {
                T a;
                a = data[i];
                cout << a << ' ';
            }
        }
        if (first > rear)
        {
            for (int i = (first + 1) % maxl; i <= maxl - 1; i++)
            {
                T a;
                a = data[i];
                cout << a << ' ';
            }
            for (int i = 0; i <= rear; i++)
            {
                T a;
                a = data[i];
                cout << a << ' ';
            }
        }

        cout << endl;
    }
};

class pa
{
public:
    int val;
    int id;
    pa(int i) : id(i), val(0){};
    pa(){};
};
bool paixu(pa &a, pa &b)
{
    return a.id < b.id;
}
void f(int n)
{
    cqueue<pa> q;
    vector<pa> v;

    for (int i = 1; i <= n; i++)
    {
        q.push(pa(i));
    }

    for (int i = 1; !q.empty(); i++)

    {
        for (int j = 0; j < i; j++)
        {
            q.push(q.front());
            q.pop();
        }
        // q.front().val = i;
        q.front().val = i;
        v.push_back(q.front());
        q.pop();
    }
    sort(v.begin(), v.end(), paixu);
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i].val << ' ';
    }
    cout << v[v.size() - 1].val;
}
int main()
{
    int n;
    cin >> n;
    int m[n];

    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        f(m[i]);
        cout << endl;
    }
    f(m[n - 1]);
    // cout << endl;
}