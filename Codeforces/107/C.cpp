#include <iostream>
#include <array>
using namespace std;
using LL = long long;

constexpr const LL INF = 0x3f3f3f3f3f3f3f3f;
constexpr const int N = 17, M = 1 << N - 1;
array<LL, N> a, fa, to;
array<LL, M> f, cnt;
int n;

void solve() {
	f.fill({});
	f[0] = 1;
	for(int i = 0; i < (1 << n); ++i)
		for(int j = 1; j <= n; ++j) {
			if((i & (1 << j - 1)) != 0 || (a[j] & i) != a[j] || (to[j] != 0 && cnt[i] != to[j]) || (fa[cnt[i]] != 0 && fa[cnt[i]] != j))
				continue;
			if(f[i | (1 << j - 1)] < INF)
				f[i | (1 << j - 1)] += f[i];
		}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	LL year;
	cin >> n >> year >> m;
	year -= 2000;
	for(int x, y; m--; ) {
		cin >> x >> y;
		a[y] |= (1 << x - 1);
	}
	cnt[0] = 1;
	for(int i = 1; i < (1 << n); ++i)
		cnt[i] = cnt[i >> 1] + (i & 1);
	for(int i = 1, j; i <= n; ++i) {
		for(j = 1; j <= n; ++j) {
			if(fa[j])
				continue;
			fa[j] = i;
			to[i] = j;
			solve();
			if(f[(1 << n) - 1] >= year)
				break;
			else {
				year -= f[(1 << n) - 1];
				fa[j] = 0;
			}
		}
		if(j > n) {
			cout << "The times have changed";
			cout.flush();
			return 0;
		}
		cout << j << ' ';
	}
	cout.flush();
	return 0;
}