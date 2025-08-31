#include <iostream>
using namespace std;

const int N = 501;
int a[N], b[N], f[N][N], pre[N][N], path[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> m;
	for(int j = 1; j <= m; ++j)
		cin >> b[j];
	a[0] = b[0] = -1;
	for(int i = 1; i <= n; ++i) {
		int w = 0, id = 0;
		for(int j = 1; j <= m; ++j) {
			f[i][j] = f[i-1][j];
			pre[i][j] = j;
			if(a[i] == b[j])
				if(f[i][j] < w + 1) {
					f[i][j] = w + 1;
					pre[i][j] = id;
				}
			if(b[j] < a[i])
				if(f[i-1][j] > w) {
					w = f[i-1][j];
					id = j;
				}
		}
	}
	int ans = 0, idx;
	for(int i = 1; i <= m; ++i)
		if(f[n][i] > ans) {
			ans = f[n][i];
			idx = i;
		}
	cout << ans << '\n';
	if(!ans) {
		cout.flush();
		return 0;
	}
	int cnt = 0;
	for(int i = n, j = idx; i || j; j = pre[i--][j])
		if(pre[i][j] != j)
			path[cnt++] = b[j];
	for(int i = cnt - 1; i >= 0; --i)
		cout << path[i] << ' ';
	cout.flush();
	return 0;
}