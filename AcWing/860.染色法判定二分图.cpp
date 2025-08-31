#include <iostream>
#include <vector>
using namespace std;

vector<int> G[100003];
int col[100003];

bool dfs(const int& u, const int& c) {
	col[u] = c;
	for(const auto& v: G[u])
		if(!col[v]) {
			if(dfs(v, 3 - c))
				return true;
		} else if(col[v] == c)
			return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool flag = true;
	for(int u = 1; flag && u <= n; ++u)
		if(!col[u])
			if(dfs(u, 1))
				flag = false;
	if(flag)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}