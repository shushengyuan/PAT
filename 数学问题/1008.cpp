#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int m;
    int temp = 0;
    int total = 0;
    for (int i = 0; i < n;i++){
        cin >> m;
        if(m>temp){
            total += (m - temp) * 6;
            //    cout << total << endl;
            temp = m; 
        }
        // cout << temp << endl;
        if(m<temp){
            total += (temp - m) * 4;
            temp = m; 
            // cout << total << endl;
        }
        
        
    }
    // cout << total << endl;
    // cout<<num<<endl;
    total += n * 5;
    cout << total;
    return 0;
}