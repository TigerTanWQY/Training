#include <iostream>
#include <vector>
using namespace std;

const int N = 100003;
vector<int> G[N];

int dfs(const int& u) {
	if(G[u].empty())
		return 1;
	int d = 0;
	for(const auto& v: G[u])
		d = max(d, dfs(v));
	return G[u].size() + d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	cout << dfs(1);
	return 0;
}