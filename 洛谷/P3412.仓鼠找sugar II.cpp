#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
using LL = long long;

constexpr const int P = 998'244'353, N = 100'003;
vector<int> G[N];
int dep[N], f[N], maxdep = 0;

LL inv(LL a, LL b = P - 2) {
	LL res = 1;
	for(; b; a = a * a % P, b >>= 1)
		if(b & 1)
			res = res * a % P;
	return res;
}

void bfs(const int rt) {
	memset(dep, 0, sizeof(dep));
	dep[rt] = 1;
	queue<int> q;
	q.push(rt);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		maxdep = max(maxdep, dep[u]);
		for(const auto& v: G[u])
			if(!dep[v]) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bfs(1);
	cout << 16LL * inv(9) % P;
	cout.flush();
	return 0;
}