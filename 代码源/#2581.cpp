#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define _w first
#define _id second

constexpr const int N = 5e5 + 3;
pair<int, int> a[N];
int n, b[N], f[N << 1], g[N << 1];
LL ans;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		a[i] = {x, i};
	}
	sort(a + 1, a + n + 1);
	for(int i = 0; i < 30; ++i) {
		b[a[1]._id] = a[1]._w & 1;
		for(int j = 2; j <= n; ++j) {
			int x = a[j]._w ^ a[j - 1]._w;
			b[a[j]._id] = b[a[j - 1]._id] + 2 * (x > 1);
			if(a[j]._w & 1)
				b[a[j]._id] |= 1;
			else
				b[a[j]._id] &= ~1;
		}
		for(int j = 1; j <= n; ++j)
			++g[b[j]];
		LL c[2]{};
		for(int j = 1; j <= n; ++j) {
			--g[b[j]];
			c[b[j] & 1 ^ 1] -= f[b[j] ^ 1];
			ans += c[b[j] & 1];
			c[b[j] & 1] += g[b[j] ^ 1];
			++f[b[j]];
		}
		for(int j = 1; j <= n; ++j)
		{ --f[b[j]]; a[j]._w >>= 1; }
	}
	cout << ans << endl;
	return 0;
}
