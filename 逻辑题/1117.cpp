#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), c);
    int i = 0;
    // int temp = 0;
    // int result = 0;
    while (i < N && v[i] > i + 1)
    {
        i++;
    }
    cout << i << endl;
    return 0;
}
/*

#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
int main() {
    int n, e = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n, greater<int>());
    while(e < n && a[e] > e+1) e++;
    printf("%d", e);
    return 0;
}
*/