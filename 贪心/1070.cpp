#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
struct node
{
    double a;
    double p;
    double pri;
};
bool cmp1(node v1, node v2)
{
    return v1.pri > v2.pri;
}
using namespace std;
int main()
{
    double na[1005];
    double np[1005];
    int n, d;
    cin >> n >> d;
    vector<node> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> na[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> np[i];
        v[i].a = na[i];
        v[i].p = np[i];
        v[i].pri = np[i] / na[i];
        // cout << v[i].pri << endl;
    }
    sort(v.begin(), v.end(), cmp1);
    double tol = 0.0;
    int num = 0;
    double res = 0.0;
    while (num != n)
    {
        if (tol + v[num].a < d)
        {
            res += v[num].p;
            tol = tol + v[num].a;
            // cout << res << endl;
        }
        else
        {
            // cout << (d - tol) / (v[num].a) << endl;
            res += (d - tol) / (v[num].a) * v[num].p;
            tol = d;
            break;
        }
        num++;
    }
    printf("%.2f", res);
    return 0;
}