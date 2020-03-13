#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int N;
    cin>>N;
    string s;
    int a;
    for(int i=0;i<N;i++){
        cin>>s;
        a = stoi(s);
        int a1 = a / (pow(10,(s.length()/2)));
        int a2 = a - a1 * (pow(10,(s.length()/2)));
        if(a1*a2 == 0){
            printf("No\n");
            continue;
        }
        int num = a / (a1 * a2);
        if(a==num*a1*a2){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

/*
#include <iostream>
using namespace std;
int main() {
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        string s = to_string(num);
        int len = s.length();
        int a = stoi(s.substr(0, len/2));
        int b = stoi(s.substr(len/2));
        if (a * b != 0 && num % (a * b) == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
*/