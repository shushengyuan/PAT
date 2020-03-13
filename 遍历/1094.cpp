#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int id;
    vector<int> child;
    int levels;
};
vector<node> v;
int level;
vector<int> num;
void dfs(int num, int lev)
{
    v[num].levels = lev;
    if (v[num].child.size() == 0)
    {
        return;
    }
    for (int i = 0; i < v[num].child.size(); i++)
    {
        dfs(v[num].child[i], lev + 1);
    }
    return;
}
int main()
{
    int n, m;
    cin >> n >> m;
    v.resize(n + 1);
    if (n > 0 && m < n)
    {
        for (int i = 0; i < m; i++)
        {
            int t, chil;
            cin >> t >> chil;
            int temp;
            for (int j = 0; j < chil; j++)
            {
                cin >> temp;

                v[t].child.push_back(temp);
                v[t].id = t;
            }
        }
        dfs(1, 1);
        int maxnuml = 0;
        vector<int> tolnum(100);//这个一百很关键 能避免不必要的麻烦
        for (int i = 1; i <= n; i++)
        {
            tolnum[v[i].levels]++;
            int tempx = maxnuml;
            maxnuml = max(tolnum[v[i].levels], maxnuml);
            if (tempx < maxnuml)
            {
                level = v[i].levels;
            }
            // cout << v[i].levels << endl;
        }
        cout << maxnuml << " " << level << endl;
        // // cout << v[23].child.size();
    }

    return 0;
}