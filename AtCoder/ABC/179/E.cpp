#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using LL = long long;

constexpr const int N = 100'003;
vector<int> a{-1};
bitset<N> vis;
LL f[N], g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL n;
	int x, m;
	cin >> n >> x >> m;
	int d = 0, k = 0, c = 0;
	while(true) {
		a.push_back(x % m);
		if(vis[x % m]) {
			d = a.size() - 2;
			k = x % m;
			break;
		}
		vis[x % m] = true;
		x = (LL)x * x % m;
	}
	for(int i = 1; !c && i <= d; ++i)
		if(a[i] == k)
			c = i;
	LL tot1 = 0, tot2 = 0, ans = 0;
	for(int i = 1; i < c; ++i) {
		tot1 += a[i];
		f[i] = f[i - 1] + a[i];
	}
	for(int i = c; i <= d; ++i) {
		tot2 += a[i];
		g[i + 1 - c] = g[i - c] + a[i];
	}
	if(n >= c)
		ans += tot1 + (n - c + 1) / (d - c + 1) * tot2 + g[(n - c + 1) % (d - c + 1)];
	else
		ans += f[n];
	cout << ans << endl;
	return 0;
}