#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 100'003;
struct Node {
	int L, R;
	LL tot;
} seg[N * 4];
int a[N];

void buildTree(const int u, const int L, const int R) {
	seg[u].L = L; seg[u].R = R;
	if(L == R) {
		seg[u].tot = a[L];
		return;
	}
	int M = (L + R) / 2;
	buildTree(u * 2, L, M);
	buildTree(u * 2 + 1, M + 1, R);
	seg[u].tot += seg[u * 2].tot + seg[u * 2 + 1].tot;
}

LL query(const int u, const int L, const int R) {
	if(L <= seg[u].L && seg[u].R <= R)
		return seg[u].tot;
	LL res = 0;
	int M = (seg[u].L + seg[u].R) / 2;
	if(L <= M)
		res += query(u * 2, L, R);
	if(R > M)
		res += query(u * 2 + 1, L, R);
	return res;
}

void modify(const int u, const int x, const LL w) {
	if(seg[u].L == seg[u].R) {
		seg[u].tot = w;
		return;
	}
	int M = (seg[u].L + seg[u].R) / 2;
	if(x <= M)
		modify(u * 2, x, w);
	else
		modify(u * 2 + 1, x, w);
	seg[u].tot = seg[u * 2].tot + seg[u * 2 + 1].tot;
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
			modify(1, x, a[x] + y);
			a[x] += y;
		} else
			cout << query(1, x, y) << '\n';
	}
	cout.flush();
	return 0;
}