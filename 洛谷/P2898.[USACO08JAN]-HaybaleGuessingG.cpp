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
int n;

bool chk(int x) {
	s.clear(n + 1);
	memcpy(cp, a, sizeof(int) * (x+1));
	sort(cp + 1, cp + x + 1);
	int p = cp[1].w, Lx, Ln, Rx, Rn;
	Lx = Ln = cp[1].L; Rx = Rn = cp[1].R;
	for(int i = 2; i <= x; ++i)
		if(p == cp[i].w) {
			Ln = min(Ln, cp[i].L); Rn = min(Rn, cp[i].R);
			Lx = max(Lx, cp[i].L); Rx = max(Rx, cp[i].R);
			if(Lx > Rn)
				return 0;
		} else {
			if(s.fnd(Lx) > Rn)
				return 0;
			for(int j = s.fnd(Ln); ; j = s.fnd(j + 1))
				if(j > Rx)
					break;
				else
					s.c[j] = s.c[j + 1];
			p = cp[i].w;
			Lx = Ln = cp[i].L;
			Rx = Rn = cp[i].R;
		}
	return s.fnd(Lx) <= Rn;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q;
	cin >> n >> q;
	for(int i = 1; i <= q; ++i)
		cin >> a[i].L >> a[i].R >> a[i].w;
	int L = 0, R = q + 1;
	while(L < R - 1) {
		int M = (L + R) >> 1;
		if(chk(M))
			L = M;
		else
			R = M;
	}
	if(R == q + 1)
		cout.put('0');
	else
		cout << R;
	cout << endl; return 0;
}
