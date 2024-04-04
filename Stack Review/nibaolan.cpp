#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class express
{
    string exp;
    string hexp;

public:
    express(string str)
    {
        exp = str;
        hexp = "";
    }
    void trans();
    void getvalue();
};
void express::trans()
{
    char ch, e;
    stack<char> s;
    int i = 0;
    while (i < exp.length())
    {
        ch = exp[i];
        if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (s.top() != '(')
            {
                e = s.top();
                hexp += e;
                hexp += '#';
                s.pop();
            }
            s.pop();
        }
        else if (ch == '+' || ch == '-')
        {
            if (!s.empty() && s.top() != '(')
            {
                e = s.top();
                s.pop();
                hexp += e;
                hexp += '#';
            }
            s.push(ch);
        }
        else if (ch == '*' || ch == '/')
        {
            if (!s.empty() && s.top() != '(' && (s.top() == '*' || s.top() == '/'))
            {
                e = s.top();
                s.pop();
                hexp += e;
                hexp += '#';
            }
            s.push(ch);
        }
        else if (ch >= '0' && ch <= '9')
        {
            string d = "";
            while (ch >= '0' && ch <= '9')
            {
                d += ch;
                i++;
                ch = exp[i];
            }
            i--;
            d += '#';
            hexp += d;
        }
        i++;
    }
    while (!s.empty())
    {
        e = s.top();
        hexp += e;
        hexp += '#';
        s.pop();
    }
    cout << hexp;
}

void express::getvalue()
{
    int a;
    int b;
    int c;
    int d;
    stack<int> s;
    string token;
    stringstream ss(hexp);
    while (getline(ss, token, '#'))
    {
        if (token == "+")
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            c = b + a;
            s.push(c);
        }
        else if (token == "-")
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            c = b - a;
            s.push(c);
        }
        else if (token == "*")
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            c = b * a;
            s.push(c);
        }
        else if (token == "/")
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            c = b / a;
            s.push(c);
        }
        else
        {
            d = atoi(token.c_str());
            s.push(d);
        }
    }
    cout << s.top();
}

int main()
{
    string str;
    getline(cin, str);
    express v(str);
    v.trans();
    cout << endl;
    v.getvalue();
}