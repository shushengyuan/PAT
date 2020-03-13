// #include<stdio.h>
/*
#include<iostream>
#include<cstring>
#include<cmaths>
using namespace std;
int main(){
    string a;
    cin >> a;
    int i = 1;
    string b = "";
    string c = "";
    if (a[0] == '-')
        cout << "-" << end;
    while (i < a.length())
        {
            if(a[i]=='.')
                continue;
            if(a[i]!='E')
                b.append(a[i]);
            else
                break;
            i++;
        }
        i++;
    while (i < a.length())
        {
            c.append(a[i]);
            i++;
        }
    int num = stoi(c);
    int dig = stoi(b);
    if(num<0){
        cout << "0.";
        while(--num)
            cout << "0";
    }
    cout << b;

    while((abs(num)-(b.length()-1))--){
        cout << "0";
    }
    return 0;

}
*/
#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != 'E') i++;
    string t = s.substr(1, i-1);
    int n = stoi(s.substr(i+1));
    if (s[0] == '-') cout << "-";
    if (n < 0) {
        cout << "0.";
        for (int j = 0; j < abs(n) - 1; j++) cout << '0';
        for (int j = 0; j < t.length(); j++)
            if (t[j] != '.') cout << t[j];
    } else {
        cout << t[0];
        int cnt, j;
        for (j = 2, cnt = 0; j < t.length() && cnt < n; j++, cnt++) cout << t[j];
        if (j == t.length()) {
            for (int k = 0; k < n - cnt; k++) cout << '0';
        } else {
            cout << '.';
            for (int k = j; k < t.length(); k++) cout << t[k];
        }
    }
    return 0;
}