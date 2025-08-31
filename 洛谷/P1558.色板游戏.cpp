#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

constexpr const int N = 100'003;
struct Node {
	int L, R, tag;
	bitset<31> val;
	Node() noexcept
	: L(0), R(0), tag(0), val({})
	{ }
} seg[N * 4];
bitset<31> ans;
int a[N];

void settag(const int u, const int c) {
	seg[u].tag = c;
	seg[u].val.reset();
	seg[u].val.set(c, 1);
}

void pushdown(const int u) {
	if(seg[u].tag == 0)
		return;
	settag(u * 2, seg[u].tag);
	settag(u * 2 + 1, seg[u].tag);
	seg[u].tag = 0;
}

void buildTree(const int u, const int L, const int R) {
	seg[u].L = L; seg[u].R = R; seg[u].val.set(1, 1);
	if(seg[u].L == seg[u].R)
		return;
	const int M = (seg[u].L + seg[u].R) / 2;
	buildTree(u * 2, L, M);
	buildTree(u * 2 + 1, M + 1, R);
}

void modify(const int u, const int L, const int R, const int c) {
	if(seg[u].L == L && seg[u].R == R) {
		settag(u, c);
		return;
	}
	pushdown(u);
	const int M = (seg[u].L + seg[u].R) / 2;
	if(R <= M)
		modify(u * 2, L, R, c);
	else if(L > M)
		modify(u * 2 + 1, L, R, c);
	else {
		modify(u * 2, L, M, c);
		modify(u * 2 + 1, M + 1, R, c);
	}
	seg[u].val = (seg[u * 2].val | seg[u * 2 + 1].val);
}

void query(const int u, const int L, const int R) {
	if(seg[u].L == L && seg[u].R == R) {
		ans |= seg[u].val;
		return;
	}
	pushdown(u);
	int M = (seg[u].L + seg[u].R) / 2;
	if(R <= M)
		query(u * 2, L, R);
	else if(L > M)
		query(u * 2 + 1, L, R);
	else {
		query(u * 2, L, M);
		query(u * 2 + 1, M + 1, R);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q >> q;
	buildTree(1, 1, n);
	for(char op; q--; ) {
		int L, R;
		cin >> op >> L >> R;
		if(L > R)
			swap(L, R);
		if(op == 'C') {
			int c;
			cin >> c;
			modify(1, L, R, c);
		} else {
			query(1, L, R);
			cout << ans.count() << '\n';
			ans.reset();
		}
	}
	return 0;
}