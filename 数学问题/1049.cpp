/*#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int dp[10];
    int n,m;
    string s;
    cin>>s;
    n = stoi(s);
    int num=-1;
    m = n;
    num = s.size();
    // cout<<num<<endl;
    dp[0] = 1;
    for(int i=1;i<num;i++){
        dp[i] = dp[i-1]*9+pow(10,i);
        // cout << dp[i] << endl;
    }
    int total = 0;
    int i;
    for ( i = 0; i < num-1;i++){
        int temp = s[i] - '0';
        // cout << temp << endl;
        // cout << num << endl;

        if(temp == 1){
            total += dp[num - i - 2]+1;
        }else if(temp == 0){
            continue;
        }
        else if(temp>1){
            total += dp[num - i - 2] + (temp - 1)*dp[num - i - 2];
        }
    }
    if(s[i]-'0'!=0){
        total += 1;
    }
    cout << total;
    return 0;
}*/

#include <iostream>
using namespace std;
int main() {
    int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
    scanf("%d", &n);
    while(n / a) {
        left = n / (a * 10), now = n / a % 10, right = n % a;
        if(now == 0) ans += left * a;
        else if(now == 1) ans += left * a + right + 1;
        else ans += (left + 1) * a;
        a = a * 10;
    }
    printf("%d", ans);
    return 0;
}