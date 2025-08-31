#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 203;
int v[N], w[N], n, V;

namespace sub1 {
	LL ans = 0;

	void dfs(int x, LL cnt, LL totw) {
		if(cnt > V)
			return;
		else if(x == n) {
			ans = max(ans, totw);
			return;
		}
		dfs(x + 1, cnt + v[x], totw + w[x]);
		dfs(x + 1, cnt, totw);
	}

	void Main() {
		dfs(0, 0, 0);
		cout << ans;
	}
}

namespace sub2 {
	LL f[200003];

	void Main() {
		V = min(V, (int)2e5);
		for(int i = 0; i < n; ++i)
			for(int j = V; j >= v[i]; --j)
				f[j] = max(f[j], f[j - v[i]] + w[i]);
		cout << f[V];
	}
}

namespace sub3 {
	LL f[200003];

	void Main() {
		memset(f, 0x3f, sizeof(f));
		f[0] = 0;
		int ans = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 2e5; j >= w[i]; --j)
				f[j] = min(f[j], f[j - w[i]] + v[i]);
		for(int j = 0; j <= 2e5; ++j)
			if(f[j] <= V)
				ans = max(ans, j);
		cout << ans;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> V;
	LL totv = 0, totw = 0;
	for(int i = 0; i < n; ++i) {
		cin >> w[i] >> v[i];
		totw += w[i];
		totv += v[i];
	}
	if(totv <= V)
		cout << totw;
	else if(n <= 30)
		sub1::Main();
	else if(*max_element(v, v + n) <= 1000)
		sub2::Main();
	else if(*max_element(w, w + n) <= 1000)
		sub3::Main();
	cout << endl;
	return 0;
}
