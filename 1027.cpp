#include<stdio.h>
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    char s[14] = "0123456789abc";
    printf("#%c%c%c%c%c%c", s[a / 13], s[a % 13], s[b / 13], s[b % 13], s[c / 13], s[c % 13]);
    return 0;

}