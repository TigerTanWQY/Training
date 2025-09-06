#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 8;
int a[N][N], b[N][N], p[N], q[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> b[i][j];
	iota(p + 1, p + n + 1, 1);
	iota(q + 1, q + m + 1, 1);
	int ans = 1e9;
	do
		do {
			bool flg = true;
			for(int i = 1; flg && i <= n; ++i)
				for(int j = 1; flg && j <= m; ++j)
					if(a[p[i]][q[j]] != b[i][j])
						flg = false;
			if(!flg)
				continue;
			int cnt = 0;
			for(int i = 1; i < n; ++i)
				for(int j = i + 1; j <= n; ++j)
					if(p[i] > p[j])
						++cnt;
			for(int i = 1; i < m; ++i)
				for(int j = i + 1; j <= m; ++j)
					if(q[i] > q[j])
						++cnt;
			ans = min(ans, cnt);
		} while(next_permutation(q + 1, q + m + 1));
	while(next_permutation(p + 1, p + n + 1));
	cout << (ans == 1e9? -1: ans) << endl;
	return 0;
}
