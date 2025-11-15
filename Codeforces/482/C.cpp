#include <bits/stdc++.h>
using namespace std;

constexpr const int M = (1<<20)+3;
char a[53][53];
int num[M];
long long g[M];
double f[M];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		for(int j = strlen(a[i]); j; --j)
			swap(a[i][j], a[i][j-1]);
	}
	int m = strlen(a[1]+1);
	for(int i = 1; i < n; ++i)
		for(int j = i+1; j <= n; ++j) {
			int nw = 0;
			for(int k = 1; k <= m; ++k) {
				if(a[i][k] == a[j][k])
					nw |= 1 << m-k;
				g[nw] |= (1LL << i-1) | (1LL << j-1);
			}
		}
	for(int i = (1<<m)-1; ~i; --i)
		for(int j = 0; j < m; ++j)
			if(!(i>>j & 1))
				g[i] |= g[i ^ 1<<j];
	for(int i = 0; i < 1<<m; ++i)
		for(int j = 0; j < n; ++j)
			if(g[i]>>j & 1)
				++num[i];
	for(int i = (1<<m)-1; ~i; --i) {
		if(!num[i])
			continue;
		int cnt = 0;
		for(int j = 0; j < m; ++j)
			if(!(i>>j & 1)) {
				++cnt;
				f[i] += f[i | 1<<j];
			}
		f[i] /= cnt;
		f[i] += num[i];
	}
	f[0] /= n;
	cout << fixed << setprecision(12) << f[0] << endl;
	return 0;
}
