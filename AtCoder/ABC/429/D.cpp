#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL s[1000003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	LL n, m, k;
	cin >> n >> m >> k;
	map<LL, LL> mp;
	for(int i = 0; i < n; ++i) {
		LL x; cin >> x;
		++mp[x];
	}
	if(mp.size() == 1) {
		cout << m * n << endl;
		return 0;
	}
	vector<LL> a, ca;
	for(const auto& p: mp) {
		a.push_back(p.first);
		ca.push_back(p.second);
	}
	int la = a.size();
	vector<LL> f = a, cf = ca;
	for(int i = 0; i < la; ++i) {
		f.push_back(a[i] + m);
		cf.push_back(ca[i]);
	}
	int lf = f.size();
	for(int i = 0; i < lf; ++i)
		s[i+1] = s[i] + cf[i];
	LL ans = 0;
	for(int L = 0, R = 0; L < la; ++L) {
		if(R < L)
			R = L;
		for(; R < lf && s[R+1] - s[L] < k; ++R);
		LL len;
		if(L == 0)
			len = a[0] + (m - a[la-1]);
		else
			len = a[L] - a[L-1];
		ans += (s[R+1] - s[L]) * len;
	}
	cout << ans << endl;
	return 0;
}
