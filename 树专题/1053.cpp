#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int w;
    vector<int> child;
};
vector<node> v;
vector<int> path;
int s;
void dfs(int index, int nodeNum, int sum)
{
    if (sum > s)
        return;
    if (sum == s)
    {
        if (v[index].child.size() != 0)
            return;
        for (int i = 0; i < nodeNum; i++)
            printf("%d%c", v[path[i]].w, i != nodeNum - 1 ? ' ' : '\n');
        return;
    }
    for (int i = 0; i < v[index].child.size(); i++)
    {
        int temp1 = v[index].child[i];
        path[nodeNum] = temp1;
        dfs(temp1, nodeNum + 1, sum + v[temp1].w);
    }
}
int cmp1(int a, int b)
{
    return v[a].w > v[b].w;
}
int main()
{
    int n, m;
    cin >> n >> m >> s;
    v.resize(n);
    path.resize(n);
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &v[i].w);
    }
    int temp, num;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &temp, &num);
        v[temp].child.resize(num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &v[temp].child[j]);
        }
        sort(v[temp].child.begin(), v[temp].child.end(), cmp1);
    }
    dfs(0, 1, v[0].w);
    return 0;
}