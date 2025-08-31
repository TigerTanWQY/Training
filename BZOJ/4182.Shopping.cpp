#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 503, M = 4'003;
class Dsu {
private:
	size_t n;
	vector<size_t> fa;
public:
	void init(void) noexcept {
		for(size_t i = 0; i <= n; ++i)
			fa[i] = i;
	}

	Dsu(const size_t _n = 0) noexcept
	: n(_n), fa(vector<size_t>(_n + 3))
	{ init(); }

	void resize(const size_t _n) noexcept {
		n = _n;
		fa.resize(_n + 3);
		init();
	}

	size_t fnd(const size_t x) {
		assert(x <= n);
		if(fa[x] != x)
			fa[x] = fnd(fa[x]);
		return fa[x];
	}

	void mrge(size_t x, size_t y) {
		assert(x <= n);
		assert(y <= n);
		x = fnd(x); y = fnd(y);
		if(x == y)
			return;
		fa[y] = x;
	}

	bool same(const size_t x, const size_t y) {
		assert(x <= n);
		assert(y <= n);
		return fnd(x) == fnd(y);
	}
} dsu;
vector<int> G[N];
int w[N], v[N], d[N], f[M];

void dfs(const int x, const int fa) {
	for(const auto& y: G[x])
		if(y != fa)
			dfs(y, x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n, V; _T--; cout.put('\n')) {
		cin >> n >> V;
		for(int i = 1; i <= n; ++i)
			cin >> w[i];
		for(int i = 1; i <= n; ++i)
			cin >> v[i];
		for(int i = 1; i <= n; ++i)
			cin >> d[i];
		for(int _ = 1, x, y; _ < n; ++_) {
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dsu.resize(n);
		dfs(1, 0);
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; ++i)
			for(int j = V; j >= v[i]; --j)
				for(int k = 0; k < d[i]; ++k)
					f[j] = max(f[j], f[j - v[i]] + w[i]);
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			ans += w[i];
		cout << ans;
		for(int i = 1; i <= n; ++i)
			G[i].clear();
	}
	cout.flush();
	return 0;
}