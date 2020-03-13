#include<cstdio>
#include<iostream>  
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    string s, rs;
    getline(cin, s);
    rs = s;
    reverse(rs.begin(), rs.end());
    // cout << rs[4] << a;
    int num = 0;
    int maxt = 0;
    int flag = 0;
    for (int i = 0; i < s.length();i++){
        for (int j = 0; j < s.length();j++){    
            // cout << s[i] << endl;
            // cout << rs[j] << endl;
            if(s[i]==rs[j]){
                num++;
                // cout << i << endl;
                // cout << j << endl;
                i++;
                flag = 1;
                // cout << s[i-1] << endl;
                // cout << rs[j] << endl;
                // cout << num << endl;
            }else{

                maxt = max(maxt,num);
                // cout << "max" << maxt << endl;
                num = 0;
            }

    }
    maxt = max(maxt,num);
    num = 0;
    if(flag==1)
        i--;
    }
    maxt = max(maxt,num);
    cout << maxt << endl;
    
    return 0;
}
//上面有个测试点过不了
/*
#include <iostream>
using namespace std;
int dp[1010][1010];
int main() {
    string s;
    getline(cin, s);
    int len = s.length(), ans = 1;
    for(int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if(i < len - 1 && s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            ans = 2;
        }
    }
    for(int L = 3; L <= len; L++) {
        for(int i = 0; i + L - 1 < len; i++) {
            int j = i + L -1;
            if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    printf("%d", ans);
    return 0;
}*/