#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    string a;
    string temp;
    int i;
    int tag=0;
    vector<string> v,vi;
    cin >> a;
    if(a[0]=='-'){
        cout << "Fu ";
        a = a.substr(1, a.length());//先到者为准
    }
    // reverse(a.begin(),a.end());
    // cout << a;
    for (i = 0; i < a.length();i++){
        switch(a[i]){
            
            case '1' : vi.push_back("yi");break;
            case '2': vi.push_back("er");break;
            case '3' : vi.push_back("san");break;
            case '4' : vi.push_back("si");break;
            case '5' : vi.push_back("wu");break;
            case '6' : vi.push_back("liu");break;
            case '7' : vi.push_back("qi");break;
            case '8' : vi.push_back("ba"); break;
            case '9' : vi.push_back("jiu"); break;
            case '0' : vi.push_back("ling"); break;
        }

    }
    
    for (i = 0; i < a.length();i++){
        if(vi[i]=="ling"){
            tag ++;
            
        }else{
            if(tag>0&&tag!=i&&((a.length()-i)!=4))//101000 ->一十零一千
                vi[i] = "ling " + vi[i];
            tag = 0;
        }
        if(tag>=1){
            if((a.length()-i)==5&&(a.length()<9))  {//&&tag!=i
                temp = "Wan";
                v.push_back(temp);
                }
            if(a.length()==1){//这里漏了只有一个0的情况!
                v.push_back("ling");
            }
                continue;
        }
        switch(a.length()-i){
            case 9:   temp = vi[i]+" "+"Yi";v.push_back(temp);break;
            case 8:   temp = vi[i]+" "+"Qian";v.push_back(temp);break;
            case 7:   temp = vi[i]+" "+"Bai";v.push_back(temp);break;
            case 6:   temp = vi[i]+" "+"Shi";v.push_back(temp);break;
            case 5:   temp = vi[i]+" "+"Wan";v.push_back(temp);break;
            case 4:   temp = vi[i]+" "+"Qian";v.push_back(temp);break;
            case 3:   temp = vi[i]+" "+"Bai";v.push_back(temp);break;
            case 2:   temp = vi[i]+" "+"Shi";v.push_back(temp);break;
            case 1:   temp = vi[i];v.push_back(temp);break;
        }
    }
    
    int cnt = v.size();
    for (i = 0; i < cnt;i++){
        cout << v[i];
        if(i!=cnt-1)  cout << " ";
    }

        return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string num[10] = { "ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string c[6] = { "Ge","Shi", "Bai", "Qian", "Yi", "Wan" };
int J[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
vector<string> res;
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "ling";
        return 0;
    }
    if (n < 0) {
        cout << "Fu ";
        n = -n;
    }
    int part[3];
    part[0]= n / 100000000; 
    part[1]= (n % 100000000) / 10000;
    part[2] = n % 10000;
    bool zero = false; //是否在非零数字前输出合适的ling
    int printCnt = 0; //用于维护单词前没有空格，之后输入的单词都在前面加一个空格。
    for (int i = 0; i < 3; i++) {
        int temp = part[i]; //三个部分，每部分内部的命名规则都一样，都是X千X百X十X
        for (int j = 3; j >= 0; j--) {
            int curPos = 8 - i * 4 + j; //当前数字的位置
            if (curPos >= 9) continue; //最多九位数
            int cur = (temp / J[j]) % 10;//取出当前数字
            if (cur != 0) {
                if (zero) {
                    printCnt++ == 0 ? cout<<"ling" : cout<<" ling";
                    zero = false;
                }
                if (j == 0)
                    printCnt++ == 0 ? cout << num[cur] : cout << ' ' << num[cur]; //在个位，直接输出
                else                             
                    printCnt++ == 0 ? cout << num[cur] << ' ' << c[j] : cout << ' ' << num[cur] << ' ' << c[j]; //在其他位，还要输出十百千
            } else {
                if (!zero && j != 0 && n / J[curPos] >= 10) zero = true;   //注意100020这样的情况
            }
        }
        if (i != 2 && part[i]>0) cout << ' ' << c[i + 4]; //处理完每部分之后，最后输出单位，Yi/Wan
    }
    return 0;
}*/