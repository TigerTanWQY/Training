#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 500'003;
int a[N], c[N], n;

int lb(int x)
{ return x & -x; }

LL qry(int x) {
	LL res = 0;
	for(; x; x -= lb(x))
		res += c[x];
	return res;
}

void mdf(int x, int w) {
	for(; x <= n; x += lb(x))
		c[x] += w;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	vector<int> st;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		st.push_back(a[i]);
	}
	sort(begin(st), end(st));
	st.erase(unique(begin(st), end(st)), cend(st));
	LL ans = 0;
	for(int i = 1; i <= n; ++i) {
		int x = lower_bound(cbegin(st), cend(st), a[i]) - cbegin(st) + 1;
		ans += qry(x);
		mdf(x, 1);
	}
	cout << (LL)n * (n - 1) / 2 - ans << endl;
	return 0;
}
