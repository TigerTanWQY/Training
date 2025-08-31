#include <iostream>
#include <bitset>
using namespace std;
using LL = long long;

constexpr const int N = 503, K = 503;
bitset<K> f, g;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	LL tota = 0, totb = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		tota += a[i];
		totb += b[i];
	}
	if(tota / k + totb / k == (tota + totb) / k) {
		cout << (tota + totb) / k << endl;
		return 0;
	}
	const int ra = tota % k, rb = totb % k, L = k - rb, R = ra;
	f[0] = true;
	for(int t = 1; t <= n; ++t) {
		g = f;
		for(int i = 0; i < k; ++i)
			if(g[i])
				for(int j = 1; j < k; ++j)
					if(j <= a[t] && k - j <= b[t])
						f[(i + j) % k] = true;
		for(int i = L; i <= R; ++i)
			if(f[i]) {
				cout << (tota + totb) / k << endl;
				return 0;
			}
	}
	cout << (tota + totb) / k - 1 << endl;
	return 0;
}