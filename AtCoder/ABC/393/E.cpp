#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1.2e6;
vector<int> G[N];
int a[N], freq[N], cnt[N], ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		++freq[a[i]];
	}
	int m = *max_element(a, a + n);
	for(int d = 1; d <= m; ++d)
		for(int x = d; x <= m; x += d)
			cnt[d] += freq[x];
	for(int i = 0; i < n; ++i)
		G[a[i]].push_back(i);
	for(int d = m; d; --d) {
		if(cnt[d] < k)
			continue;
		for(int x = d; x <= m; x += d)
			for(const auto& i: G[x])
				if(ans[i] == 0)
					ans[i] = d;
	}
	for(int i = 0; i < n; ++i)
		cout << ans[i] << '\n';
	cout.flush();
	return 0;
}
