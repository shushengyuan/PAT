#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int nodes[1000] = {0};
struct node
{
    int value;
    int l , r ;
    int num = 0;
};
int k;
int templ = 1;
// int tempr = 1;
vector<node> v;
void build(int root, int start)
{
    if (start >= k)
    {
        return;
    }
    if (v[start].value > v[root].value)
    {
        // cout << v[start].value <<" "<<v[root].value<< endl;
        if (v[root].r == -100010010)
        {
            v[root].r = start;
            // templ++;
            v[start].num = templ;
            // cout << templ << endl;
            
            templ = 1;
            build(0, start + 1);
        }
        else
        {
            templ++;
            build(v[root].r, start);
        }
    }
    else if (v[start].value <= v[root].value)
    {
        // cout << v[start].value <<" "<<v[root].value<< endl;
        if (v[root].l == -100010010)
        {
            v[root].l = start;
            
            v[start].num = templ;
            templ = 1;
            build(0, start + 1);
        }
        else
        {
            templ++;
            build(v[root].l, start);
        }
    }
}
int cmd(node v1, node v2)
{
    return v1.num > v2.num;
}
int main()
{
    int n;
    cin >> n;
    k = n;
    
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].value;
        v[i].l = -100010010;
        v[i].r = -100010010;
    }
    if(n<=0){
        v[0].l = -100010010;
        v[0].r = -100010010;
    }
    build(0, 1);
    sort(v.begin(), v.end(), cmd);
    int temp1 = v[0].num;
    // int temp2 = 0;
    int result[1000] ={0};
    for (int i = 0; i < v.size(); i++)
    {
        result[v[i].num]++;
    }
    int tot = result[temp1] + result[temp1 - 1];
    cout << result[temp1]<< " + " << result[temp1-1] <<" = "<<tot<< endl;
    return 0;
}