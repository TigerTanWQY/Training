#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 500'003;
struct Info {
	LL tot, mss, mpre, msuf;
	Info() noexcept = default;
	Info(const LL& x) noexcept
	: tot(x), mss(x), mpre(x), msuf(x)
	{ }
	Info friend operator+(const Info& x, const Info& y) {
		Info res;
		res.mss = max({x.mss, y.mss, x.msuf + y.mpre});
		res.mpre = max(x.mpre, x.tot + y.mpre);
		res.msuf = max(y.msuf, y.tot + x.msuf);
		res.tot = x.tot + y.tot;
		return res;
	}
	Info& operator+=(const Info& x) {
		*this = *this + x;
		return *this;
	}
};
struct Node {
	int L, R;
	Info val;
} seg[N * 4];
int a[N];

void buildTree(const int u, const int L, const int R) {
	seg[u].L = L; seg[u].R = R;
	if(L == R) {
		seg[u].val = a[L];
		return;
	}
	int M = (L + R) / 2;
	buildTree(u * 2, L, M);
	buildTree(u * 2 + 1, M + 1, R);
	seg[u].val = seg[u * 2].val + seg[u * 2 + 1].val;
}

Info query(const int u, const int L, const int R) {
	if(L <= seg[u].L && seg[u].R <= R)
		return seg[u].val;
	Info res;
	bool flag = false;
	int M = (seg[u].L + seg[u].R) / 2;
	if(L <= M) {
		res = query(u * 2, L, R);
		flag = true;
	}
	if(R > M)
		if(flag)
			res += query(u * 2 + 1, L, R);
		else
			res = query(u * 2 + 1, L, R);
	return res;
}

void modify(const int u, const int x, const LL w) {
	if(seg[u].L == seg[u].R) {
		seg[u].val = w;
		return;
	}
	int M = (seg[u].L + seg[u].R) / 2;
	if(x <= M)
		modify(u * 2, x, w);
	else
		modify(u * 2 + 1, x, w);
	seg[u].val = seg[u * 2].val + seg[u * 2 + 1].val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	buildTree(1, 1, n);
	for(int k, x, y; m--; ) {
		cin >> k >> x >> y;
		if(k == 1) {
			if(x > y)
				swap(x, y);
			cout << query(1, x, y).mss << '\n';
		} else
			modify(1, x, y);
	}
	cout.flush();
	return 0;
}