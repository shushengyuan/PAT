#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int N = s.length();
    // cout << N << endl;
    int x = min((N+2)/3,(N-1)/2);
    x = max(1,x);
    int i;
    int j = (N - 2 * x);
    // cout << j+2 << endl;
    
    for (i = 0; i < x-1;i++){
        printf("%c", s[i]);
        for (int k = 0; k < j;k++)
            printf(" ");
        printf("%c\n", s[N - i-1]);
    }
    for (i = x-1; i < N -  x + 1;i++)
        printf("%c", s[i]);
        return 0;
}