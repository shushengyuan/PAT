/*#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num = n/2;
    int consecutive = 0;
    // cout << num;
    vector<int> v;
    int flag = 0;
    for (int i = 2; i <= num;i++){
        if (n % i == 0){
            flag = 1;
            // cout << i << endl;
            v.push_back(i);
            consecutive++;
        }
        flag = 0;
    }
    // cout << consecutive << endl;
    int sum = 0;
    int temp = 1;
    // int tempx ;
    vector<int> v1;
    v1.push_back(v[consecutive - 1]);
    for (int i = consecutive - 1; i > 0; i--)
    {
        if (v[i-1] == v[i]-1)
        {
            v1.push_back(v[i-1]);
            temp++;
            
        }
        else
        {
            if(temp > sum){
                v1.clear();
                for (int j = 1; j <= temp;j++){
                    // cout << v[i + j]<<endl;
                    v1.push_back(v[i + j]);
                }
            }
            sum = max(sum, temp);
            temp = 1;  
        }
            
            cout << i << endl;
            
            
    }

    sum = max(sum, temp);
    // cout << sum << endl;

    for (int i = sum - 1; i > 0; i--)
    {
        printf("%d*", v1[i]);
    }
    cout << v1[0] << endl;
        return 0;
}*/
#include <iostream>
#include <cmath>
using namespace std;
long int num, temp;
int main(){
    cin >> num;
    int first = 0, len = 0, maxn = sqrt(num) + 1;
    for (int i = 2; i <= maxn; i++) {
        int j; 
        temp = 1;
        for (j = i; j <= maxn; j++) {
            temp *= j;
            if (num % temp != 0)
                break;
        }
        if (j - i > len) {
            len = j - i;
            first = i;
        }
    }
    if (first == 0) {
        cout << 1 << endl << num;
    } else {
        cout << len << endl;
        for (int i = 0; i < len; i++) {
            cout << first + i;
            if (i != len - 1) cout << '*';
        }
    }
    return 0;
}