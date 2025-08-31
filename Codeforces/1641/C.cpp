#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
int fa[N], f[N];

int fnd(int x)
{ return fa[x] == x? x: fa[x] = fnd(fa[x]); }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q; ++n;
	iota(fa + 1, fa + n + 1, 1);
	memset(f, 0x3f, sizeof(f));
	for(int op, L, R; _q--; ) {
		cin >> op >> L;
		if(op == 0) {
			cin >> R >> op;
			if(op) {
				int a = fnd(L);
				f[a] = min(f[a], R);
			} else
				while(L <= R) {
					int a = fnd(L), b = fnd(L + 1);
					fa[a] = b;
					f[b] = min(f[a], f[b]);
					L = b;
				}
		} else
			if(fnd(L) != L)
				cout << "NO\n";
			else if(f[L] < fnd(L + 1))
				cout << "YES\n";
			else
				cout << "N/A\n";
	}
	cout.flush(); return 0;
}
