#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 2e4 + 3;
struct Data {
	int L, R, H;
	LL val;
	bool friend operator<(const Data& u, const Data& v) {
		if(u.H != v.H)
			return u.H < v.H;
		else
			return u.val > v.val;
	}
} que[N * 2];
struct Node {
	int L, R;
	LL val, tag;
} seg[N * 4];
int id[N];

void init(void) {
	memset(que, 0, sizeof(que));
	memset(seg, 0, sizeof(seg));
}

void update(const int u)
{ seg[u].val = max(seg[u * 2].val, seg[u * 2 + 1].val); }

void settag(const int u, const LL t) {
	seg[u].val += t;
	seg[u].tag += t;
}

void pushdown(const int u) {
	if(seg[u].tag == 0)
		return;
	settag(u * 2, seg[u].tag);
	settag(u * 2 + 1, seg[u].tag);
	seg[u].tag = 0;
}

void buildTree(const int u, const int L, const int R) {
	seg[u].L = L; seg[u].R = R; seg[u].val = seg[u].tag = 0;
	if(L == R)
		return;
	const int M = (L + R) / 2;
	buildTree(u * 2, L, M);
	buildTree(u * 2 + 1, M + 1, R);
}

void modify(const int u, const int L, const int R, const LL t) {
	if(L <= seg[u].L && seg[u].R <= R) {
		settag(u, t);
		return;
	}
	pushdown(u);
	const int M = (seg[u].L + seg[u].R) / 2;
	if(R <= M)
		modify(u * 2, L, R, t);
	else if(L > M)
		modify(u * 2 + 1, L, R, t);
	else {
		modify(u * 2, L, M, t);
		modify(u * 2 + 1, M + 1, R, t);
	}
	update(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n, W, H; _T--; cout.put('\n'), init()) {
		cin >> n >> W >> H;
		for(int i = 1, u, v, l; i <= n; ++i) {
			cin >> u >> v >> l;
			id[i * 2 - 1] = v;
			id[i * 2] = v + H - 1;
			que[i * 2 - 1] = {v, v + H - 1, u, l};
			que[i * 2] = {v, v + H - 1, u + W - 1, -l};
		}
		n *= 2;
		sort(id + 1, id + n + 1);
		sort(que + 1, que + n + 1);
		const int m = unique(id + 1, id + n + 1) - id - 1;
		for(int i = 1; i <= n; ++i) {
			const int pos1 = lower_bound(id + 1, id + m + 1, que[i].L) - id, pos2 = lower_bound(id + 1, id + m + 1, que[i].R) - id;
			que[i].L = pos1;
			que[i].R = pos2;
		}
		buildTree(1, 1, m);
		LL ans = 0;
		for(int i = 1; i <= n; ++i) {
			modify(1, que[i].L, que[i].R, que[i].val);
			ans = max(ans, seg[1].val);
		}
		cout << ans;
	}
	cout.flush();
	return 0;
}