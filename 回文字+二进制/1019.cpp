#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    int arr[100];
    int len = 0;
    do{
        arr[len++] = n % d;
        n = n / d;
    } while (n != 0);
    int a[100], b[100];
    for (int i = 0; i < len; i++)
        a[i] = arr[i];
    for (int i = len - 1; i >= 0; i--)
        b[len - i - 1] = arr[i];
    for(int i = 0;i<len;i++)    {
        if(a[i]!=b[i]) {
            cout << "No" << endl;
        for(int j = len-1;j>0;j--)    printf("%d ",arr[j]);
        printf("%d",arr[0]);
        return 0;
        }
    }
    cout<<"Yes"<<endl;
    for(int i = 0;i<len-1;i++)
        printf("%d ", arr[i]);
    printf("%d",arr[len-1]);
    return 0;
}