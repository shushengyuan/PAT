#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    int a,b;
    int i=0, j=0;
    cin >> a >> b;
    int c = a+b;    
    if(c<0) cout<<'-';
    c = abs(c);
    char str[20];
    sprintf(str,"%d",c);
    int nums = strlen(str);
    int m = nums / 3;
    int n = nums % 3;

    if(n!=0&&m!=0){
    for(i=0;i<n;i++)    cout<<str[i];
    cout << ',';
    }else if(m==0){
        cout << c;
    }
    for (j = 1; j <= 3 * m; j++){
        cout << str[j + i-1];
        if (j % 3 == 0 && j != 3 * m)
            cout << ',';
    }
         return 0;
}

