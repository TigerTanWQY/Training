#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
int a[N][N], b[N][2 * N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
		sort(a[i] + 1, a[i] + m + 1);
	}
	for(int i = 1; i <= n; ++i) {
		cin >> b[i][0];
		for(int j = 1; j <= b[i][0]; ++j)
			cin >> b[i][j];
		sort(b[i] + 1, b[i] + b[i][0] + 1);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int j = 1;
		for(int k = 1; j <= m && k <= b[i][0]; ++k)
			if(a[i][j] == b[i][k])
				++j;
		if(j > m)
			ans += 2;
	}
	cout << ans;
	return 0;
}