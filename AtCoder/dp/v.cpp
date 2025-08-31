#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int N = 100'003;
vector<int> G[N], nxt[2][N];
bitset<N> vis;
int s[N], f[N], P;

void up(const int u) {
	vis[u] = true;
	s[u] = 1;
	for(const auto& v: G[u])
		if(!vis[v]) {
			up(v);
			s[u] = 1LL * s[u] * (s[v] + 1) % P;
		}
}

void down(const int u) {
	vis[u] = true;
	f[u] = s[u];
	for(const auto& v: G[u]) {
		nxt[0][u].push_back(s[v] + 1);
		nxt[1][u].push_back(s[v] + 1);
	}
	for(int i = 1; i < nxt[0][u].size(); ++i)
		nxt[0][u][i] = 1LL * nxt[0][u][i - 1] * nxt[0][u][i] % P;
	for(int i = nxt[1][u].size() - 2; i >= 0; --i)
		nxt[1][u][i] = 1LL * nxt[1][u][i + 1] * nxt[1][u][i] % P;
	int j = 0;
	for(const auto& v: G[u]) {
		if(vis[v]) {
			++j;
			continue;
		}
		if(j)
			s[u] = nxt[0][u][j - 1];
		else
			s[u] = 1;
		if(j < nxt[1][u].size() - 1)
			s[u] = 1LL * s[u] * nxt[1][u][j + 1] % P;
		s[v] = 1LL * s[v] * (s[u] + 1) % P;
		down(v);
		++j;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> P;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	up(1);
	vis.reset();
	down(1);
	for(int i = 1; i <= n; ++i)
		cout << f[i] << '\n';
	cout.flush();
	return 0;
}