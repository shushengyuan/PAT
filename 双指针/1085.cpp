#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main() {
	int n;
	long long p;
	cin >> n >> p;
	if (n == 0) {
		cout << n;
		return 0;
	}
	long long int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int result = 1;
	for (int i = 0; i < n; i++) {
		result = max((int)(lower_bound(a, a+n, a[i] * p) - (a+i)), result);
        // cout << (int)(lower_bound(a, a+n, a[i] * p) - (a+i));

    }
	cout << result;
	return 0;
}