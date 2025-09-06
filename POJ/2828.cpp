#include <iostream>
using namespace std;

const int N = 1 << 18;
int c[N], ans[N];

int fnd(int x) {
	int u = N >> 1, res = 0;
	for(int lb = u; lb; ) {
		lb >>= 1;
		if(c[u] >= x)
			u -= lb;
		else {
			res = max(res, u);
			x -= c[u];
			u += lb;
		}
	}
	return res + 1;
}

void add(int u, int w) {
	for(; u < N; u += (u & -u))
		c[u] += w;
}

void dfs(int cnt) {
	int x, w;
	cin >> x >> w;
	if(cnt > 0)
		dfs(cnt - 1);
	int u = fnd(x + 1);
	ans[u] = w;
	add(u, -1);
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	for(int n; cin >> n; cout.put('\n')) {
		for(int i = 1; i < N; ++i)
			c[i] = i & -i;
		dfs(n - 1);
		for(int i = 1; i <= n; ++i)
			cout << ans[i] << ' ';
	}
	cout.flush(); return 0;
}
