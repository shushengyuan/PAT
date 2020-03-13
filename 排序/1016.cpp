#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct node{
    
    string name;
    int yy, dd, hh, mm;
    int sum;
    string line;
    int total;
    int flag;
};
bool temp(node v1, node v2){
    return v1.name != v2.name ? v1.name < v2.name : v1.sum < v2.sum;
}

int main(){
    int rate[24];
    for (int i = 0; i < 24;i++){
        cin >> rate[i];
    }
    int temptime = 0;
    for (int j = 0; j <= 23; j++){
        temptime += 60 * rate[j];
    }
    int n;
    cin >> n;
    vector<node> v(n);
    map<string, int > custom;
    for (int i = 0; i < n;i++){
        // cout << "start" << endl;
        cin >> v[i].name;
        scanf("%d:%d:%d:%d",  &v[i].yy, &v[i].dd, &v[i].hh, &v[i].mm);
        cin >> v[i].line;
        v[i].sum = v[i].dd * 24 * 60 + v[i].hh * 60 + v[i].mm;
        v[i].total = 0;
        v[i].flag = 0;
        // custom[v[i].name] = v[i].flag;
    }
    sort(v.begin(), v.end(), temp);
    // cout << endl;
    // for (int i = 0; i < n;i++){
    //     // cout << "start" << endl;
    //     cout << v[i].name << " " << v[i].yy << ":" << v[i].dd 
    //             << ":" << v[i].hh << ":" << v[i].mm << ":" << " " << v[i].line << endl;
    // }
    // int tempx;
    int total = 0;
    
    for (int i = 0; i < n-1;i++){
        if (v[i].line == "on-line" && v[i + 1].line == "off-line" && v[i].name == v[i + 1].name){
            total = 0;
        
            if(v[i].dd == v[i+1].dd){
            total += (60 - v[i].mm) * rate[v[i].hh];
            
            for (int j = v[i].hh + 1; j < v[i + 1].hh; j++){
                total += 60 * rate[j];
            }
            total += v[i + 1].mm * rate[v[i + 1].hh];
            
            }else{
                total += (60 - v[i].mm) * rate[v[i].hh];
                
                for (int j = v[i].hh + 1; j <= 23; j++){
                    total += 60 * rate[j];
                }
                total += (v[i + 1].dd - v[i].dd - 1) * temptime;
                for (int j = 0; j < v[i + 1].hh; j++){
                    total += 60 * rate[j];
                }
                 total += v[i + 1].mm * rate[v[i + 1].hh];
            }

            // custom[v[i].name].push_back(v[i]);
            v[i].total = total;
            // cout << total << endl;
        }
        else
        {
            continue;
        }
    }
    int totalsum = 0;
    for (int i = 0; i < n-1;i++){
        if (v[i].total > 0){
            if(custom[v[i].name]==0){
            cout << v[i].name;
            printf(" %02d\n", v[i].yy);
            printf("%02d:%02d:%02d %02d:%02d:%02d", v[i].dd, v[i].hh, v[i].mm, v[i + 1].dd, v[i+1].hh, v[i + 1].mm);
            printf(" %d $%d.%02d\n", v[i+1].sum-v[i].sum,v[i].total/100,v[i].total%100);
            totalsum = v[i].total;
            custom[v[i].name] = 1;
        }else{
            printf("%02d:%02d:%02d %02d:%02d:%02d", v[i].dd, v[i].hh, v[i].mm, v[i + 1].dd, v[i+1].hh, v[i + 1].mm);
            printf(" %d $%d.%2d\n", v[i+1].sum-v[i].sum,v[i].total/100,v[i].total%100);
            totalsum += v[i].total;
        }
       
        }
         if(v[i+1].name != v[i].name){
            printf("Total amount: $%02d.%02d\n", totalsum / 100, totalsum % 100);
        }
    }
    printf("Total amount: $%d.%02d\n", totalsum / 100, totalsum % 100);

    return 0;
}