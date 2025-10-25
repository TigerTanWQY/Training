#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 1e9 + 7, N = 1003;
int f[N], cnt[N];

int main () {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, V;
	cin >> n >> V;
	fill(cnt, cnt + V + 1, 1);
	for(int i = 1, v, w; i <= n; ++i) {
		cin >> v >> w;
		for(int j = V; j >= v; --j)
			if(f[j - v] + w > f[j]) {
				f[j] = f[j - v] + w;
				cnt[j] = cnt[j - v];
			} else if(f[j - v] + w == f[j])
				cnt[j] = (cnt[j] + cnt[j - v]) % P;
	}
	cout << cnt[V] << endl;
	return 0;
}
