#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int n, low, high;
struct node
{
    int id;
    int vg;
    int tg;
};
vector<node> v;
bool cmp1(node a, node b)
{
    if (a.vg + a.tg == b.vg + b.tg)
    {
        return a.vg == b.vg ? a.id < b.id : a.vg > b.vg;
    }
    else
    {
        return a.vg + a.tg > b.vg + b.tg;
    }
}
int main()
{
    cin >> n >> low >> high;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].id >> v[i].vg >> v[i].tg;
    }
    vector<node> v1;
    vector<node> v2;
    vector<node> v3;
    vector<node> v4;
    for (int i = 0; i < n; i++)
    {
        if (v[i].vg >= high && v[i].tg >= high)
        {
            v1.push_back(v[i]);
        }
        else if (v[i].vg >= high && v[i].tg < high && v[i].tg >= low)
        {
            v2.push_back(v[i]);
        }
        else if (v[i].vg < high && v[i].vg >= low && v[i].tg < high && v[i].tg >= low&&v[i].vg>=v[i].tg)
        {
            v3.push_back(v[i]);
        }else if(v[i].vg >= low&& v[i].tg >= low){
            v4.push_back(v[i]);
        }
    }
    sort(v1.begin(), v1.end(), cmp1);
    sort(v2.begin(), v2.end(), cmp1);
    sort(v3.begin(), v3.end(), cmp1);
    sort(v4.begin(), v4.end(), cmp1);
    int tol = v1.size() + v2.size() + v3.size()+ v4.size();
    cout << tol << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i].id << " " << v1[i].vg << " " << v1[i].tg << endl;
    }
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i].id << " " << v2[i].vg << " " << v2[i].tg << endl;
    }
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i].id << " " << v3[i].vg << " " << v3[i].tg << endl;
    }
    for (int i = 0; i < v4.size(); i++)
    {
        cout << v4[i].id << " " << v4[i].vg << " " << v4[i].tg << endl;
    }
    return 0;
}