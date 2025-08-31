#include <iostream>
#include <vector>
using namespace std;

constexpr const int N = 300'003;
vector<int> G[N];
int c[N];
long long f[N][1 << 6], ans;

void func(const int i, const int u) {
	int j = i ^ (1 << c[u]);
	if(j == 0)
		f[u][i] = 1;
	else {
		for(const auto& v: G[u])
			f[u][i] += f[v][j];
		ans += f[u][i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> c[i];
		--c[i];
	}
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i < 1 << k; ++i)
		for(int j = 1; j <= n; ++j)
			if(i & 1 << c[j])
				func(i, j);
	cout << ans;
	cout.flush();
	return 0;
}