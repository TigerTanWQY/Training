#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 303;
int st[12][12][N][N];

int qry(int x1, int y1, int x2, int y2) {
	if(x1 == x2 && y2 == y1)
		return st[0][0][x1][y1];
	int cntx = 0, cnty = 0;
	for(; x1 + (1 << cntx + 1) - 1 <= x2; ++cntx);
	for(; y1 + (1 << cnty + 1) - 1 <= y2; ++cnty);
	return max({st[cntx][cnty][x1][y1], st[cntx][cnty][x2 - (1 << cntx) + 1][y1], st[cntx][cnty][x1][y2 - (1 << cnty) + 1], st[cntx][cnty][x2 - (1 << cntx) + 1][y2 - (1 << cnty) + 1]});
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int n, m, _q; cin >> n >> m; ) {
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				cin >> st[0][0][i][j];
		for(int i = 0; (1 << i) <= n; ++i)
			for(int j = 0; (1 << j) <= m; ++j)
				if(i || j)
					for(int x = 1; x + (1 << i) - 1 <= n; ++x)
						for(int y = 1; y + (1 << j) - 1 <= m; ++y)
							st[i][j][x][y] = (j? max(st[i][j - 1][x][y], st[i][j - 1][x][y + (1 << j - 1)]): max(st[i - 1][j][x][y], st[i - 1][j][x + (1 << i - 1)][y]));
		cin >> _q;
		for(int x1, y1, x2, y2; _q--; cout.put('\n')) {
			cin >> x1 >> y1 >> x2 >> y2;
			int ans = qry(x1, y1, x2, y2);
			cout << ans << ' ' << (st[0][0][x1][y1] == ans || st[0][0][x1][y2] == ans || st[0][0][x2][y1] == ans || st[0][0][x2][y2] == ans? "yes": "no");
		}
	}
	cout.flush(); return 0;
}
