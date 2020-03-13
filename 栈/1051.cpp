#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k;i++){
        bool flag = false;
        stack<int> s;
        vector<int> v(m);
        for (int j = 0; j < m;j++){
            scanf("%d", &v[j]);
        }
        int current = 0;
        for (int j = 1; j < m+1;j++){
            s.push(j);
            if(s.size()> n)
                break;
            // cout << s.top() << endl;
            while(!s.empty() && s.top() == v[current]) {
                // cout << v[current]<<endl;
                s.pop();
                current++;
            }
        }
        if(current == m)
            flag = true;
        if(flag == true)
            cout << "YES" << endl;
        else
            cout << "NO"<<endl;
    }
        return 0;
}