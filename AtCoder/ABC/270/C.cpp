#include <iostream>
#include <vector>
using namespace std;

vector<int> G[200003], ans;
bool vis[200003];
int y;

void dfs(const int &u) {
	if(u == y) {
		for(const auto &p: ans)
			cout << p << ' ';
		return;
	}
	for(const auto &v: G[u])
		if(!vis[v]) {
			vis[v] = true;
			ans.push_back(v);
			dfs(v);
			ans.pop_back();
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	cin >> n >> x >> y;
	for(int u, v; --n; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vis[x] = true;
	ans.push_back(x);
	dfs(x);
	ans.pop_back();
	return 0;
}
