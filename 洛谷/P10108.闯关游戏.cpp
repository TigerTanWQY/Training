#include <iostream>
#include <cstring>
using namespace std;
using LL = long long;

constexpr const int M = 103, N = 10'003;
int a[M], b[N], n, m;
LL f[N * 2], ans = -0x3f3f3f3f3f3f3f3f;

LL dfs(const int i, const LL tot) {
	if(f[i] != -0x3f3f3f3f3f3f3f3f)
		return f[i];
	if(i >= n) {
		ans = max(ans, tot);
		return tot;
	}
	for(int j = 0; j < m; ++j)
		f[i] = max(f[i], dfs(i + a[j], tot + b[i]));
	return f[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	memset(f, -0x3f, sizeof(f));
	dfs(0, 0);
	cout << ans;
	cout.flush();
	return 0;
}