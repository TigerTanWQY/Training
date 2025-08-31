#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
int a[N], idx[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	for(int i = 0, j = 2; j <= n; j += 2) {
		if(a[j] != a[j - 1]) {
			i = j;
			continue;
		}
		ans = max(ans, j - max(i, idx[a[j]]));
		i = max(i, idx[a[j]]);
		idx[a[j]] = j;
	}
	memset(idx, 0, sizeof(idx));
	for(int i = 1, j = 3; j <= n; j += 2) {
		if(a[j] != a[j - 1]) {
			i = j;
			continue;
		}
		ans = max(ans, j - max(i, idx[a[j]]));
		i = max(i, idx[a[j]]);
		idx[a[j]] = j;
	}
	cout << ans << endl;
	return 0;
}
