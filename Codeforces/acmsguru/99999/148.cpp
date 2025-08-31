#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 15003;
struct Data {
	int id, ch;
	bool operator<(const Data& A) const
	{ return ch < A.ch; }
} a[N];
bitset<N> b;
int w[N], L[N], p[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> w[i] >> L[i] >> p[i];
	int tot = 0;
	for(int i = 1; i <= n; ++i) {
		tot += w[i];
		a[i] = {i, tot - L[i]};
	}
	sort(a + 1, a + n + 1);
	tot = 0; int psum = 0, j = 1;
	for(; j <= n && a[j].ch - tot <= 0; ++j)
		psum += p[a[j].id];
	int minp = psum, L1 = j, R1 = 0;
	for(int i = 1; i < n; ++i) {
		tot += w[i]; psum -= p[i];
		for(; j <= n && a[j].ch - tot <= 0; ++j)
			psum += p[a[j].id];
		if(psum < minp)
		{ minp = psum; L1 = j; R1 = i; }
	}
	for(int i = 1; i < L1; ++i)
		b[a[i].id] = 1;
	for(int i = R1 + 1; i <= n; ++i)
		if(b[i])
			cout << i << '\n';
	cout.flush(); return 0;
}
