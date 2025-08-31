#include<bits/stdc++.h>
using namespace std;

void ckmn(int &x, int v)
{ if(v < x) x = v; }
void ckmx(int &x, int v)
{ if(v > x) x = v; }

constexpr const int N = 1e5 + 5;
pair<int, int> D[N], Q[N];
int n, b[1000003], m, op[N], fa[N], d;

int fnd(int x)
{ return fa[x] == x? x: fa[x] = fnd(fa[x]); }

vector<int> t[N << 2];

void upd(int x, int l, int r, int L, int R, int id){
	if(L > R) return;
	if(l >= L && r <= R) return t[x].push_back(id), void();
	int M = l + r >> 1;
	if(L <= M) upd(x << 1, l, M, L, R, id);
	if(R > M) upd(x << 1 | 1, M + 1, r, L, R, id);
}

vector<int> A;
void qry(int x, int l, int r, int p){
	for(int v : t[x]) A.push_back(v);
	t[x].clear();
	if(l == r) return;
	int M = l + r >> 1;
	if(p <= M) qry(x << 1, l, M, p); else qry(x << 1 | 1, M + 1, r, p);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);

	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> op[i] >> Q[i].first >> Q[i].second, fa[i] = i;
	for(int i = 1; i <= n; ++i) if(op[i] == 1) b[++m] = Q[i].first, b[++m] = Q[i].second;

	sort(b + 1, b + m + 1);
	m = unique(b + 1, b + m + 1) - b - 1;
	for(int i = 1; i <= n; ++i) if(op[i] == 1)
		Q[i].first = lower_bound(b + 1, b + m + 1, Q[i].first) - b,
		Q[i].second = lower_bound(b + 1, b + m + 1, Q[i].second) - b;

	for(int i = 1; i <= n; ++i)
		if(op[i] == 1){
			A.clear(); qry(1, 1, m, Q[i].first), qry(1, 1, m, Q[i].second);
			++d;
			D[d].first = Q[i].first, D[d].second = Q[i].second;
			for(int x : A)
				fa[x] = d, ckmn(D[d].first, D[x].first), ckmx(D[d].second, D[x].second);
			upd(1, 1, m, D[d].first + 1, D[d].second - 1, d);
		} else{
			int x = fnd(Q[i].first), y = fnd(Q[i].second);
			if(x == y || (D[x].first >= D[y].first && D[x].second <= D[y].second)) cout << "YES";
			else cout << "NO";
			cout.put('\n');
		}
	cout.flush(); return 0;
}
