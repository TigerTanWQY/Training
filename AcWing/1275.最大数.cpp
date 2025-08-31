#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 200'003;
struct Node
{ int L, R, maxn; }
seg[N * 4];

void buildTree(const int u, const int L, const int R) {
	seg[u].L = L; seg[u].R = R;
	if(L == R) {
		seg[u].maxn = -0x3f3f3f3f;
		return;
	}
	int M = (L + R) / 2;
	buildTree(u * 2, L, M);
	buildTree(u * 2 + 1, M + 1, R);
	seg[u].maxn = max(seg[u * 2].maxn, seg[u * 2 + 1].maxn);
}

int query(const int u, const int L, const int R) {
	if(L <= seg[u].L && seg[u].R <= R)
		return seg[u].maxn;
	int res = -0x3f3f3f3f, M = (seg[u].L + seg[u].R) / 2;
	if(L <= M)
		res = max(res, query(u * 2, L, R));
	if(R > M)
		res = max(res, query(u * 2 + 1, L, R));
	return res;
}

void modify(const int u, const int x, const int w) {
	if(seg[u].L == seg[u].R) {
		seg[u].maxn = w;
		return;
	}
	int M = (seg[u].L + seg[u].R) / 2;
	if(x <= M)
		modify(u * 2, x, w);
	else
		modify(u * 2 + 1, x, w);
	seg[u].maxn = max(seg[u * 2].maxn, seg[u * 2 + 1].maxn);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0, m, p;
	cin >> m >> p;
	buildTree(1, 1, N - 3);
	int x, last = 0;
	for(char op; m--; ) {
		cin >> op >> x;
		if(op == 'Q') {
			last = query(1, n - x + 1, n);
			cout << last << '\n';
		}
		else/* if(op == 'A')*/
			modify(1, ++n, ((long long)x + last + p) % p);
	}
	cout.flush();
	return 0;
}