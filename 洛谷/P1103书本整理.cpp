#include <iostream>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
#define h first
#define w second

const int N = 103;
pair<int, int> a[N];
int f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, ans = 0x3f3f3f3f;
	cin >> n >> k;
	int m = n - k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].h >> a[i].w;
	sort(a + 1, a + n + 1);
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; ++i)
		f[i][1] = 0;
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j < i; ++j)
			for(k = 2; k <= min(i, m); ++k)
				f[i][k] = min(f[i][k], f[j][k - 1] + abs(a[i].w - a[j].w));
	for(int i = m; i <= n; ++i)
		ans = min(ans, f[i][m]);
	cout << ans;
	return 0;
}