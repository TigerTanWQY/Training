#include <iostream>
using namespace std;

constexpr const int N = (1 << 18) + 3;
int a[N], fa[N];

int fnd(const int x) {
	if(fa[x] != x)
		fa[x] = fnd(fa[x]);
	return fa[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < 1 << m; ++i)
		fa[i] = i;
	long long ans = 0;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		if(a[x])
			ans += x;
		a[x] = x;
	}
	for(int s = (1 << m) - 1; s; --s) {
		for(int i = 0; i < m && !a[s]; ++i)
			a[s] = a[s | 1 << i];
		for(int i = 0; i < m; ++i)
			if(a[s | 1 << i] && fnd(a[s]) != fnd(a[s | 1 << i])) {
				fa[fnd(a[s])] = fa[fnd(a[s | 1 << i])];
				ans += s;
			}
	}
	cout << ans << endl;
	return 0;
}