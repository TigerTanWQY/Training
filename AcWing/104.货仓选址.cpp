#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int x = a[n / 2 + 1], ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += abs(a[i] - x);
	cout << ans;
	cout << endl;
	return 0;
}