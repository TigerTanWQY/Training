#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e5 + 5;
vector<int> G[N], T[N], c;
unordered_map<char, int> mp;
char s[N];
int f[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	mp['R'] = 0; mp['G'] = 1; mp['B'] = 2;
	int n, k;
	cin >> n >> k; ++k;
	c.resize(k);
	for(int i = 0; i < k; ++i) {
		f[i] = 1e9;
		c[i] = 0;
	}
	for(int i = 1; i <= n; ++i) {
		cin >> s;
		s[k - 1] = 'G';
		T[i].resize(k);
		for(int j = 0; j < k; ++j) {
			T[i][j] = mp[s[j]];
			c[j] = (c[j] + T[i][j]) % 3;
		}
		int id = i;
		for(int j = 0; j < k; ++j)
			if(T[i][j]) {
				int x = T[i][j];
				for(int l = 0; l < k; ++l)
					T[i][l] = T[i][l] * x % 3;
				if(f[j] > id) {
					swap(f[j], id);
					swap(G[j], T[i]);
				}
				if(id == 1e9)
					break;
				for(int l = 0; l < k; ++l)
					T[i][l] = (T[i][l] + 3 - G[j][l]) % 3;
			}
	}
	int ans = 0;
	for(int i = 0; i < k; ++i)
		if(c[i]) {
			ans = max(ans, f[i]);
			int x = c[i];
			for(int j = 0; j < k; ++j)
				c[j] = (c[j] * x + 3 - G[i][j]) % 3;
		}
	cout << ans << endl;
	return 0;
}
