#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int a[10001];
int main()
{
    int n;
    cin >> n;
    vector<long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        a[v[i]]++;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(a[v[i]] == 1){
            printf("%d", v[i]);
            return 0;
        }
    }

    cout << "None";

    return 0;
}