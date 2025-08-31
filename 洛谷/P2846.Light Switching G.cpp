#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 100'003;
struct Node {
	int L, R;
	LL val;
	bool t;
} seg[N * 4];
int a[N];

void update(const int u)
{ seg[u].val = seg[u * 2].val + seg[u * 2 + 1].val; }

void pushdown(const int u, const int sz) {
	if(!seg[u].t)
		return;
	seg[u * 2].t ^= true;
	seg[u * 2 + 1].t ^= true;
	seg[u * 2].val = sz - sz / 2 - seg[u * 2].val;
	seg[u * 2 + 1].val = sz / 2 - seg[u * 2 + 1].val;
	seg[u].t = 0;
}

void buildTree(const int u, const int L, const int R) {
	seg[u].L = L; seg[u].R = R;
	if(L == R) {
		seg[u].val = a[L];
		return;
	}
	const int M = (L + R) / 2;
	buildTree(u * 2, L, M);
	buildTree(u * 2 + 1, M + 1, R);
	update(u);
}

LL query(const int u, const int L, const int R) {
	if(L <= seg[u].L && seg[u].R <= R)
		return seg[u].val;
	pushdown(u, seg[u].R - seg[u].L + 1);
	const int M = (seg[u].L + seg[u].R) / 2;
	if(R <= M)
		return query(u * 2, L, R);
	else if(L > M)
		return query(u * 2 + 1, L, R);
	else
		return query(u * 2, L, M) + query(u * 2 + 1, M + 1, R);
}

void modify(const int u, const int L, const int R) {
	if(L <= seg[u].L && seg[u].R <= R) {
		seg[u].t ^= true;
		seg[u].val = seg[u].R - seg[u].L + 1 - seg[u].val;
		return;
	}
	pushdown(u, seg[u].R - seg[u].L + 1);
	const int M = (seg[u].L + seg[u].R) / 2;
	if(R <= M)
		modify(u * 2, L, R);
	else if(L > M)
		modify(u * 2 + 1, L, R);
	else {
		modify(u * 2, L, M);
		modify(u * 2 + 1, M + 1, R);
	}
    update(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	buildTree(1, 1, n);
	for(int op, L, R; m--; ) {
		cin >> op >> L >> R;
		if(op == 0)
			modify(1, L, R);
		else
			cout << query(1, L, R) << '\n';
	}
	cout.flush();
	return 0;
}