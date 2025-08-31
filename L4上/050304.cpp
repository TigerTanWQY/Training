#include <iostream>
#include <cassert>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3, M = 30;
struct Node
{ int nxt[2], sz; }
seg[N * 32];
int idx = 1;

void ist(const int x) {
	int now = 1;
	for(int j = M - 1; j >= 0; --j) {
		++seg[now].sz;
		bool w = x >> j & 1;
		if(seg[now].nxt[w] == 0)
			seg[now].nxt[w] = ++idx;
		now = seg[now].nxt[w];
	}
	++seg[now].sz;
}

int query(const int x, int k) {
	int res = 0, now = 1;
	for(int j = M - 1; j >= 0; --j) {
		bool w = x >> j & 1;
		if(seg[seg[now].nxt[w]].sz >= k)
			now = seg[now].nxt[w];
		else {
			k -= seg[seg[now].nxt[w]].sz;
			res ^= 1 << j;
			now = seg[now].nxt[w ^ true];
		}
		assert(now != 0);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int _ = 0, x; _ < n; ++_) {
		cin >> x;
		ist(x);
	}
	for(int _ = 0, x, k; _ < m; ++_) {
		cin >> x >> k;
		cout << query(x, k) << '\n';
	}
	cout.flush();
	return 0;
}