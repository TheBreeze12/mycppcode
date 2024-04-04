#include <iostream>
#include <stack>
#include <string>

using namespace std;

class express
{
    string exp;
    string poexp;

public:
    express(string str)
    {
        exp = str;
        poexp = "";
    }
    string getpoexp()
    {
        return poexp;
    }
    void trans()
    {
        stack<char> opor;
        int i = 0;
        char ch, e;
        while (i < exp.length())
        {
            ch = exp[i];
            if (ch == '(')
                opor.push(ch);
            else if (ch == ')')
            {
                while (!opor.empty() && opor.top() != '(')
                {
                    e = opor.top();
                    opor.pop();
                    poexp += e;
                }
                opor.pop();
            }
            else if (ch == '+' || ch == '-')
            {
                while (!opor.empty() && opor.top() != '(')
                {
                    e = opor.top();
                    opor.pop();
                    poexp += e;
                }
                opor.push(ch);
            }
            else if (ch == '*' || ch == '/')
            {
                while (!opor.empty() && opor.top() != '(' && (opor.top() == '*' || opor.top() == '/'))
                {
                    e = opor.top();
                    opor.pop();
                    poexp += e;
                }
                opor.push(ch);
            }
            else if (ch >= '0' && ch <= '9')
            {
                string d = "";
                while (ch >= '0' && ch <= '9')
                {
                    d += ch;
                    i++;
                    if (i < exp.length())
                        ch = exp[i];
                    else
                        break;
                }
                i--;
                poexp += d;
                poexp += "#";
            }
            i++;
        }
        while (!opor.empty())
        {
            e = opor.top();
            opor.pop();
            poexp += e;
        }
    }
    int getvalue()
    {
        stack<int> opand;
        int a, b, c, d;
        char ch;
        int i = 0;
        while (i < poexp.length())
        {
            ch = poexp[i];
            switch (ch)
            {
            case '+':
                a = opand.top();
                opand.pop();
                b = opand.top();
                opand.pop();
                c = a + b;
                opand.push(c);
                break;
            case '-':
                a = opand.top();
                opand.pop();
                b = opand.top();
                opand.pop();
                c = b - a;
                opand.push(c);
                break;
            case '*':
                a = opand.top();
                opand.pop();
                b = opand.top();
                opand.pop();
                c = a * b;
                opand.push(c);
                break;
            case '/':
                a = opand.top();
                opand.pop();
                b = opand.top();
                opand.pop();
                c = b / a;
                opand.push(c);
                break;
            default:
                d = 0;
                while (ch >= '0' && ch <= '9')
                {
                    d = 10 * d + (ch - '0');
                    i++;
                    ch = poexp[i];
                }
                opand.push(d);
                break;
            }
            i++;
        }

        return opand.top();
    }
};

int main()
{
    string str;
    getline(cin, str);
    // // cout << str;
    // int m = str.length();
    // // cout << m << endl;
    // string s;
    // for (int i = 0; i < m; i++)
    // {
    //     if (str[i] == ' ' || str[i] == '=')
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         s += str[i];
    //     }
    // }

    express e(str);
    e.trans();
    cout << e.getvalue() << endl;
}