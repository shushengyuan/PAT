#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char s1[100000], s2[100000];
int main(){
    cin.getline(s1, 100000);
    cin.getline(s2, 100000);
    int lens1 = strlen(s1), lens2 = strlen(s2);
    bool flag[256] = {false};
    for(int i = 0; i < lens2; i++){
        flag[s2[i]] = true;
        if(s2[i]>='a'&&s2[i]<='z'){
            flag[s2[i]+'A'-'a'] = true;
        }else if(s2[i]>='A'&&s2[i]<='Z'){
            flag[s2[i] -('A'-'a')] = true;
        }
    }
    for(int i = 0; i < lens1; i++) {
        if(!flag[s1[i]]){
            flag[s1[i]] = true;
            if(s1[i]>='a'&&s1[i]<='z'){
            flag[s1[i]+'A'-'a'] = true;
        }else if(s1[i]>='A'&&s1[i]<='Z'){
            flag[s1[i] -('A'-'a')] = true;
        }
        if(s1[i]>='a'&&s1[i]<='z'){
            printf("%c", s1[i]+'A'-'a');
        }else {
            printf("%c", s1[i]);
        }
        }
    }
    return 0;

}