#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
tuple<int, int, int> a[N];
map<int, vector<tuple<int, int, int>>> G[2];
int ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int H, W, n;
	cin >> H >> W >> n;
	for(int i = 1, x, y, len; i <= n; ++i) {
		cin >> x >> y >> len;
		G[0][x].push_back({y, len, i});
		G[1][y].push_back({x, len, i});
		a[i] = {x, y, len};
	}
	for(int i = 1; i <= H; ++i)
		sort(begin(G[0][i]), end(G[0][i]));
	for(int j = 1; j <= W; ++j)
		sort(begin(G[1][j]), end(G[1][j]));
	sort(a + 1, a + n + 1);
	for(int i = n; i; --i) {
		ans[i] = H;
		ans[i] = ans[i + 1] + 1;
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << '\n';
	cout.flush();
	return 0;
}
