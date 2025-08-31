#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3003;
int a[N], b[N], f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	for(int i = 1; i <= n; ++i) {
		int maxn = 1;
		for(int j = 1; j <= n; ++j) {
			f[i][j] = f[i - 1][j];
			if(a[i] == b[j])
				f[i][j] = max(f[i][j], maxn);
			else if(a[i] > b[j])
				maxn = max(maxn, f[i - 1][j] + 1);
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; ++i)
		ans = max(ans, f[n][i]);
	cout << ans;
	cout.flush();
	return 0;
}