/*#include<cstdio>
#include<iostream>  
#include<algorithm>
#include<cmath>
using namespace std;
long long result;

long long Erfen(int a,string s,long long b){
    //a  ~ 35
    long long left1 = a + 1;
    long long right1 = max(b,left1);
    long long temp ;
    long long t;
    long long tempx;
    while(left1 <= right1){
    tempx = (left1 + right1) / 2;
    temp = 0;
    int index = 0;
    for (int i = 0; i < s.length();i++){
        t = isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10;
        temp += t * pow(tempx, index++);
        // cout << temp << endl;
    }
    if(temp > b || temp < 0){
        right1 = tempx - 1;
    }else if(temp == b){
        return tempx;
    }else{
        left1 = tempx + 1;
    }
    }
    
    return -1;
}
int main(){
    string a, b;
    int n, m;
    cin >> a >> b >> n >> m;
    long long t=0;
    long long radix = 0;
    // int tempm1 = 0, tempm2 = 0;
    // cout << a[0] << endl;

    long long result1 = t;
    long long result2 = t;
    // cout << result2 << endl;
    int index1 = 0;
    int index2 = 0;
    if(n==1){
        
        for (int i = 0; i < a.length();i++) {
        t = isdigit(a[i]) ? a[i] - '0' : a[i] - 'a' + 10;
        result1 += t * pow(m, index1++);
    }
    // cout << result1 << endl;

    radix = max(radix, result2);
    for (int i = 0; i < b.length(); i++)
    {
        t = isdigit(b[i]) ? b[i] - '0' : b[i] - 'a' + 10;
        radix = max(radix, t);
            
        }
        radix++;
        // cout << radix << endl;
        // cout << result1 << endl;
        result = Erfen(radix,b, result1);
        // result2 = result;
        // cout << result2 << endl;
    }
    else if(n==2){
        for (int i = 0; i < b.length();i++) {
        t = isdigit(a[i]) ? b[i] - '0' : b[i] - 'a' + 10;
        result2 += t * pow(m, index2++);
    }
        
        
        radix = max(radix, result1);
        for (int i = 0; i < a.length();i++){
            t = isdigit(a[i]) ? a[i] - '0' : a[i] - 'a' + 10;
            radix = max(radix, t);
            
        }
        radix++;
        // cout << radix << endl;
        // cout << result2 << endl;
        result = Erfen(radix,b, result2);
        // result1 = result;
        // cout << result2 << endl;
    }


    if(result != -1)
        printf("%lld", result);
    else
        cout << "Impossible";

    return 0;
}*/

#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;
long long convert(string n, long long radix) {
    long long sum = 0;
    int index = 0, temp = 0;
    for (int it = n.begin(); it <= n.end(); it++) {
        temp = isdigit(n[it]) ? n[it] - '0' : n[it] - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}
long long find_radix(string n, long long num) {
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if (t < 0 || t > num) high = mid - 1;
        else if (t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}
int main() {
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        printf("Impossible");
    }   
    return 0;
}