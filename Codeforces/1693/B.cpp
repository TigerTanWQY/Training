#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 200003;
vector<int> G[N];
int fa[N], ans = 0;
LL L[N], R[N], a[N];

void dfs(const int& u) {
	LL tot = 0;
	for(const auto& v: G[u]) {
		dfs(v);
		tot += a[v];
	}
	if(L[u] > tot) {
		++ans;
		a[u] = R[u];
	} else
		a[u] = min(R[u], tot);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int n; T--; ) {
		cin >> n;
		for(int i = 2; i <= n; ++i) {
			cin >> fa[i];
			G[fa[i]].push_back(i);
		}
		for(int i = 1; i <= n; ++i)
			cin >> L[i] >> R[i];
		dfs(1);
		cout << ans << '\n';
		for(int u = 1; u <= n; ++u)
			G[u].clear();
		ans = 0;
	}
	return 0;
}