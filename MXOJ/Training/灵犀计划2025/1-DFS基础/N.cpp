#include <bits/stdc++.h>
using namespace std;

unordered_set<int> st;
int a[13][13], n, m, ans = 0;

void dfs(int x, int y) {
	if(st.find(a[x][y]) != cend(st))
		return;
	else if(x == n && y == m) {
		++ans;
		return;
	}
	st.insert(a[x][y]);
	dfs(x + 1, y);
	dfs(x, y + 1);
	st.erase(a[x][y]);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	dfs(1, 1);
	cout << ans << endl;
	return 0;
}
