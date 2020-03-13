#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string, int> stringToint;
map<int, string> intTostring;
int n, k;
vector<int> hap;
int cost[205][205];
string start;
int idNumber = 1;
int stoiFunc(string s)
{
    if (stringToint[s] == 0)
    {
        stringToint[s] = idNumber;
        intTostring[idNumber] = s;
        idNumber++;
        return idNumber;
    }
    else
    {
        return stringToint[s];
    }
}
int main()
{
    cin >> n >> k;
    cin >> start;
    hap.resize(n + 1);
    string tempString;
    int tempInt;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> tempString;
        cin >> tempInt;
        int id = stoiFunc[tempString];
        hap[id] = tempInt;
    }
    string tempString1;
    string tempString2;
    for (int i = 0; i < k; i++)
    {
        cin >> tempString1;
        cin >> tempString2;
        int id1 = stringToint[tempString1];
        int id2 = stringToint[tempString2];
        int tempint1;
        cin >> tempint1;
        cost[id1][id2] = cost[id2][id1] = tempint1;
    }
    return 0;
}