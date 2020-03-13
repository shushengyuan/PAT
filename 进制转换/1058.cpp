#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    long int a[3];
    long int a1[3];
    long int res[3];
    scanf("%ld.%ld.%ld",&a[2],&a[1],&a[0]);
    scanf("%ld.%ld.%ld",&a1[2],&a1[1],&a1[0]);
    int temp = 0,temp1;
    res[0] = a[0]+a1[0];
        temp1 = res[0];
        res[0] = res[0] % 29;
        temp = temp1/29;
    res[1] = a[1]+a1[1]+ temp;
        temp1 = res[1];
        // cout << temp1 << endl;
        res[1] = res[1]%17 ;
        // cout << res[1] << endl;
        temp = temp1/17;
    
    res[2] = ((a[2]+a1[2])+temp);
    cout<<res[2]<<'.'<<res[1]<<'.'<<res[0];
    
    return 0;
}