#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 3e5 + 3;
vector<int> a[N], idx[N];
int cnt[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0, k; i < m; ++i) {
		cin >> k;
		cnt[i] = k;
		a[i].resize(k);
		for(auto &x: a[i]) {
			cin >> x; --x;
			idx[x].push_back(i);
		}
	}
	int ans = 0;
	for(int i = 0, x; i < n; ++i) {
		cin >> x; --x;
		for(const auto& id: idx[x]) {
			--cnt[id];
			if(cnt[id] == 0)
				++ans;
		}
		cout << ans << '\n';
	}
	cout.flush(); return 0;
}
