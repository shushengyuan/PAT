#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
void downAdjust(vector<int> &b, int low, int high)
{
    int i = 1, j = i * 2;
    while (j <= high)
    {
        if (j + 1 <= high && b[j] < b[j + 1])
            j = j + 1;
        if (b[i] >= b[j])
            break;
        swap(b[i], b[j]);
        i = j;
        j = i * 2; //之所以指乘二是要理解我们只需要调整堆的顶点
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int p = 1;
    while (p < n && b[p - 1] <= b[p])
        p++;
    int index = p;
    while (p <= n && a[p] == b[p])
        p++;
    if (p == n + 1)
    {
        printf("Insertion Sort\n");
        sort(b.begin() + 1, b.begin() + index + 1);
    }
    else
    {
        printf("Heap Sort\n");
        p = n;
        while (p > 2 && b[p] >= b[1])
            p--;
        swap(b[1], b[p]);
        downAdjust(b, 1, p - 1);
    }
    printf("%d", b[1]);
    for (int i = 2; i <= n; i++)
        printf(" %d", b[i]);
    return 0;
}