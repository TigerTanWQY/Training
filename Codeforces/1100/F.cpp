#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 5e5 + 3, B = 30;
struct PLB {
	LL c[B + 3];
	int idx[B + 3];
	void init()
	{ memset(c, 0, sizeof c); memset(idx, 0, sizeof idx); }
	void ist(PLB A, int w, LL v) {
		*this = A;
		for(int i = B; ~i; --i)
			if(v >> i & 1) {
				if(!c[i]) {
					c[i] = v;
					idx[i] = w;
					return;
				} else if(idx[i] < w)
				{ swap(idx[i], w); swap(c[i], v); }
				v ^= c[i];
			}
	}
	LL qry(int L) {
		LL res = 0;
		for(int i = B; ~i; --i)
			if(c[i] && idx[i] >= L)
				res = max(res, res ^ c[i]);
		return res;
	}
} a[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n;
	a[0].init();
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		a[i].ist(a[i - 1], i, x);
	}
	cin >> _q;
	for(int L, R; _q--; cout.put('\n')) {
		cin >> L >> R;
		cout << a[R].qry(L);
	}
	cout.flush(); return 0;
}
