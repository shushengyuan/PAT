
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int cnt = 1;
    int i;
    for (i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        if (cnt > n / 2)
        {
            break;
        }
    }
    cout << nums[i] << endl;
}
