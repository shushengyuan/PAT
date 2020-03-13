#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
bool testDia(vector<int> v)
{
    // for (int j = 1; j < v.size(); j++)
    //     {
    //         cout << v[j] << endl;
    //     }

    for (int i = 1; i < v.size(); i++)
    {
        for (int j = i+1; j < v.size(); j++)
        {
            // cout << abs(v[j] - v[i]) << endl;
            // cout << abs(j - i) << endl;
            if (abs(v[j] - v[i]) == abs(j - i))
            {
                return false;
            }
        }
    }
    return true;
}
bool testRow(vector<int> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != i)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int K, N;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> N;
        vector<int> v(N + 1);
        for (int j = 1; j <= N; j++)
        {
            cin >> v[j];
        }
        
        int temp1 = testDia(v);
        if (temp1 == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        sort(v.begin(), v.end());
        int temp2 = testRow(v);
        if (temp2 == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }

    return 0;
}