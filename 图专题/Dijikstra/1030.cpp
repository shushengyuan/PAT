#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n, m, s, d;
int eDis[510][510];
int eCost[510][510];
bool visit[510];
int tolcost[510];
int toldis[510];
int num[510];
vector<int> res[510];
const int infi = 0x7fffffff;
int main()
{
    fill(eDis[0], eDis[0] + 510 * 510, infi);
    fill(eCost[0], eCost[0] + 510 * 510, infi);
    fill(toldis, toldis + 510, infi);
    fill(tolcost, tolcost + 510, infi);
    cin >> n >> m >> s >> d;
    for (int i = 0; i < m; i++)
    {
        int city1, city2, distance, cost;
        scanf("%d %d %d %d", &city1, &city2, &distance, &cost);
        eDis[city1][city2] = eDis[city2][city1] = distance;
        eCost[city1][city2] = eCost[city2][city1] = cost;
    }
    toldis[s] = 0;
    tolcost[s] = 0;
    res[s].push_back(s);
    // visit[s] = true;
    num[s] = 1;
    for (int i = 0; i < n; i++)
    {
        int t = -1, minn = infi;
        for (int j = 0; j < n; j++)
        {
            if (visit[j] == false && toldis[j] < minn)
            {
                // cout << toldis[j] << endl;
                t = j;
                minn = toldis[j];
            }
        }
        if (t == -1)
            break;
        visit[t] = true;
        for (int v = 0; v < n; v++)
        {
            if (visit[v] == false && eDis[t][v] != infi)
            {
                // visit[v] = true;
                if (toldis[t] + eDis[t][v] < toldis[v])
                {
                    toldis[v] = toldis[t] + eDis[t][v];
                    num[v] = num[t];
                    tolcost[v] = tolcost[t] + eCost[t][v];
                    res[v] = res[t];
                    res[v].push_back(v);
                }
                else if (toldis[t] + eDis[t][v] == toldis[v])
                {

                    if (tolcost[t] + eCost[t][v] < tolcost[v])
                    {
                        tolcost[v] = tolcost[t] + eCost[t][v];
                        res[v] = res[t];
                        // for (int i = 0; i < res[v].size(); i++)
                        // {
                        //     printf("%d ", res[d][i]);
                        // }
                        res[v].push_back(v);
                    }
                }
            }
        }
    }
    for (int i = 0; i < res[d].size(); i++)
    {
        printf("%d ", res[d][i]);
    }
    printf("%d %d", toldis[d], tolcost[d]);

    return 0;
}