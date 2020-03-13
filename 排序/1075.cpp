#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int n, k, m;
struct node
{
    int id;
    int s[6];
    int tol = 0;
    int iden = 0;
};
vector<node> v, vt;
vector<int> score;
bool cmp(node a, node b)
{
    if (a.tol == b.tol)
    {
        return a.iden == b.iden ? a.id < b.id : a.iden > b.iden;
    }
    else
        return a.tol > b.tol;
}
int main()
{

    cin >> n >> k >> m;
    score.resize(k + 1);
    v.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        fill(v[i].s, v[i].s + 6, -5);
        // cout << v[i].s[2] << endl;
    }
    for (int i = 1; i < k + 1; i++)
    {
        cin >> score[i];
    }
    int temp;
    int ids;
    int sco;
    for (int i = 0; i < m; i++)
    {
        cin >> temp >> ids >> sco;
        if (v[temp].s[ids] < sco)
        {
            v[temp].s[ids] = sco;
            if (v[temp].s[ids] == score[ids])
            {
                v[temp].iden++;
            }
        }
        v[temp].id = temp;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            if (v[i].s[j] >= 0)
            {
                vt.push_back(v[i]);
                break;
            }
        }
    }
    for (int i = 0; i < vt.size(); i++)
    {

        for (int j = 1; j < k + 1; j++)
        {
            if (vt[i].s[j] < 0)
            {
                continue;
            }
            else
            {
                vt[i].tol += vt[i].s[j];
            }
        }
    }
    sort(vt.begin(), vt.end(), cmp);
    int ranklist = 1;
    cout << ranklist;
    printf(" %05d %d", vt[0].id, vt[0].tol);
    for (int j = 1; j < k + 1; j++)
    {
        if (vt[0].s[j] == -5)
                cout << " -";
            else if (vt[0].s[j] < 0)
                cout << " 0";
            else 
                cout << " " << vt[0].s[j];
    }
    cout << endl;
    for (int i = 1; i < vt.size(); i++)
    {
        if (vt[i].tol == vt[i - 1].tol)
            cout << ranklist;
        else
        {
            ranklist = i + 1;
            cout << i + 1;
        }
        printf(" %05d %d", vt[i].id, vt[i].tol);
        for (int j = 1; j < k + 1; j++)
        {
            if (vt[i].s[j] == -5)
                cout << " -";
            else if (vt[i].s[j] < 0)
                cout << " 0";
            else 
                cout << " " << vt[i].s[j];
        }
        cout << endl;
    }
    return 0;
}