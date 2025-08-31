#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 1e9 + 7;

vector<int> xor_bs(int n, const vector<int>& a) {
	vector<int> b;
	for(int i = 0; i < n; ++i) {
		int x = a[i];
		for(const auto& j: b)
			x = min(x, x ^ j);
		if(x != 0) {
			for(int& j: b)
				j = min(j, j ^ x);
			b.push_back(x);
			sort(b.begin(), b.end(), greater<>());
		}
	}
	return b;
}

int work(int n, int k, const vector<int>& a, const vector<int>& b) {
	if(find(b.cbegin(), b.cend(), 0) != b.cend())
		return 0;
	vector<int> pow2(n + 1);
	pow2[0] = 1;
	for(int i = 0; i < n; ++i)
		pow2[i + 1] = pow2[i] * 2 % P;
	vector<int> sa = xor_bs(n, a);
	const int m = sa.size();
	int ans = 0;
	for(unsigned i = 0; i < 1U << k; ++i) {
		int z = 0;
		for(int j = 0; j < k; ++j)
			if(i >> j & 1)
				z |= b[j];
		vector<int> ta(m);
		for(int j = 0; j < m; ++j)
			ta[j] = sa[j] & z;
		ta = xor_bs(m, ta);
		int y = z;
		for(const auto& j: ta)
			if(y > (y ^ j))
				y ^= j;
		if(y == 0) {
			int sub = pow2[n - ta.size()];
			if(!(popcount(i) & 1))
				ans = (ans + sub) % P;
			else
				ans = (ans - sub + P) % P;
		}
	}
	ans = (ans + P - 1) % P;
	return ans;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(int n, k; _T--; cout.put('\n')) {
		cin >> n >> k;
		vector<int> a(n), b(k);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < k; ++i)
			cin >> b[i];
		cout << work(n, k, a, b);
	}
	cout.flush(); return 0;
}
