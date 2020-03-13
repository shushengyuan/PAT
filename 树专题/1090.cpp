
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100010];
int root;
int maxdepth = 0;
int tolnum = 0;
void dfs(int index, int depth)
{
    if (v[index].size() == 0)
    {
        if (depth == maxdepth)
        {
            tolnum++;
        }
        else if (depth > maxdepth)
        {
            maxdepth = depth;
            tolnum = 1;
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
        if (temp == -1)
        {
            root = i;
        }
        else
        {
            v[temp].push_back(i);
        }
    }
    dfs(root, 0);
    printf("%.2f %d", p * pow(1 + r / 100, maxdepth), tolnum);
    return 0;
}