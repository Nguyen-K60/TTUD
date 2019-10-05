#include <stdlib.h>
#include <stack>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

bool match(char c, char d)
{
    if (c == '(' && d == ')')
        return true;
    if (c == '[' && d == ']')
        return true;
    if (c == '{' && d == '}')
        return true;
    return false;
}
bool check(string m)
{
    stack<char> s;
    int n = m.length();
    for (int i = 0; i < n; i++)
    {
        char c = m.at(i);
        if (c == '(' || c == '[' || c == '{')
        {
            s.push(c);
        }
        else
        {
            if (s.size() == 0)
                return false;
            char d = s.top();
            if (!match(d, c))
            {
                return false;
            }
            s.pop();
        }
    }
    return !s.size();
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string m;
        cin >> m;
        cout << check(m) << endl;
    }
}
