#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    string a = "PAT";
    // cout << a[0] << endl;
    vector<int> v;
    long long f1 =0;
    long long f2 = 0;
    long long total = 0;
    long long flag1[100001];
    long long flag2[100001];
    // bool PA[100001][100001];
    // bool AT[100001][100001];
    for (int base = 0; base < s.length(); base++)
    {
        if (s[base] == a[0]){
            f1++;
        }
        if (s[base] == a[2]){
            f2++;
        }
            flag1[base] = f1;
            flag2[base] = f2;
            // cout << flag1[base] << endl;
            // cout << flag2[base] << endl;
    }
    for (int base = 0; base < s.length(); base++)
    {
        if(s[base] == a[1]){
        int temp1 = flag1[base];
        int temp2 = flag2[s.length()-1] - flag2[base];
        total += temp1 * temp2;

        }

    }
    
        printf("%lld", total % 1000000007);
        return 0;
}