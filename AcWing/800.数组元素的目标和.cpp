#include <iostream>
using namespace std;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, x;
	cin >> n >> m >> x;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1, j = n, k; i <= m; ++i) {
		cin >> k;
		for(; j && a[j] + k > x; --j);
		if(a[j] + k == x) {
			cout << j - 1 << ' ' << i - 1;
			break;
		}
	}
	return 0;
}