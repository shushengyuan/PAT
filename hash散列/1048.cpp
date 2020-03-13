#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
int a[1001];
using namespace std;
bool temp(int a, int b)
{
    return a > b;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        a[v[i]]++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int k;
        k = v[i];
        // cout << k << endl;

        if (a[m - k] >= 1 && m != 2 * k)
        {
            if (k <= m - k)
                printf("%d %d", k, m - k);
            else if (k > m - k)
                printf("%d %d", m - k, k);
            return 0;
        }
        else if (m == 2 * k)
        {
            if (a[m - k] >= 2)
            {
                printf("%d %d", k, m - k);
                return 0;
            }
        }
    }

    cout << "No Solution" << endl;
    return 0;
}