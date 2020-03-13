#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
struct node
{
    int age;
    char s[10];
    int worth;
};
vector<node> v;
bool cmp1(node a, node b)
{
    if (a.worth == b.worth)
    {
        return a.age == b.age ? strcmp(a.s, b.s) < 0 : a.age < b.age;
    }
    else
    {
        return a.worth > b.worth;
    }
}
int main()
{
    int n, q;
    cin >> n >> q;
    v.resize(n);
    vector<node> vt;
    vector<int> book(205, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", v[i].s);
        cin >> v[i].age >> v[i].worth;
        
    }
    sort(v.begin(), v.end(), cmp1);
    for(int i = 0; i < n; i++) {
        if(book[v[i].age] < 100) {
            vt.push_back(v[i]);    
            book[v[i].age]++;
        }
    }
    int  num, minn, maxn;   
    for (int i = 0; i < q; i++)
    {
        // cin >> temp;
        cin >> num;
        cin >> minn >> maxn;
        cout << "Case #" << i + 1 << ":" << endl;

        int k = 0;
        int total = 0;
        while (total != num && k != n)
        {
            if (vt[k].age >= minn && vt[k].age <= maxn)
            {
                cout << vt[k].s << " ";
                cout << vt[k].age <<" "<< vt[k].worth << endl;
                total++;
            }
            // cout<< v[k].worth << endl;
            k++;
        }
        if(total == 0)
            cout << "None" << endl;
    }

    return 0;
}