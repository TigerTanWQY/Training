#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
int a[N], b[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	long long ans = 0;
	for(int i = 0; i < n; ++i)
		ans += min(a[i], b[i]);
	for(char ch; _q--; cout.put('\n')) {
		int x, w;
		cin >> ch >> x >> w; --x;
		int prev = min(a[x], b[x]);
		if(ch == 'A')
			a[x] = w;
		else
			b[x] = w;
		int nxt = min(a[x], b[x]);
		ans += nxt - prev;
		cout << ans;
	}
	cout.flush(); return 0;
}
