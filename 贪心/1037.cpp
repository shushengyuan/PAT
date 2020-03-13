#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> nc, np,nc1, np1;
bool cmp1(int a, int b)
{
    return a > b;
}
int main()
{
    int c, p;
    cin >> c;
    int temp;
    for (int i = 0; i < c; i++)
    {
        cin >> temp;
        if(temp>0)
            nc.push_back(temp);
        else
            nc1.push_back(temp);
    }
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> temp;
        if(temp>0)
            np.push_back(temp);
        else
            np1.push_back(temp);
    }
    sort(nc.begin(), nc.end(), cmp1);
    sort(np.begin(), np.end(), cmp1);
    sort(nc1.begin(), nc1.end());
    sort(np1.begin(), np1.end());
    int k = 0;
    int sum = 0;
    int maxnum = min(nc.size(), np.size());
    for (int i = 0; i < maxnum;i++){
        sum += nc[i] * np[i];
    }
    int maxnum1 = min(nc1.size(), np1.size());
    for (int i = 0; i < maxnum1;i++){
        sum += nc1[i] * np1[i];
    }
    cout << sum << endl;
    return 0;
}