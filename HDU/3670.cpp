#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 1 << 16;
int c[17][(1 << 17) + 3];

auto lb = [](int x) { return x & -x; };

void mdf(int u, int x, int k) {
	for(; x <= P; x += lb(x))
		c[u][x] += k;
}

LL qry(int u, int x) {
	LL res = 0;
	for(; x; x -= lb(x))
		res += c[u][x];
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int _ = 1, n; cin >> n && ~n; cout.put('\n'), ++_) {
		memset(c, 0, sizeof(c));
		for(int i = 1, x; i <= n; ++i) {
			cin >> x;
			for(int j = 0; j < 17; ++j)
				mdf(j, x % (1 << (j + 1)) + 1, 1);
		}
		LL ans = 0; int tot = 0;
		for(char op; cin >> op && op != 'E'; ) {
			int x;
			cin >> x;
			if(op == 'C')
			{ tot += x; tot %= P; }
			else {
				int MOD = 1 << (x + 1), tmp = tot % MOD;
				int L = 1 << x, R = 1 << (x + 1);
				L = (L - tmp + MOD) % MOD; R = (R - tmp + MOD) % MOD;
				if(L <= R)
					ans += qry(x, R) - qry(x, L);
				else
					ans += qry(x, P) - qry(x, L) + qry(x, R);
			}
		}
		cout << "Case " << _ << ": " << ans;
	}
	cout.flush(); return 0;
}
