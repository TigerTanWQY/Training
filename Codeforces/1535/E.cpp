#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q;
	cin >> q;
	vector<vector<int>> p(23, vector<int>(q + 1, 0));
	vector<int> a(q + 1), c(q + 1);
	cin >> a[0] >> c[0];
	for(int i = 1, op, u, v, w; i <= q; ++i) {
		cin >> op;
		if(op == 1) {
			cin >> u >> a[i] >> c[i];
			p[0][i] = u;
			for(int j = 1; j <= 20; ++j)
				p[j][i] = p[j - 1][p[j - 1][i]];
		} else {
			cin >> v >> w;
			int ansR = 0; LL ansS = 0;
			while(w > 0 && a[v] > 0) {
				u = v;
				for(int j = 20; j >= 0; --j)
					if(a[p[j][u]] > 0)
						u = p[j][u];
				int mn = min(a[u], w);
				a[u] -= mn; w -= mn; ansR += mn;
				ansS += 1LL * mn * c[u];
			}
			cout << ansR << ' ' << ansS << endl;
		}
	}
	return 0;
}
