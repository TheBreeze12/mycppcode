#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void bolan(string filename)
{
    stack<string> s;
    fstream fin(filename);
    string buf;
    getline(fin, buf);
    stringstream bbuf(buf);
    string str;
    int a;
    int b;
    int c;
    string cc;

    while (getline(bbuf, str, ','))
    {
        // cout << str << endl;
        if (str != "+" && str != "-" && str != "*" && str != "/")
        {
            s.push(str);
        }
        if (str == "+")
        {
            a = atoi(s.top().c_str());
            s.pop();
            b = atoi(s.top().c_str());
            s.pop();
            c = a + b;
            cc = to_string(c);
            s.push(cc);
        }
        if (str == "-")
        {
            a = atoi(s.top().c_str());
            s.pop();
            b = atoi(s.top().c_str());
            s.pop();

            c = b - a;
            cc = to_string(c);
            s.push(cc);
        }
        if (str == "*")
        {
            a = atoi(s.top().c_str());
            s.pop();
            b = atoi(s.top().c_str());
            s.pop();
            c = a * b;
            cc = to_string(c);
            s.push(cc);
        }
        if (str == "/")
        {
            a = atoi(s.top().c_str());
            s.pop();
            b = atoi(s.top().c_str());
            s.pop();
            c = b / a;
            cc = to_string(c);
            s.push(cc);
        }
    }
    cout << s.top();
}

int main()
{
    bolan("in.txt");
}