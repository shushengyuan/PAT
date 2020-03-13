#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<double> v;

int main()
{
    int n;
    cin >> n;
    v.resize(n);
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v[i] = temp;
    }
    sort(v.begin(), v.end());
    int init = (v[0] + v[1]) / 2;
    int result = init;
    for (int i = 2; i < n; i++)
    {
        result = (result + v[i]) / 2;
    }
    cout << result << endl;
    return 0;
}