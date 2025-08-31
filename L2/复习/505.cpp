#include <iostream>
#include <algorithm>
using namespace std;

int a[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1, tot = 0; i <= n; ++i) {
		tot += a[i];
		if(tot > k) {
			cout << i - 1 << endl;
			return 0;
		}
	}
	cout << n << endl;
	return 0;
}