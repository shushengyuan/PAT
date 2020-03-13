#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct node
{
    double data;
    vector<int> child;
};
vector<node> v;
double tolres = 0.0;
int n;
double r, p;
void dfs(int index, int depth)
{
    if (v[index].child.size() == 0)
    {
        double res;
        res = p * pow(1 + r / 100, depth) * v[index].data;
        tolres += res;
        return;
    }
    for (int i = 0; i < v[index].child.size(); i++)
    {
        // cout << i << endl;
        dfs(v[index].child[i], depth + 1);
    }
}
int main()
{
    cin >> n >> p >> r;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        int tempnum;

        scanf("%d", &tempnum);
        if (tempnum == 0)
        {
            // scanf("%d", &temp);
            scanf("%lf", &v[i].data);
        }
        else
        {
            for (int j = 0; j < tempnum; j++)
            {
                int temp;
                scanf("%d", &temp);

                v[i].child.push_back(temp);
            }
        }
        // cout << i << endl;
    }
    dfs(0, 0);
    // cout << tolres << endl;
    printf("%.1f", tolres);
    return 0;
}