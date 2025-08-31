#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 10003;
vector<int> G[N];
int d[N], f[N], n;

bool topSort() {
	queue<int> q;
	int res = 0;
	for(int u = 1; u <= n; ++u)
		if(!d[u]) {
			q.push(u);
			f[u] = 100;
			++res;
		}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(const auto& v: G[u])
			if(!--d[v]) {
				q.push(v);
				f[v] = f[u] + 1;
				++res;
			}
	}
	return res == n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[v].push_back(u);
		++d[u];
	}
	if(topSort()) {
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			ans += f[i];
		cout << ans;
	} else
		cout << "Poor Xed";
	cout << endl;
	return 0;
}