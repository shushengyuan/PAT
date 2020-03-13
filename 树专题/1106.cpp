#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
int mindepth = 100005;
int tolnum = 0;
void dfs(int index, int depth)
{
    if (v[index].size() == 0)
    {
        if (depth < mindepth)
        {
            mindepth = depth;
            tolnum = 1;
        }
        else if (depth == mindepth)
        {
            tolnum++;
        }
        return;
    }

    for (int i = 0; i < v[index].size(); i++)
    {
        dfs(v[index][i], depth + 1);
    }
}
int main()
{
    int n;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        for (int j = 0; j < temp; j++)
        {
            int temp1;
            scanf("%d", &temp1);
            v[i].push_back(temp1);
        }
    }
    dfs(0, 0);
    printf("%.4f %d", p * pow(1 + r/100,mindepth),tolnum);
    return 0;
}