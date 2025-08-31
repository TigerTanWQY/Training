#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr const int N = 100'003;
vector<int> G[N];
int fa[N], k, ans = 0;

int dfs(const int u, const int dep) {
	int ret = dep;
	for(const auto& v: G[u])
		ret = max(ret, dfs(v, dep + 1));
	if(fa[u] != 1 && ret - dep == k - 1) {
		++ans;
		return 0;
	} else
		return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> fa[i];
	if(fa[1] != 1)
		ans = fa[1] = 1;
	for(int i = 2; i <= n; ++i)
		G[fa[i]].push_back(i);
	dfs(1, 0);
	cout << ans;
	cout.flush();
	return 0;
}