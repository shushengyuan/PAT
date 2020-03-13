#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int sum = -1;
    int num;
    int base = 0;
    int i=-1 ;
    int left = 0, right=N-1;
    int tempindex;
    while(N--){
        cin>>num;
        i++;
        base += num;
        if(base<0){
            base = 0;
            tempindex = i + 1;
        }else if(base>sum){
            left = tempindex;
            right = i;
            sum = base;
        }   
    }
    cout << sum << " " << left << " " << right;
    return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        temp = temp + v[i];
        if (temp < 0) {
            temp = 0;
            tempindex = i + 1;
        } else if (temp > sum) {
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        }
    }
    if (sum < 0) sum = 0;
    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
    return 0;
}
*/