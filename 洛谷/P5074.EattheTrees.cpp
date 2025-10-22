#include <iostream>
using namespace std;

constexpr const int N = 12;
int a[N][N];
long long f[1<<N+1], g[1<<N+1];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, m; _T--; cout.put('\n')) {
		cin >> n >> m;
		int s = 1<<m+1;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				cin >> a[i][j];
		for(int i = 0; i < s; ++i)
			g[i] = 0;
		g[0] = 1;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) {
				for(int t = 0; t < s; ++t)
					f[t] = j? g[t]: t&1? 0: g[t>>1];
				if(!a[i][j])
					for(int t = 0; t < s; ++t)
						g[t] = t>>j&3? 0: f[t];
				else
					for(int t = 0; t < s; ++t)
						g[t] = f[t^3<<j] + ((t>>j&1) ^ (t>>j+1&1)? f[t]: 0);
			}
		cout << g[0];
	}
	cout.flush(); return 0;
}
