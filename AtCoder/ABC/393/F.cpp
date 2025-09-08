#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<pair<int, int>> qs[N];
int a[N], ans[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < q; i++) {
		int r, x;
		cin >> r >> x;
		qs[--r].push_back({i, x});
	}
	memset(f, 0x3f, sizeof(f));
	for(int i = 0; i < n; ++i) {
		auto it = lower_bound(f, f + n, a[i]);
		*it = a[i];
		for(const auto& [id, x]: qs[i])
			ans[id] = upper_bound(f, f + n, x) - f;
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';
	cout.flush();
	return 0;
}
