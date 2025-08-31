#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 100'003;
struct Node {
	int L, R;
	LL val;
} seg[N * 4];

void update(const int u)
{ seg[u].val = seg[u * 2].val + seg[u * 2 + 1].val; }

void buildTree(const int u, const int L, const int R) {
	seg[u].L = L; seg[u].R = R;
	if(L == R) {
		seg[u].val = 0;
		return;
	}
	int M = (L + R) / 2;
	buildTree(u * 2, L, M);
	buildTree(u * 2 + 1, M + 1, R);
	update(u);
}

LL query(const int u, const int L, const int R) {
	if(L <= seg[u].L && seg[u].R <= R)
		return seg[u].val;
	int M = (seg[u].L + seg[u].R) / 2;
	if(R <= M)
		return query(u * 2, L, R);
	else if(L > M)
		return query(u * 2 + 1, L, R);
	else
		return query(u * 2, L, M) + query(u * 2 + 1, M + 1, R);
}

void modify(const int u, const int x, const int w) {
	if(seg[u].L == seg[u].R) {
		seg[u].val += w;
		return;
	}
	int M = (seg[u].L + seg[u].R) / 2;
	if(x <= M)
		modify(u * 2, x, w);
	else
		modify(u * 2 + 1, x, w);
	update(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	buildTree(1, 1, n);
	for(char op; m--; ) {
		int x, y;
		cin >> op >> x >> y;
		if(op == 'x')
			modify(1, x, y);
		else
			cout << query(1, x, y) << '\n';
	}
	cout.flush();
	return 0;
}