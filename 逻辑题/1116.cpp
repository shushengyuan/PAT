#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int a) {
    if(a <= 1) return false;
    int Sqrt = sqrt((double)a);
    for(int i = 2; i <= Sqrt; i++) {
        if(a % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n, k;
    cin >> n;
    vector<string> v(10001);
    vector<int> a(10001);
    int temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        if(i == 1)
        {
            v[temp] = "Mystery Award";
        }
        else if(isPrime(i))
        {
            v[temp] = "Minion";
        }
        else
        {
            v[temp] = "Chocolate";
        }
    }
    string s;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> s;
        int temp = stoi(s);
        if (v[temp] != "")
        {

            cout << s << ": ";
            if (a[temp] == 0)
            {
                a[temp] = 1;
            cout << v[temp] << endl;
            }
            else
            {
                cout << "Checked" << endl;
            }
        }
        else
        {
            cout << s << ": "
                 << "Are you kidding?" << endl;
        }
    }
}