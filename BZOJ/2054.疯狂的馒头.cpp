#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3;
int fa[N], c[N];

int fnd(int x)
{ return fa[x] == x? x: fa[x] = fnd(fa[x]); }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	iota(fa + 1, fa + n + 2, 1);
	for(int i = m; i; --i) {
		int L = (i * p + q) % n + 1, R = (i * q + p) % n + 1;
		if(L > R) swap(L, R);
		for(int j = fnd(L); j <= R; j = fnd(j)) {
			fa[j] = j + 1;
			c[j] = i;
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << c[i] << '\n';
	cout.flush(); return 0;
}
/*
sudo tee '
Acquire::http::Proxy "http://127.0.0.1:9910"
Acquire::https::Proxy "http://127.0.0.1:9910"
EOF
' /etc/apt/apt.conf
*/
