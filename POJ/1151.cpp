#include <iostream>
#include <iomanip>
#include <algorithm>
#define Ls (x << 1)
#define Rs (x << 1 | 1)
using namespace std;
#define y1 asdfg

const int N = 1e3 + 3;
double X[N << 1];

struct Data {
	double L, R, h;
	int tag;
	Data(): L(0), R(0), h(0), tag(0) { }
	Data(double _L, double _R, double _h, int _tag)
	: L(_L), R(_R), h(_h), tag(_tag) { }
	bool operator<(const Data &A) const
	{ return h < A.h; }
} line[N << 1];

struct SegTree {
	int L, R, tot;
	double len;
} T[N << 2];

void build(int x, int L, int R) {
	T[x].L = L; T[x].R = R;
	T[x].len = 0; T[x].tot = 0;
	if(L == R)
		return;
	int M = (L + R) >> 1;
	build(Ls, L, M);
	build(Rs, M + 1, R);
	return;
}

void pushup(int x) {
	int L = T[x].L, R = T[x].R;
	T[x].len = (T[x].tot? X[R + 1] - X[L]: T[Ls].len + T[Rs].len);
}

void mdf(int x, double qL, double qR, int c) {
	int L = T[x].L, R = T[x].R;
	if(X[R + 1] <= qL || qR <= X[L])
		return;
	if(qL <= X[L] && X[R + 1] <= qR) {
		T[x].tot += c;
		pushup(x);
		return;
	}
	mdf(Ls, qL, qR, c);
	mdf(Rs, qL, qR, c);
	pushup(x);
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	for(int _ = 1, n; cin >> n && n; cout.put('\n'), ++_) {
		for(int i = 1; i <= n; ++i) {
			double x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			X[2 * i - 1] = x1; X[2 * i] = x2;
			line[2 * i - 1] = Data(x1, x2, y1, 1);
			line[2 * i] = Data(x1, x2, y2, -1);
		}
		n <<= 1;
		sort(line + 1, line + n + 1);
		sort(X + 1, X + n + 1);
		build(1, 1, unique(X + 1, X + n + 1) - X - 2);
		double ans = 0;
		for(int i = 1; i < n; ++i) {
			mdf(1, line[i].L, line[i].R, line[i].tag);
			ans += T[1].len * (line[i + 1].h - line[i].h);
		}
		cout << "Test case #" << _ <<
			"\nTotal explored area: " <<
			fixed << setprecision(2) << ans << '\n';
	}
	cout.flush(); return 0;
}
