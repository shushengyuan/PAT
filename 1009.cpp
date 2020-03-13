#include<cstdio>
// #include<iostream>
using namespace std;
int main(){
    double c[1001] = {0.0};
    double d[2001] = {0.0};
    int n;
    scanf("%d", &n);
    int i;
    int num1;
    double n1;
    for (i = 0; i < n;i++){
        scanf("%d%lf", &num1, &n1);
        c[num1] = n1;
    }
    int m;
    scanf("%d",&m);
    int j;
    int num2;
    double m1;
    for (j = 0; j < m;j++){
        scanf("%d%lf", &num2, &m1);
        for (i = 0; i < 1001;i++){
            d[i + num2] += c[i] * m1;
        }
    }   
    int cnt = 0;

    for (i = 0; i <= 2000;i++){
        if(d[i]!=0.0){
            cnt++;
        }
    }
    printf("%d", cnt);
    for (i = 2000; i >= 0; i--)
    {
        if(d[i]!=0.0){
            printf(" %d ", i);
            printf("%.1f", d[i]);
        }
    }
    return 0;
}