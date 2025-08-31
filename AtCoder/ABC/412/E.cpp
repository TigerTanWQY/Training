#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<int> fac(int n) {
	vector<bool> b(n + 1, true);
	vector<int> res;
	if(n < 2)
		return res;
	b[0] = b[1] = false;
	for(int i = 2; i * i <= n; ++i)
		if(b[i])
			for(int j = i * i; j <= n; j += i)
				b[j] = false;
	for(int i = 2; i <= n; ++i)
		if(b[i])
			res.push_back(i);
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	LL L, R;
	cin >> L >> R;
	vector<bool> vis(R - L);
	int ans = 1;
	for(const auto& p: fac(sqrt(R) + 100))
		for(LL x = (L / p + 1) * p; x <= R; x += p) {
			if(vis[x - (L + 1)])
				continue;
			vis[x - (L + 1)] = true;
			LL y = x;
			while(y % p == 0)
				y /= p;
			if(y == 1)
				++ans;
		}
	for(const auto& v: vis)
		ans += !v;
	cout << ans << endl;
	return 0;
}
