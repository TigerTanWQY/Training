#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 1e9 + 7, N = 53;
char s[N];
int nxt[N];
long long f[N][N];

int main () {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n >> s;
	int m = strlen(s);
	for(int i = m; i; --i)
		swap(s[i], s[i-1]);
	for(int i = 2, j = 0; i <= m; ++i) {
		while(j && s[i] != s[j+1])
			j = nxt[j];
		if(s[i] == s[j+1])
			++j;
		nxt[i] = j;
	}
	f[0][0] = 1;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			for(char k = 'a'; k <= 'z'; ++k) {
				int u = j;
				while(u && s[u+1] != k)
					u = nxt[u];
				if(s[u+1] == k)
					++u;
				if(u < m)
					f[i+1][u] = (f[i+1][u] + f[i][j]) % P;
			}
	long long ans = 0;
	for(int i = 0; i < m; ++i)
		ans = (ans + f[n][i]) % P;
	cout << ans << endl;
	return 0;
}
