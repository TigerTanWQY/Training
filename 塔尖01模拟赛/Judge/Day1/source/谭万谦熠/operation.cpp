#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 998244353, N = 2e5 + 3;
bitset<N> ins;
int idx[N], L[N], R[N];

int main() {
	freopen("operation.in", "r", stdin);
	freopen("operation.out", "w", stdout);
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
		for(int i = 1; i <= n; ++i) {
			idx[i] = -1;
			ins[i] = false;
			L[i] = R[i] = 0;
		}
		for(int i = 0; i < k; ++i)
			idx[b[i]] = i;
		for(int i = 0; i < n; ++i) {
			if(i > 0)
				L[a[i]] = a[i - 1];
			if(i < n - 1)
				R[a[i]] = a[i + 1];
		}
		for(int i = 1; i <= n; ++i)
			ins[i] = !~idx[i];
		LL ans = 1;
		for(int i = 0; i < k; ++i) {
			int x = b[i], l = L[x], r = R[x];
			vector<int> c;
			if(l && ins[l])
				c.push_back(l);
			if(r && ins[r])
				c.push_back(r);
			ans = ans * c.size() % P;
			if(c.empty())
				break;
			int y = c[0];
			if(y == l) {
				if(R[y])
					L[R[y]] = L[y];
				if(L[y])
					R[L[y]] = R[y];
				L[x] = L[y];
				if(L[y])
					R[L[y]] = x;
			} else {
				if(L[y])
					R[L[y]] = R[y];
				if(R[y])
					L[R[y]] = L[y];
				R[x] = R[y];
				if(R[y])
					L[R[y]] = x;
			}
			ins[x] = true;
			L[y] = R[y] = 0;
		}
		cout << ans;
	}
	cout.flush(); return 0;
}
