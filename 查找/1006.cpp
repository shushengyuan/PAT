#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int m;
    scanf("%d", &m);
    
    string name,res1,res2;
    int i;
    int minn=INT_MAX, maxn=INT_MIN;
    for (i = 0; i < m;i++){
        cin >> name;
        int HH, MM, SS;
        int LHH, LMM, LSS;
        scanf("%d:%d:%d %d:%d:%d", &HH, &MM, &SS, &LHH, &LMM, &LSS);
        int times1 = HH * 3600 + MM * 60 + SS;
        int times2 = LHH * 3600 + LMM * 60 + LSS;
        if(times1<minn){
            minn = times1;
            res1 = name;
        }
        if(times2>maxn){
            maxn = times2;
            res2 = name;
        }
    }
    cout << res1 << " " << res2;
    return 0;
}