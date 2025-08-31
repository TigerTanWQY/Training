#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 998244353, N = 1e6 + 3;
int a[N];
LL c[N];

int lb(int x)
{ return x & -x; }

void mdf(int x, LL w) {
	for(; x <= n; x += lb(x))
		c[x] += w;
}

LL qry(int x) {
	LL res = 0;
	for(; x; x -= lb(x))
		res += c[x];
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cout << endl;
	return 0;
}
