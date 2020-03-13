#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
struct tree{
    char ID[2];
    int k;
};
int main(){
    int m,n;
    int i;
    cin >> n >> m;
    for (i = 0; i < m; i++){
        tree T[100];
        char ID[100][2];
        int k;
        int j;
        char strings[100][2];
        cin >> ID[i];
        cin >> k;
        strcpy(T->ID, ID[i]);
        T->k = k;
        for (j = 0; j < k; j++)
        {
            cin >> strings[j];
        }
    //读取完毕

    }
        return 0;
}