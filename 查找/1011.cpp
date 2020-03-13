#include<cstdio>
#include<iostream>
// #include<climits>
using namespace std;
int main(){
    double a[3][3] = {{0.0}};
    int i, j;
    double b[3] = {0};
    int c[3] = {0};
    double maxn = 0.0;

    for (i = 0; i < 3;i++){
        for (j = 0; j < 3;j++){
            cin >> a[i][j];
            if(a[i][j] > maxn){
                maxn = a[i][j];
                c[i] = j;
            }
            
        }
        b[i] = maxn;
        maxn = 0.0;
    }

    for (i = 0; i < 3;i++){
        if(c[i] == 0)
            cout << "W ";
        if(c[i] == 1)
            cout << "T ";
        if(c[i] == 2)
            cout << "L ";
    }
    double res = 1.0;
    for (i = 0; i < 3;i++){
        res = res * b[i];
    }
    res = (res * 0.65 - 1) * 2;
    printf("%.2f", res);
    // cout << res;

    // cout << a[0][2];
    return 0;
}  