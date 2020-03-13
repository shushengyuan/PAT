#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int minn=INT_MAX,maxn=INT_MIN;
    string name,temp_name_M,temp_ID_M,temp_name_F,temp_ID_F,gender,ID;
    for(int i=0;i<n;i++){
        
        int grade;
        cin>>name>>gender>>ID>>grade;
        if(gender == "M"){
            if(grade < minn){
                minn = grade;
                temp_name_M = name;
                temp_ID_M = ID;
            }
        }
        if(gender == "F"){
            if(grade > maxn){
                maxn = grade;
                temp_name_F = name;
                temp_ID_F = ID;
            }
        }
    }
    if(maxn != INT_MIN){
        cout << temp_name_F << " " << temp_ID_F << endl;
    }else{
        cout<<"Absent"<<endl;
    }
    if(minn != INT_MAX){
        cout << temp_name_M << " " << temp_ID_M << endl;
    }else{
        cout << "Absent" << endl;
    }

    if((maxn != INT_MIN)&&(minn != INT_MAX)){
        cout << maxn - minn;
    }else{
        cout << "NA";
    }

    return 0;
}