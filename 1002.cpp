#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int i = 0;
    int flag = 0;
    int num1;
    int num2;
    int k1;
    int k2;
    float a1;
    float a2;
    float num[1001]={0};

    cin >> num1;
    for (i=0; i < num1;i++){
        cin >> k1 >> a1;
        num[k1] += a1;
    }

    cin >> num2;
    for (i=0; i < num2;i++){
        cin >> k2 >> a2;
        num[k2] += a2;
    }
    
     for (i = 0; i <=1000 ;i++){
         if(num[i]!=0)
             flag++;
    }
    cout << flag;
    for (i = 1000; i >=0 ;i--){
        if(num[i]==0.0)
            continue;
        else
            printf(" %d %.1f", i, num[i]);
    }
    

        return 0;

}