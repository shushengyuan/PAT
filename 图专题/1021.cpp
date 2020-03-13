#include <algorithm>
// #include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> resNum;
// set<int> resNum1;
vector<bool> visit;
vector<bool> resNum1;
vector<vector<int>> v;
int n;
// int a[10005][10005];
int maxn = 0;
// int cnt = 0;
void dfs(int index, int cnt)
{
    visit[index] = true;
    cnt++;
    // cout << cnt << endl;
    int tempx = maxn;
    // cout << tempx << endl;
    maxn = max(maxn, cnt);
    if (tempx < maxn)
    {
        resNum1.clear();
        // resNum.insert(index);
        resNum1.push_back(index);
    }
    else if (tempx == maxn && cnt == maxn)
    {
        resNum1.push_back(index);
    }
    for (int i = 0; i < v[index].size(); i++)
    {
        if (visit[v[index][i]] == false)
            dfs(v[index][i], cnt);
    }
}

int main()
{
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        v[temp1].push_back(temp2);
        v[temp2].push_back(temp1);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (!resNum.count(i))
    //     {
    //         visit.resize(n + 1);
    //         dfs(i, 0);
    //         visit.clear();
    //     }
    // }
    int cntx = 0;
    visit.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == false)
        {
            dfs(i, 0);
            if (i == 1)
            {
                for (int j = 0; j < resNum1.size(); j++)
                    resNum.insert(resNum1[j]);
            }
            cntx++;
        }
    }
    // cout << cntx << endl;
    if (cntx >= 2)
        printf("Error: %d components", cntx);
    else
    {

        visit.clear();
        visit.resize(n + 1);
        int tempnum = resNum1[0];
        cout << tempnum << endl;
        dfs(tempnum, 0);
        for (int j = 0; j < resNum1.size(); j++)
            resNum.insert(resNum1[j]);
        // resNum.insert(tempnum);
        for (auto it = resNum.begin(); it != resNum.end(); it++) //set的输出方法
            printf("%d\n", *it);
    }
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, maxheight = 0;
vector<vector<int>> v;
bool visit[10010];
set<int> s;
vector<int> temp;
void dfs(int node, int height) {
    if(height > maxheight) {
        temp.clear();
        temp.push_back(node);
        maxheight = height;
    } else if(height == maxheight){
        temp.push_back(node);
    }
    visit[node] = true;
    for(int i = 0; i < v[node].size(); i++) {
        if(visit[v[node][i]] == false)
            dfs(v[node][i], height + 1);
    }
}
int main() {
    scanf("%d", &n);
    v.resize(n + 1);
    int a, b, cnt = 0, s1 = 0;
    for(int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(visit[i] == false) {
            dfs(i, 1);
            if(i == 1) {
                if (temp.size() != 0) s1 = temp[0];
                for(int j = 0; j < temp.size(); j++)
                    s.insert(temp[j]);
            }
            cnt++;
        }
    }
    if(cnt >= 2) {
        printf("Error: %d components", cnt);
    } else {
        temp.clear();
        maxheight = 0;
        fill(visit, visit + 10010, false);
        dfs(s1, 1);
        for(int i = 0; i < temp.size(); i++)
            s.insert(temp[i]);
        for(auto it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}
*/