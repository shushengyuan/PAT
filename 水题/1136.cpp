    #include<cstdio>
    #include<iostream>
    // #include<string>
    #include<algorithm>
    using namespace std;
    string add(string s,string rs){
        string s1 = s;
        int carry = 0;
        for (int i = s.size() - 1; i >= 0;i--){
            s1[i] = (s[i] - '0' + rs[i] - '0' + carry) % 10 + '0';
            carry = (s[i] - '0' + rs[i] - '0' + carry) / 10;
        }
        if(carry ==1){
            s1 = '1' + s1;
        }
        return s1;
    }
    int main(){
        
        string s ;
        cin >> s;
        string sum;
        // cout << s << endl;
        string rs = s;
        reverse(rs.begin(), rs.end());
        if(rs ==s){
        cout << s << " is a palindromic number.\n";
        return 0;
        }
        int k = 0;
    while(k!=10){

        sum = add(s, rs);
        cout << s << " + " << rs << " = " << sum << endl;
        s = sum;
        rs = s;
        reverse(rs.begin(), rs.end());
        if(rs ==s){
        cout << s << " is a palindromic number.\n";
        return 0;
    }
        k++;
    }
    cout << "Not found in 10 iterations.";
    return 0;
    }