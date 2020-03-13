#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    vector<int> num,num1;
    for (int i = 0; i < s.size();i++){
        num.push_back(s[i] - '0');
        num1.push_back(s[i] - '0');
    }
    int t = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        // cout << num[i] << endl;
        int temp = num[i];
        num[i] = num[i] * 2 % 10 + t;
        t = temp * 2 / 10;
        // cout << t << endl;
    }
    vector<int> v,v1;
    
    if(t!=0){
        
        cout << "No" << endl;
        cout << t;
        for (int i = 0; i < s.size() ; i++){
            printf("%d", num[i]);
        }
        return 0;
    }
    for (int i = 0; i < s.size() ; i++)
    {
        v.push_back(num[i]);
        v1.push_back(num[i]);
    }
    sort(v.begin(), v.end());
    sort(num1.begin(), num1.end());
    for (int i = 0; i < s.size();i++){
        // cout << num1[i] << endl;
        // cout << v[i] << endl;
        if(num1[i]!=v[i]){
            cout << "No" << endl;
            for (int i = 0; i < s.size() ; i++){
            printf("%d", v1[i]);
        }
        return 0;
        }

    }
    cout << "Yes" << endl;
    for (int i = 0; i < s.size() ; i++){
            printf("%d", v1[i]);
    }

    return 0;
}
/*
#include <cstdio>
#include <string.h>
using namespace std;
int book[10];
int main() {
    char num[22];
    scanf("%s", num);
    int flag = 0, len = strlen(num);
    for(int i = len - 1; i >= 0; i--) {
        int temp = num[i] - '0';
        book[temp]++;
        temp = temp * 2 + flag;
        flag = 0;
        if(temp >= 10) {
            temp = temp - 10;
            flag = 1;
        }
        num[i] = (temp + '0');
        book[temp]--;
    }
    int flag1 = 0;
    for(int i = 0; i < 10; i++) {
        if(book[i] != 0)
            flag1 = 1;
    }
    printf("%s", (flag == 1 || flag1 == 1) ? "No\n" : "Yes\n");
    if(flag == 1) printf("1");
    printf("%s", num);
    return 0;
}
*/