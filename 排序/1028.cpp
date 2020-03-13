#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
struct node
{
    int id;
    char s[10];
    int grade;
};
vector<node> v;
bool cmp1(node a, node b)
{
    return a.id < b.id;
}
bool cmp2(node a, node b)
{
    return strcmp(a.s, b.s) == 0 ? a.id < (b.id) : strcmp(a.s, b.s) < 0;
}
bool cmp3(node a, node b)
{
    return a.grade == b.grade ? (a.id) < (b.id) : a.grade < b.grade;
}
int main()
{
    int n, c;
    cin >> n >> c;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %d", &v[i].id, v[i].s, &v[i].grade);
        // cout << v[i].id << endl;
    }
    if (c == 1)
    {
        sort(v.begin(), v.end(), cmp1);
    }
    else if (c == 2)
    {
        sort(v.begin(), v.end(), cmp2);
    }
    else if (c == 3)
    {
        sort(v.begin(), v.end(), cmp3);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%06d", v[i].id);
        cout<< " " << v[i].s << " " << v[i].grade << endl;
    }
    return 0;
}