#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N, M, K;
    cin >> N;
    cin >> M;
    vector<int> v(M);
    for (int i = 0; i < M;i++){
        cin >> v[i];
    }
    cin >> K;
    vector<int> v1(K);
    for (int i = 0; i < K;i++){
        cin >> v1[i];
    }
    vector<int> result;
    int temp = 0;
    for (int i = 0; i < M;i++){
        for (int j = temp; j < K;j++){
                if(v[i]==v1[j]){
                    result.push_back(v1[j]);
                    temp = j;
                }
    }
    }
    //  for (int i = 0; i < result.size();i++){
    //     cout << result[i] << endl;
    //  }
    cout << result.size();
    return 0;
}
/*
C++
#include <iostream>
#include <vector>
using namespace std;
int book[201], a[10001], dp[10001];
int main() {
    int n, m, x, l, num = 0, maxn = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &x);
        book[x] = i;
    }
    scanf("%d", &l);
    for(int i = 0; i < l; i++) {
        scanf("%d", &x);
        if(book[x] >= 1)
            a[num++] = book[x];
    }
    for(int i = 0; i < num; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);
    return 0;
}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
#include <iostream>
#include <vector>
using namespace std;
int book[201], a[10001], dp[10001];
int main() {
    int n, m, x, l, num = 0, maxn = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &x);
        book[x] = i;
    }
    scanf("%d", &l);
    for(int i = 0; i < l; i++) {
        scanf("%d", &x);
        if(book[x] >= 1)
            a[num++] = book[x];
    }
    for(int i = 0; i < num; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);
    return 0;
}
*/