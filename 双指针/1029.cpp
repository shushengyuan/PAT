#include<iostream>
using namespace std;
int k[200005];
int main(){
    int m, n, cnt = 0;
    int temp;
    int i,j;
    cin >> m;
    for (i = 1; i <= m;i++)
        scanf("%d", &k[i]);//用cin会超时 建议遇到大量数据的时候用C语言的格式化输入输出。
    i = 1;
    k[m+1] = 0x7fffffff;
    cin >> n;
    int medpos = (n + m + 1) / 2;
    for (j = 1; j <= n;j++){
        cin >> temp;
        while(k[i]<temp){
            cnt++;
            if(cnt==medpos){
                cout << k[i];
                break;
            }
            i++;
        }
        cnt++;
        if(cnt==medpos){
            cout << temp;
            break;
        }
    }
    while(i<=m){
        cnt++;
        if(cnt == medpos){
             cout << k[i];
             break;
        }
           
        i++;
    }
        return 0;
}