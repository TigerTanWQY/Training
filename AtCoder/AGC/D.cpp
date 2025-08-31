#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> G[100'003];

bool dfs(const int u, const int fa) {
	int res = 0;
	for(const auto& v: G[u])
		if(v != fa) {
			res += dfs(v, u);
		}
	if(res > 1) {
		cout << "First" << endl;
		exit(0);
	}
	return res ^ 1;
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
	if(dfs(1, 0))
		cout << "First";
	else
		cout << "Second";
	cout << endl;
	return 0;
}