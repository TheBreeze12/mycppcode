#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Pair
{
public:
    int val;
    int id;
    Pair(int v, int i) : val(v), id(i){};
};
bool bigger(Pair &p1, Pair &p2)
{
    return p1.id > p2.id;
}

void fun(string filename)
{
    fstream fin(filename);
    int n;
    fin >> n;
    // cout << n << endl;
    string buf;

    stack<Pair> a;
    stack<Pair> b;
    vector<Pair> v;
    int x;
    for (int i = n; i > 0; i--)
    {
        fin >> buf;
        if (buf == "push")
        {
            fin >> buf;
            if (buf == "A")
            {
                fin >> x;
                // cout << x << 11 << endl;

                a.push(Pair(x, i));
            }
            else if (buf == "B")
            {
                fin >> x;
                b.push(Pair(x, i));
                // cout << x << 12 << endl;
            }
        }
        else if (buf == "pop")
        {
            fin >> buf;
            if (buf == "A")
            {

                cout << a.top().val << endl;

                a.pop();
            }
            else if (buf == "B")
            {

                cout << b.top().val << endl;

                b.pop();
            }
        }
        else if (buf == "merge")
        {
            // cout << 44 << endl;

            fin >> buf;
            while (!a.empty())
            {
                v.push_back(a.top());
                a.pop();
            }
            while (!b.empty())
            {
                v.push_back(b.top());
                b.pop();
            }
            sort(v.begin(), v.end(), bigger);
            if (buf == "A")
            {
                //   cout << 41 << endl;
                for (auto e : v)
                {
                    a.push(e);
                }
            }
            else if (buf == "B")
            {
                //  cout << 42 << endl;
                for (auto e : v)
                {
                    b.push(e);
                }
            }
            v.clear();
            fin >> buf;
        }
    }
}

int main()
{
    fun("in.txt");
}
