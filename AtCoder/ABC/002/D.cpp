#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 15;
bool G[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int x, y; m--; ) {
		cin >> x >> y;
		--x; --y;
		G[x][y] = G[y][x] = true;
	}
	int ans = 0;
	for(unsigned s = 0; s < 1U << n; ++s) {
		bool flag = true;
		for(int i = 0; flag && i + 1 < n; ++i)
			if(s & 1 << i)
				for(int j = i + 1; flag && j < n; ++j)
					if(s & 1 << j)
						if(!G[i][j])
							flag = false;
		if(flag)
			ans = max(ans, popcount(s));
	}
	cout << ans << endl;
	return 0;
}
