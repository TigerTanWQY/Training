#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3, Q = 3e4 + 3;
struct Query {
	int L, R, w;
	bool operator<(const Query& A) const {
		if(w == A.w)
			return L < A.L;
		else
			return w > A.w;
	}
} a[Q], cp[Q];
int n;

struct DSU {
	int c[N];
	void clear(int x)
	{ iota(c, c + x + 1, 0); }
	int fnd(int x) {
		if(c[x] == x)
			return x;
		return c[x] = fnd(c[x]);
	}
} s;

bool check(int x) {
	s.clear(n + 1);
	for(int i = 1; i <= x; ++i)
		cp[i] = a[i];
	sort(cp + 1, cp + x + 1);
	int p = cp[1].w, lx, ln, rx, rn;
	lx = ln = cp[1].L; rx = rn = cp[1].R;
	for(int i = 2; i <= x; ++i)
		if(p == cp[i].w) {
			ln = min(ln, cp[i].L);
			rn = min(rn, cp[i].R);
			lx = max(lx, cp[i].L);
			rx = max(rx, cp[i].R);
			if(lx > rn)
				return 0;
		} else {
			if(s.fnd(lx) > rn)
				return 0;
			for(int j = s.fnd(ln); ; j = s.fnd(j + 1))
				if(j > rx)
					break;
				else
					s.c[j] = s.c[j+1];
			p = cp[i].w;
			lx = ln = cp[i].L;
			rx = rn = cp[i].R;
		}
	return s.fnd(lx) <= rn;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q;
	cin >> n >> q;
	for(int i = 1; i <= q; ++i)
		cin >> a[i].L >> a[i].R >> a[i].w;
	int L = 0, R = q + 1;
	while(L < R - 1) {
		int mid = (L + R) >> 1;
		if(check(mid))
			L = mid;
		else
			R = mid;
	}
	if(R == q + 1)
		cout.put('0');
	else
		cout << R;
	cout << endl; return 0;
}
