#include <bits/stdc++.h>
using namespace std;

constexpr const int M = 1 << 10;
vector<int> op;
int f[2][M][M], g[103], cnt[M], n, m;

bool chk(int x) {
	for(int i = 0; i < m; ++i)
		if((1 & x >> i) && ((1 & x >> i + 1) || (1 & x >> i + 2)))
			return false;
	return true;
}

int calc(int x) {
	int res = 0;
	for(int i = 0; i < m; ++i)
		res += 1 & x >> i;
	return res;
}

int main () {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < m; ++j) {
			char ch;
			cin >> ch;
			if(ch == 'H')
				g[i] += 1 << j;
		}
	for(int i = 0; i < 1 << m; ++i)
		if(chk(i)) {
			op.push_back(i);
			cnt[i] = calc(i);
		}
	for(int i = 1; i <= n + 2; ++i)
		for(int j = 0; j < (int)op.size(); ++j)
			for(int k = 0; k < (int)op.size(); ++k)
				for(int l = 0; l < (int)op.size(); ++l) {
					int a = op[j], b = op[k], c = op[l];
					if((a & b) | (b & c) | (a & c))
						continue;
					if((g[i - 1] & a) | (g[i] & b))
						continue;
					f[i & 1][j][k] = max(f[i & 1][j][k], f[1 & i - 1][l][j] + cnt[b]);
				}
	cout << f[1 & n + 2][0][0] << endl;
	return 0;
}
