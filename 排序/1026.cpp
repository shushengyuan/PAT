#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    int time, p, tag, nowtime;
    int index;
    int visit = 0;
};
struct table
{
    int index;
    int token = 0;
    int nowtime = 0;
    int vips = 0;
    int numbers = 0;
};
bool cmp1(node a, node b)
{
    return a.time < b.time;
}
bool cmp2(table a, table b)
{
    return a.nowtime < b.nowtime;
}
bool cmp3(node a, node b)
{
    return a.tag == b.tag ? a.time > b.time : a.tag < b.tag;
}
int main()
{
    int n;
    cin >> n;
    vector<node> v(n);
    for (int i = 0; i < n; i++)
    {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);

        int time = (hh)*3600 + mm * 60 + ss;
        v[i].time = time;
        int tempp;
        cin >> tempp;
        v[i].p = tempp * 60;
        cin >> v[i].tag;
        v[i].nowtime = v[i].time;
    }
    sort(v.begin(), v.end(), cmp1);
    for (int i = 0; i < n; i++)
    {
        v[i].index = i;
    }
    int m, vip;
    cin >> m >> vip;
    vector<table> num(m);
    for (int i = 0; i < m; i++)
    {
        num[i].index = i;
    }
    for (int i = 0; i < vip; i++)
    {
        int temp;
        cin >> temp;
        num[temp-1].vips = 1;
    }
    int flag = 0;
    queue<node> q;
    // int restime = 0;
    int cnt = 0;
    vector<node> res;
    while (cnt != n)
    {
        if (v[cnt].visit == 1)
        {
            cnt = res[res.size() - 1].index;
            res.pop_back();
            continue;
        }
        flag = 0;
        // cout << "??" << endl;
        if(v[])
        if (num[0].token != 1)

        {
            num[0].numbers++;
            flag = 1;
            num[0].token = 1;
            printf("%02d:%02d:%02d ", v[cnt].time / 3600, (v[cnt].time - (v[cnt].time / 3600) * 3600) / 60, v[cnt].time - (v[cnt].time / 3600) * 3600 - ((v[cnt].time - (v[cnt].time / 3600) * 3600) / 60 * 60));
            if (num[0].nowtime != 0)
            {
                if (num[0].nowtime < v[cnt].time)
                    num[0].nowtime = v[cnt].time;
                else
                    num[0].nowtime = num[0].nowtime;
            }
            else
                num[0].nowtime = v[cnt].time;
            printf("%02d:%02d:%02d ", num[0].nowtime / 3600, (num[0].nowtime - (num[0].nowtime / 3600) * 3600) / 60, num[0].nowtime - (num[0].nowtime / 3600) * 3600 - ((num[0].nowtime - (num[0].nowtime / 3600) * 3600) / 60 * 60));
            printf("%d\n", int(num[0].nowtime - v[cnt].time + 0.5 * 60) / 60);
            num[0].nowtime += v[cnt].p;
            v[cnt].visit = 1;
            cnt++;
            continue;
            
        }

        if (flag == 0) //无桌子进入等待
        {
            sort(num.begin(), num.end(), cmp2);
            // cout << num[0].nowtime / 3600 << endl;
            if (num[0].nowtime >= (21 * 3600))
            {
                // cout << "??" << endl;
                break;
            }
            // cout << num[0].index << endl;

            if (v[cnt].time <= num[0].nowtime && cnt < n - 1)
            {
                // printf("%02d:%02d:%02d \n", num[0].nowtime / 3600, (num[0].nowtime - (num[0].nowtime / 3600) * 3600) / 60, num[0].nowtime - (num[0].nowtime / 3600) * 3600 - ((num[0].nowtime - (num[0].nowtime / 3600) * 3600) / 60 * 60));

                res.push_back(v[cnt]);
                cnt++;
            }
            else if (v[cnt].tag == 1 || cnt == n - 1 || v[cnt].time > num[0].nowtime)
            {
                res.push_back(v[cnt]);
                // cout << v[cnt].time/3600 << endl;
                sort(res.begin(), res.end(), cmp3);
                // printf("%02d:%02d:%02d \n", res[0].time / 3600, (res[0].time - (res[0].time / 3600) * 3600) / 60, res[0].time - (res[0].time / 3600) * 3600 - ((res[0].time - (res[0].time / 3600) * 3600) / 60 * 60));
                cnt = res[res.size() - 1].index;
                // cout << cnt << endl;
                num[0].token = 0;
                res.pop_back();
                // vector<node>().swap(res);
            }
        }
    }
    cout << num[0].numbers;
    for (int i = 1; i < m; i++)
    {
        cout << " " << num[i].numbers;
    }

    return 0;
}

/*
5
08:00:00 20 0
08:02:00 30 0
08:10:00 5 0
08:11:00 5 0
08:12:00 5 1
3 1 2
*/

/*
08:00:00 20 0
08:01:30 15 1
08:02:00 30 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
20:51:00 10 0
20:52:00 10 0
20:53:00 10 1
*/