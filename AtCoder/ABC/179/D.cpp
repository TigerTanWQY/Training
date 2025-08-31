#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <iostream>
#include <vector>
#include <algorithm>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

constexpr const int N = 200'000;
mint f[2 * N + 3];

int read() {
	int res = 0;
	char ch = cin.get();
	for(; ch != EOF && ('0' > ch || ch > '9'); ch = cin.get());
	for(; '0' <= ch && ch <= '9'; ch = cin.get())
		res = res * 10 + ch - '0';
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = read(), k = read();
	vector<int> st;
	for(int i = 1, L, R; i <= k; ++i) {
		L = read(); R = read();
		for(int j = L; j <= R; ++j)
			st.push_back(j);
	}
	sort(st.begin(), st.end());
	for(const auto& d: st)
		f[d + 1] = 1;
	for(int i = 1; i <= n; ++i)
		for(const auto& d: st)
			if(i - d >= 0)
				f[i] += f[i - d];
			else
				break;
	cout << f[n].val() << endl;
	return 0;
}