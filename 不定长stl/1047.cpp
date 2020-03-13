#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxnn = 2505;
vector<string> v[maxnn];
// bool cmp1(char a[4], char b[4])
// {
//     return strcmp(a, b) < 0;
// }
int main()
{
    int n, k;
    // cin >> n >> k;
    scanf("%d %d", &n, &k);
    // char c[4];
    string c;
    c.resize(4);
    for (int i = 0; i < n; i++)
    {
        int num;
        // scanf("%s", c);
        // cin >> c;
        scanf("%s", &c[0]);
        scanf("%d", &num);
        int id;
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &id);
            v[id].push_back(c);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        sort(v[i].begin(), v[i].end());
        // cout << i << " " << v[i].size() << endl;
        printf("%d %d\n", i, v[i].size());
        for (int j = 0; j < v[i].size(); j++)
        {
            printf("%s\n", v[i][j].c_str());
            // cout << v[i][j] << endl;

        }
    }
    return 0;
}