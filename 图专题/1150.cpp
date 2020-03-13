#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[205][205];
    for (int i = 0; i < m; i++)
    {
        int temp1, temp2, dis;
        cin >> temp1 >> temp2 >> dis;
        a[temp1][temp2] = a[temp2][temp1] = dis;
    }
    int k;
    cin >> k;

    int minn = 0x7fffffff;
    int resnum = 0;
    for (int i = 0; i < k; i++)
    {
        int temp3;
        cin >> temp3;
        vector<int> v(temp3);
        set<int> s;
        // int hash[105];
        for (int j = 0; j < temp3; j++)
        {
            int temp4;
            cin >> temp4;
            v[j] = temp4;
            // hash[temp4]
            s.insert(temp4);
        }
        int tol = 0;
        int isNa = 1;
        for (int j = 1; j < temp3; j++)
        {
            if (a[v[j - 1]][v[j]] == 0)
            {
                isNa = 0;
                break;
            }
            tol += a[v[j - 1]][v[j]];
        }
        if (isNa == 0)
        {
            printf("Path %d: NA (Not a TS cycle)\n", i + 1);
            continue;
        }

        printf("Path %d: %d ", i + 1, tol);
        if (s.size() == n && v[0] == v[v.size() - 1] && v.size() == n + 1)
        {
            int tempmin = minn;
            minn = min(tol, minn);
            if (tempmin > minn)
            {
                resnum = i + 1;
            }
            printf("(TS simple cycle)\n");
        }
        else if (s.size() == n && v[0] == v[v.size() - 1] && (v.size() > n + 1 || v.size() == n + 1))
        {
            int tempmin = minn;
            minn = min(tol, minn);
            if (tempmin > minn)
            {
                resnum = i + 1;
            }
            printf("(TS cycle)\n");
        }
        else // 一个是set的值要满足 等于 n 另一个是直接用 else
        {
            printf("(Not a TS cycle)\n");
        }
    }
    printf("Shortest Dist(%d) = %d", resnum, minn);

    return 0;
}