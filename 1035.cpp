/*
#include<stdio>
using namespace std;
int main(0){
    char a[1000][10],b[1000][10];
    int num,i,j;
    int sum=0;
    cin>>num;
    for(i=0;i<num;i++）{
        cin>>a[i];
        cin>>b[i];
        if(b[i].find('0')||b[i].find('o')||b[i].find('1')||b[i].find('l')){
            sum++;
            if(b[i].find('0')){
                b[i][b[i].find('0')] = '%';
            }
            if(b[i].find('1')){
                b[i][b[i].find('1')] = '@';
            }
            if(b[i].find('l')){
                b[i][b[i].find('l')] = 'L';
            }
            if(b[i].find('O')){
                b[i][b[i].find('0')] = 'o';
            }
        }
    }
    if(sum == 0){
        cout<<"There are ";
        cout<<num;
        cout<<"accounts and no account is modified"<<end;
    }
    if(sum != 0){
        cout << sum << endl;
        for (i = 0; i < num;i++){
            cout << a[i];
            cout << ' ' << endl;
            cout << b[i] << endl;
        }
    }

    return 0;
}
*/

//利用vecotr
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<string> v;
    for(int i = 0; i < n; i++) {
        string name, s;
        cin >> name >> s;
        int len = s.length(), flag = 0;
        for(int j = 0; j < len; j++) {
            switch(s[j]) {
                case '1' : s[j] = '@'; flag = 1; break;
                case '0' : s[j] = '%'; flag = 1; break;
                case 'l' : s[j] = 'L'; flag = 1; break;
                case 'O' : s[j] = 'o'; flag = 1; break;
            }
        }
        if(flag) {
            string temp = name + " " + s;
            v.push_back(temp);
        }
    }
    int cnt = v.size();
    if(cnt != 0) {
        printf("%d\n", cnt);
        for(int i = 0; i < cnt; i++)
            cout << v[i] << endl;
    } else if(n == 1) {
        printf("There is 1 account and no account is modified");
    } else {
        printf("There are %d accounts and no account is modified", n);
    }
    return 0;
}