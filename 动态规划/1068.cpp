/*#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    int base = 0;
    for (int i = 0; i < N;i++){
        base = v[i];
        // cout << base << endl;
        for (int j = i+1; j < N;j++){
            base += v[j];
            // cout << base << endl;
            if(base > M){
                break;
            }else if(base <M){
                cout << j << base << endl;
                continue;
            }else if(base == M){
                cout << j << endl;
                return 0;
            }
        }
    }
    return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10010], w[10010];
bool choice[10010][110];
int cmp1(int a, int b){return a > b;}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    sort(w + 1, w + n + 1, cmp1);
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= w[i]; j--) {
            if(dp[j] <= dp[j-w[i]] + w[i]) {
                choice[i][j] = true;
                dp[j] = dp[j-w[i]] + w[i];
            }
        }
    }
    if(dp[m] != m) printf("No Solution");
    else {
        vector<int> arr;
        int v = m, index = n;
        while(v > 0) {
            if(choice[index][v] == true) {
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}