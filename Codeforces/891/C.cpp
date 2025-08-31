#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e5 + 3;
int fa[N];
int fnd(int x)
{ return fa[x] == x? x: fa[x] = fnd(fa[x]); }
void mrge(int x, int y) {
	x = fnd(x); y = fnd(y);
	if(x == y)
		return;
	fa[y] = x;
}
struct Edge {
	int x, y, val, id, tx, ty;
	bool operator<(const Edge& a) const
	{ return val < a.val; }
} e[N];
bool cmp(const Edge& x, const Edge& y)
{ return x.id < y.id; }

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, _q;
	cin >> n >> m;
	iota(fa, fa + n + 1, 0);
	for(int i = 1; i <= m; ++i)
	{ cin >> e[i].x >> e[i].y >> e[i].val; e[i].id = i; }
	sort(e + 1, e + m + 1);
	e[0].val = -1;
	for(int i = 1; i <= m; ) {
		int j = i;
		do {
			e[j].tx = fnd(e[j].x);
			e[j].ty = fnd(e[j].y);
			++j;
		} while(j <= m && e[j].val == e[j - 1].val);
		while(i < j) {
			for(; fnd(e[i].x) == fnd(e[i].y) && i < j; ++i);
			if(i < j)
				mrge(e[i].x, e[i].y);
		}
	}
	cin >> _q;
	sort(e + 1, e + m + 1, cmp);
	iota(fa, fa + n + 1, 0);
	for(int k; _q--; cout.put('\n')) {
		cin >> k;
		vector<Edge> v;
		for(int i = 1, x; i <= k; ++i) {
			cin >> x;
			v.push_back({e[x].tx, e[x].ty, e[x].val, 0, 0, 0});
		}
		sort(begin(v), end(v));
		bool flag = true;
		for(int i = 0, sz = v.size() - 1; i <= sz && flag; ) {
			if(v[i].x == v[i].y)
			{ flag = false; break;}
			mrge(v[i].x, v[i].y);
			int j = i + 1;
			for(; j <= sz && v[j].val == v[i].val; ++j) {
				if(fnd(v[j].x) == fnd(v[j].y))
				{ flag = false; break;}
				mrge(v[j].x, v[j].y);
			}
			for(; i < j; ++i)
			{ fa[v[i].x] = v[i].x; fa[v[i].y] = v[i].y; }
		}
		cout << (flag? "YES": "NO");
	}
	cout.flush(); return 0;
}
