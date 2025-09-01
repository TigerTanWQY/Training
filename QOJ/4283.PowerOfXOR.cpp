#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 1e9 + 7;
struct LB {
	int n, r;
	vector<LL> a;
	LB(int _n)
	: n(_n), r(), a(_n)
	{ }
	void ist(LL x) {
		while(x) {
			const int p = log2(x);
			if(a[p] == 0) {
				for(int i = 0; i < p; ++i)
					if(a[i] && (x >> i & 1))
						x ^= a[i];
				++r;
				a[p] = x;
				for(int i = n - 1; i > p; --i)
					if(a[i] >> p & 1)
						a[i] ^= x;
				return;
			}
			x ^= a[p];
		}
	}
	LB qry() {
		LB res(n);
		for(int i = n - 1; ~i; --i)
			if(!a[i]) {
				LL x = 1LL << i;
				for(int j = n - 1; j > i; --j)
					if(a[j] >> i & 1)
						x ^= 1LL << j;
				res.ist(x);
			}
		return res;
	}
	vector<LL> getall() {
		vector<LL> vec;
		for(int i = 0; i < n; ++i)
			if(a[i])
				vec.push_back(a[i]);
		const int m = vec.size();
		vector<LL> res(1 << m);
		for(int i = 1; i < 1 << m; ++i) {
			int p = log2(i);
			res[i] = res[i ^ (1 << p)] ^ vec[p];
		}
		return res;
	}
};
LL qpow(LL a, LL k) {
	LL res = 1;
	for(; k; a = a * a % P, k >>= 1)
		if(k & 1)
			res = res * a % P;
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<LL> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	const LL mx = *max_element(cbegin(a), cend(a));
	if(mx == 0) {
		cout.put('0') << endl;
		return 0;
	}
	const LL lg = log2(mx) + 1;
	LB lb(lg);
	for(int i = 0; i < n; ++i)
		lb.ist(a[i]);
	vector<LL> p(lg + 1);
	if(lb.r * 2 <= lg) {
		vector<LL> vec = lb.getall();
		for(const auto& x: vec)
			++p[popcount((unsigned long long)x)];
	} else {
		auto rlb = lb.qry();
		vector<LL> c(lg + 1), vec = rlb.getall();
		for(const auto& x: vec)
			++c[popcount((unsigned long long)x)];
		for(int i = 0; i <= lg; ++i) {
			vector<LL> f(lg + 1);
			f[0] = 1;
			c[i] = c[i] * qpow(2, P - 1 - rlb.r) % P;
			for (int j = 1; j <= i; j++)
				for (int k = lg; k > 0; k--)
					f[k] = (f[k] - f[k - 1]) % P;
			for(int j = 1; j <= lg - i; ++j)
				for(int k = lg; k; --k)
					f[k] = (f[k] + f[k - 1]) % P;
			for(int j = 0; j <= lg; ++j)
				p[j] = (p[j] + c[i] * f[j]) % P;
		}
	}
	LL ans = 0;
	for(int i = 0; i <= lg; ++i)
		ans = (ans + p[i] * qpow(i, m)) % P;
	cout << (ans * qpow(2, n - lb.r) % P + P) % P << endl;
	return 0;
}
