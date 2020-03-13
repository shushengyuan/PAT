#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    double a[N];
    for (int i = 0; i < N;i++){
        cin >> a[i];
        // printf("%f\n", a[i]);
    }
    double total = 0.0;
    for (int i = 0; i < N;i++){
        total += a[i] * (N-i);
        printf("%.2f\n",total);    
    }
    printf("%.2f\n",total);    
    return 0;
}
/*
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    double sum = 0.0, temp;
    for (int i = 1; i <= n; i++) { 
        cin >> temp;
        sum = sum + temp * i * (n - i + 1);
    }
    printf("%.2f", sum);
    return 0;
}
*/