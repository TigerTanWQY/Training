#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<LL> a, b;
LL cnt = 0;

auto sz = [](const vector<LL>& p) -> LL
{ return size(p); };

LL f1(LL x) {
	LL tot = sz(a) * (sz(a) - 1) / 2 +
		sz(b) * (sz(b) - 1) / 2 +
		cnt * sz(a) + cnt * sz(b) +
		cnt * (cnt - 1) / 2;
	reverse(begin(a), end(a));
	reverse(begin(b), end(b));
	for(int i = 0, j = sz(a) - 1; i < sz(b); ++i) {
		for(; ~j && b[i] * a[j] >= x; --j);
		tot += sz(a) - j - 1;
	}
	reverse(begin(a), end(a));
	reverse(begin(b), end(b));
	return tot;
}

LL f2(LL x) {
	LL tot = 0;
	for(int i = 0, j = sz(a) - 1; i < sz(a); ++i) {
		for(; ~j && a[i] * a[j] >= x; --j);
		tot += sz(a) - j - 1;
	}
	for(int i = 0, j = sz(b) - 1; i < sz(b); ++i) {
		for(; ~j && b[i] * b[j] >= x; --j);
		tot += sz(b) - j - 1;
	}
	for(const auto& p: a)
		if(p * p >= x)
			--tot;
	for(const auto& p: b)
		if(p * p >= x)
			--tot;
	return tot / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL n, k;
	cin >> n >> k;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		if(x > 0)
			a.push_back(x);
		else if(x < 0)
			b.push_back(x);
		else
			++cnt;
	}
	sort(begin(a), end(a));
	sort(begin(b), end(b), greater<>());
	k = n * (n - 1) / 2 - k + 1;
	LL L = -1e18, R = 1e18;
	auto chk = [&n, &k](LL x) {
		if(x < 0)
			return f1(x) >= k;
		else if(x > 0)
			return f2(x) >= k;
		else
			return n * (n - 1) / 2 - sz(a) * sz(b) >= k;
	};
	while(L <= R) {
		LL M = (L + R) >> 1;
		if(chk(M))
			L = M + 1;
		else
			R = M - 1;
	}
	cout << L - 1 << endl;
	return 0;
}
