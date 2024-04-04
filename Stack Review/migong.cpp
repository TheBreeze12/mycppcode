#include <iostream>
#include <stack>

using namespace std;
const int m = 5;
const int n = 4;
int mg[m][n] =
    {
        {0, 0, 1, 0},
        {1, 0, 1, 0},
        {1, 0, 1, 0},
        {1, 0, 0, 0},
        {1, 0, 1, 1}};
class box
{
public:
    int i;
    int j;
    int di;
    int val;

public:
    box(){};
    box(int ii, int jj) : i(ii), j(jj), di(-1), val(0) {}
};
void path(stack<box> &s)
{
    while (s.size() > 1)
    {
        cout << '(' << s.top().i << ',' << s.top().j << ')' << '<' << '-';
        s.pop();
    }
    cout << '(' << s.top().i << ',' << s.top().j << ')';
}
void findpath(int i, int j, int xe, int ye)
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool isfind = false;
    stack<box> s;
    box b(i, j);
    s.push(b);
    while (!isfind)
    {

        b = s.top();

        if (b.i == xe && b.j == ye)
        {
            isfind = true;
            path(s);
            break;
        }
        // int ii;
        for (; b.di < 3;)
        {
            b.di++;
            if (b.i + dx[b.di] >= 0 && b.i + dx[b.di] <= m - 1 && b.j + dy[b.di] >= 0 && b.j + dy[b.di] <= n - 1)
            {
                int e = mg[b.i + dx[b.di]][b.j + dy[b.di]];
                if (e == 0)
                {

                    isfind = true;
                    break;
                }
            }
        }
        if (isfind)
        {

            b.val = -1;
            mg[b.i][b.j] = -1;
            s.top() = b;
            box b1(b.i + dx[b.di], b.j + dy[b.di]);
            s.push(b1);
        }
        if (!isfind)
        {
            b.val = 2;
            s.pop();
        }

        isfind = 0;
        if (s.empty())
        {
            cout << "无路可走" << endl;
            break;
        }
    }
}

int main()
{

    findpath(0, 0, 0, 3);
}