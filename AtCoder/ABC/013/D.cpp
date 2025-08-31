#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 5;
int a[N], p[N], f[30][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, d;
	cin >> n >> m >> d;
	for(int i = 1; i <= n; ++i)
		p[i] = i;
	for(int x; m--; ) {
		cin >> x;
		swap(p[x], p[x + 1]);
	}
	for(int i = 1; i <= n; ++i)
		f[0][p[i]] = i;
	for(int j = 1; j <= 29; ++j)
		for(int i = 1; i <= n; ++i)
			f[j][i] = f[j - 1][f[j - 1][i]];
	for(int i = 1; i <= n; cout.put('\n'), ++i) {
		int x = i;
		for(int j = 29; j >= 0; --j)
			if(d & 1 << j)
				x = f[j][x];
		cout << x;
	}
	cout.flush();
	return 0;
}
