#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    string n;
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n.length();i++){
        sum += (n[i] - '0');
    }
    string result = to_string(sum);
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cout << arr[result[0] - '0'];
    for (int i = 0; i < result.length();i++){
        cout << ' ' << arr[result[i] - '0'];
    }

    return 0;

}