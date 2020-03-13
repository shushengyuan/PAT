#include <iostream>
#include <algorithm>
using namespace std;
int m, n, c1, c2;
int weight[501], c2c[501][501], w[501], num[501], dis[501];
const int inf = 99999999;
bool visit[501];
int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0;i<n;i++){
        scanf("%d",&weight[i]);
    }
    int a, b, c;
    for (int j = 0; j < m;j++){
        scanf("%d%d%d", &a, &b, &c);
        c2c[a][b] = c2c[b][a] = c;
    }
    num[c1] = 1;
    w[c1] = weight[c1];
    dis[c1] = 0;
    for (int i = 0; i < n;i++){
        int u = -1, mini = inf;
        for (int j = 0; j < n;j++){
            if(visit[j] == false && dis[j]<mini){
                u = j;
                mini = dis[j];
            }
        }
    if(u==-1)    break;
    visit[u] = true;
    for (int k = 0; k < n;k++){
        if(visit[k]==false && c2c[k][u]!=mini){
            if(c2c[k][u]+dis[k]<dis[u]){
                dis[k] = dis[u] + c2c[k][u];
                num[k] = num[u];
                w[k] = w[u] + weight[k];
            }else if(c2c[k][u]+dis[k]==dis[u]){
                num[k] = num[k] + num[u];
                、】 f(w[u] + weight[k] > w[k])
                        w[k] = w[u] + weight[k];
            }
        }
    }
    }
     printf("%d %d", num[c2], w[c2]);
        return 0;
}