#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
multiset<LL> s;
int n, b[N], t[N];
LL a[N], p[N], mx;

void exgcd(LL A, LL B, LL &x, LL &y, LL &g) {
	if(!B)
	{ x = 1; y = 0; g = A; }
	else
	{ exgcd(B, A % B, y, x, g); y -= (A / B) * x; }
}

LL ExCRT() {
	LL ans = 0, l = 1, x, y, g, A, B, C;
	for(int i = 1; i <= n; ++i) {
		A = (__int128)b[i] * l % p[i];
		B = p[i];
		C = (a[i] - b[i] * ans % p[i] + p[i]) % p[i];
		exgcd(A, B, x, y, g); x = (x % B + B) % B;
		if(C % g)
			return -1;
		ans += (__int128)(C / g) * x % (B / g) * l % (l *= B / g);
		ans %= l;
	}
	if(ans < mx)
		ans += ((mx - ans - 1) / l + 1) * l;
	return ans;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int m; _T--; cout.put('\n')) {
		s.clear(); mx = 0;
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		for(int i = 1; i <= n; ++i)
			cin >> p[i];
		for(int i = 1; i <= n; ++i)
			cin >> t[i];
		for(int i = 1, x; i <= m; ++i) {
			cin >> x;
			s.insert(x);
		}
		for(int i = 1; i <= n; ++i) {
			auto u = s.upper_bound(a[i]);
			if(u != s.begin())
				--u;
			b[i] = *u; s.erase(u); s.insert(t[i]);
			mx = max(mx, (a[i] - 1) / b[i] + 1);
		}
		cout << ExCRT();
	}
	cout.flush(); return 0;
}
