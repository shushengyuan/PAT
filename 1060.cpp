#include<stdio.h>
#include<cctype>
#include<iostream>
using namespace std;
int main(){
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    char s[2];
    int i = 0;
    int j = 0;
    int postion=0;
    while(i<a.length()&&i<b.length()){
        if(a[i]==b[i]&&('A'<=a[i]&&a[i]<='G')){
            s[0] = a[i];
            break;
        }
        i++;
    }
    i++;
    while(i<a.length()&&i<b.length()){
        if(a[i]==b[i]&&(('A'<=a[i]&&a[i]<='N')||isdigit(a[i]))){
            s[1] = a[i];
            break;
        }
        i++;
    }
    while(j<c.length()&&j<d.length()){
        if(c[j]==d[j]&&(isalpha(c[j]))){
            postion = j;
            break;
        }
        j++;
    }

    string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    int m = isdigit(s[1]) ? s[1] - '0' : s[1] - 'A' + 10;
    cout << week[s[0] - 'A'];
    printf("%02d:%02d", m, postion);
    return 0;
}