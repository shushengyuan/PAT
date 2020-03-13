#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int index,time;
}
int main(){
    int n,m,k,q;//n为窗口数，m为每个窗口的最大容纳量，k为顾客数量，q为输出相关
    cin>>n>>m>>k>>q;
    vector<int> v(k);
    for(int i=0;i<k;i++){
        cin>>v[i];  //take time
    }
    
    return 0;
}