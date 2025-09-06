#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	freopen("r.in", "r", stdin);
	freopen("r.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(LL a, b; _T--; cout.put('\n')) {
		cin >> a >> b;
		LL ans = 0;
		while(b != 0) {
			ans += a / b;
			a %= b;
			swap(a, b);
		}
		cout << ans;
	}
	cout.flush(); return 0;
}
