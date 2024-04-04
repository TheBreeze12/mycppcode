#include <iostream>
#include <stack>
#include <vector>

// T *a;
//

using namespace std;

bool istrue()
{
    int n;
    char c;
    char d;
    cin >> n;
    // stack<char> s;
    // stack<char> ss;
    vector<char> v;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        v.push_back(c);
    }

    cin >> c;
    int it = 0;
    for (; it < n && v[it] != c; it++)
    {
    }
    for (int i = 1; i < n; i++)
    {
        cin >> c;
        if (it - 1 >= 0 && c == v[it - 1])
        {
            v.erase(v.begin() + it);
            it = it - 1;
        }

        else
        {
            int iit = it;
            for (it = it + 1; it < v.size() && v[it] != c; it++)
            {
            }
            if (it < v.size())
            {
                v.erase(v.begin() + iit);
                it--;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    if (istrue())
        cout << "true";
    else
        cout << "false";
}