#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int lengthcost[505][505];
int timecost[505][505];

int tollength[505];
int toltime[505];
int tollength1[505];
int toltime1[505];
bool visit[505];
bool visit1[505];
int num[505];
int num1[505];
vector<vector<int>> path;
vector<vector<int>> path1;

int infi = 0x7fffffff;
// void dfs(int index,int )
int main()
{
    fill(lengthcost[0], lengthcost[0] + 505 * 505, infi);
    fill(timecost[0], timecost[0] + 505 * 505, infi);
    fill(tollength, tollength + 505, infi);
    fill(toltime, toltime + 505, infi);
    fill(tollength1, tollength1 + 505, infi);
    fill(toltime1, toltime1 + 505, infi);
    int n, m;
    cin >> n >> m;
    path.resize(n);
    path1.resize(n);

    int v1, v2, oneWay, length, time;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d %d", &v1, &v2, &oneWay, &length, &time);
        if (oneWay == 1)
        {
            lengthcost[v1][v2] = length;
            timecost[v1][v2] = time;
        }
        else
        {
            lengthcost[v1][v2] = lengthcost[v2][v1] = length;
            timecost[v1][v2] = timecost[v2][v1] = time;
        }
    }
    int start, end;
    cin >> start >> end;
    tollength[start] = 0;
    num[start] = 1;
    toltime[start] = 0;
    toltime1[start] = 0;
    tollength1[start] = 0;
    num1[start] = 1;
    path[start].push_back(start);
    path1[start].push_back(start);
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        int minn = 0x7fffffff;
        for (int j = 0; j < n; j++)
        {
            if (visit[j] == false && tollength[j] < minn)
            {
                t = j;
                minn = tollength[j];
            }
        }

        if (t == -1)
        {
            break;
        }
        visit[t] = true;
        for (int v = 0; v < n; v++)
        {
            if (visit[v] == false && lengthcost[t][v] != infi)
            {
                if (tollength[t] + lengthcost[t][v] < tollength[v])
                {
                    path[v] = path[t];
                    path[v].push_back(v);
                    tollength[v] = tollength[t] + lengthcost[t][v];
                    toltime[v] = toltime[t] + timecost[t][v];
                    num[v] = num[t];
                }
                else if (tollength[t] + lengthcost[t][v] == tollength[v])
                {
                    if (toltime[t] + timecost[t][v] < toltime[v])
                    {
                        tollength[v] = tollength[t] + lengthcost[t][v];
                        toltime[v] = toltime[t] + timecost[t][v];
                        path[v] = path[t];
                        path[v].push_back(v);
                    }

                    num[v] = num[v] + num[t];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        int minn = 0x7fffffff;
        for (int j = 0; j < n; j++)
        {
            if (visit1[j] == false && toltime1[j] < minn)
            {
                t = j;
                minn = toltime1[j];
            }
        }

        if (t == -1)
        {
            break;
        }
        visit1[t] = true;
        for (int v = 0; v < n; v++)
        {
            if (visit1[v] == false && timecost[t][v] != infi)
            {
                if (toltime1[t] + timecost[t][v] < toltime1[v])
                {
                    toltime1[v] = toltime1[t] + timecost[t][v];
                    num1[v] = num1[t];
                    path1[v] = path1[t];
                    path1[v].push_back(v);
                }
                else if (toltime1[t] + timecost[t][v] == toltime1[v])
                {
                    if (path1[t].size() + 1 < path1[v].size())
                    {
                        path1[v] = path1[t];
                        path1[v].push_back(v);
                    // toltime1[v] = toltime1[t] + timecost[t][v];
                    }
                    num1[v] = num1[v] + num1[t];
                }
            }
        }
    }
    int flag = 1;
    if (path[end].size() == path1[end].size())
    {
        for (int i = 0; i < path[end].size(); i++)
        {
        // cout << flag << endl;
            if (path[end][i] != path1[end][i])
            {
                
                flag = 1;
                break;
            }
            flag = 0;
        }
    }
    // cout << flag << endl;
    if (flag == 1)
    {
        cout << "Distance = " << tollength[end] << ": ";
        cout << path[end][0];
        for (int i = 1; i < path[end].size(); i++)
        {
            printf(" -> %d", path[end][i]);
        }
        cout << endl;
        cout << "Time = " << toltime1[end] << ": ";
        cout << path1[end][0];
        for (int i = 1; i < path1[end].size(); i++)
        {
            printf(" -> %d", path1[end][i]);
        }
        cout << endl;
    }
    else if (flag == 0)
    {
        cout << "Distance = " << tollength[end] << "; ";
        cout << "Time = " << toltime1[end] << ": ";
        cout << path1[end][0];
        for (int i = 1; i < path1[end].size(); i++)
        {
            printf(" -> %d", path1[end][i]);
        }
    }
    return 0;
}