#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
bool cmp1(string a, string b)
{
    return a + b < b + a;
}
string s[10010];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s, s + n, cmp1);
    string rs;
    for (int i = 0; i < n; i++)
    {
        rs += s[i];
    }
    while (rs.length() != 0 && rs[0] == '0')
    {
        rs.erase(rs.begin());
    }
    if (rs.length() == 0)
        cout << 0;
    cout << rs;
    return 0;
}