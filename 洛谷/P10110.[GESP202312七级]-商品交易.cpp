#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
vector<int> G[N];
int w[N];
LL dis[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, S, T;
	cin >> n >> m >> S >> T;
	++S; ++T;
	for(int i = 1; i <= n; ++i)
		cin >> w[i];
	for(int u, v; m--; ) {
		cin >> u >> v;
		++u; ++v;
		G[u].push_back(v);
	}
	memset(dis, 0x3f, sizeof(dis));
	dis[S] = 0;
	queue<int> q;
	q.push(S);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
	if(dis[T] == 0x3f3f3f3f3f3f3f3f)
		cout << "No solution";
	else
		cout << dis[T] + w[T] - w[S];
	cout << endl;
	return 0;
}
