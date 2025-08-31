#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e6 + 3;
bitset<N> vis, b;
LL c[N], cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vis[1] = true;
	for(int i = 2; i <= 50000; ++i)
		if(!vis[i]) {
			c[++cnt] = i;
			for(int j = i << 1; j <= 50000; j += i)
				vis[j] = true;
		}
	LL L, R;
	cin >> L >> R;
	L += (L == 1);
	if(L > R) {
		cout << '0' << endl;
		return 0;
	}
	for(int i = 1; i <= cnt; ++i)
		for(LL j = max(2LL, (L - 1) / c[i] + 1) * c[i]; j <= R; j += c[i])
			if(j - L >= 0)
				b[j - L] = true;
	int ans = 0;
	for(int i = 0; i <= R - L; ++i)
		if(!b[i])
			++ans;
	cout << ans << endl;
	return 0;
}
