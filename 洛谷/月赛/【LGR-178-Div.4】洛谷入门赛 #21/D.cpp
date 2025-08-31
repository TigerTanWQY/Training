#include <iostream>
using namespace std;
using LL = long long;

LL a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, ans = 0;
	LL v;
	cin >> n >> q >> v;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	while(q--) {
		int x;
		LL y;
		cin >> x >> y;
		a[x] = y;
	}
	for(int i = 1; i <= n; ++i)
		ans += (a[i] >= v);
	cout << ans;
	return 0;
}