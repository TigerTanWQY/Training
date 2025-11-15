#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 5e5;

class Fenwick {
	private:
		int n;
		vector<LL> T;
	public:
		Fenwick(int _n)
			: n(_n), T(_n+2, 0)
		{ }
		void mdf(int x, LL w) {
			++x;
			for(; x <= n; x += x & -x)
				T[x] += w;
		}
		LL qry(int x) {
			++x; LL res = 0;
			for(; x; x -= x & -x)
				res += T[x];
			return res;
		}
		LL rmq(int L, int R)
		{ return (L > R? 0: qry(R) - qry(L-1)); }
};
class Solve {
	private:
		int n;
		vector<int> a;
		Fenwick Tcnt, Scnt;
	public:
		Solve(int _n, const vector<int>& _a)
			: n(_n), a(_a), Tcnt(N+1), Scnt(N+1) {
			for(int i = 0; i < n; ++i) {
				Tcnt.mdf(a[i], 1);
				Scnt.mdf(a[i], a[i]);
			}
		}
		void mdf(int x, int y) {
			Tcnt.mdf(a[x-1], -1);
			Scnt.mdf(a[x-1], -a[x-1]);
			Tcnt.mdf(y, 1);
			Scnt.mdf(y, y);
			a[x-1] = y;
		}
		LL qry(int L, int R) {
			return (L > R? 1LL * n * L:
					Tcnt.rmq(0, L-1) * L + Scnt.rmq(L, R) + Tcnt.rmq(R+1, N) * R);
		}
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	Solve s(n, a);
	for(int tp, x, y; _q--;) {
		cin >> tp >> x >> y;
		if(tp == 1)
			s.mdf(x, y);
		else
			cout << s.qry(x, y) << '\n';
	}
	cout.flush(); return 0;
}
