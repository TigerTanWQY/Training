#include <iostream>
#include <utility>
#include <numeric>
#include <vector>
using namespace std;
using PII = pair<int, int>;

const int N = 4'000'003;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int g0 = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		g0 = gcd(g0, a[i]);
	}
	vector<PII> b{{0, 0}};
	for(int L = 1, R; L <= n; L = R) {
		while(L <= n && a[L] == g0)
			++L;
		if(L > n)
			break;
		R = L + 1;
		while(R <= n && a[R] != g0)
			++R;
		b.push_back({L, R});
	}
	if(b.empty()) {
		cout << '0';
		return 0;
	}
	for(int i = 1, minn = 1e9 + 1; i < b.size(); ++i) {
		auto [L, R] = b[i];
		int g = 0;
		for(int j = L; j < R; ++j)
			g = gcd(g, a[j]);
		f[i] = f[i - 1] + R - L + (g != g0) + k;
		if(minn <= 1e9)
			f[i] = min(f[i], R + minn + k);
		minn = min(minn, f[i - 1] - L);
	}
	cout << f[b.size() - 1];
	cout.flush();
	return 0;
}