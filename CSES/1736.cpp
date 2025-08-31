#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
pair<LL, LL> laz[N << 2];
LL arr[N], seg[N << 2];

void buildTree(int u, int s, int e) {
	if(s == e) {
		seg[u] = arr[s];
		return;
	}
	int M = (e - s) / 2 + s, l = 2 * u + 1, r = l + 1;
	buildTree(l, s, M);
	buildTree(r, M + 1, e);
	seg[u] = seg[l] + seg[r];
}

void push_down(int u, int s, int e) {
	int M = (e - s) / 2 + s, l = 2 * u + 1, r = l + 1;
	auto [a, b] = laz[u];
	assert(a && b);
	if(e > s) {
		seg[l] += a * (M - s + 1) + (M - s + 1ll) * (M - s) / 2 * b;
		seg[r] += (a + b * (M - s + 1ll)) * (e - M) + (e - M) * (e - M - 1ll) / 2 * b;
		laz[l].first += a;
		laz[l].second += b;
		laz[r].first += a + b * (M - s + 1);
		laz[r].second += b;
	}
	laz[u] = {0, 0};
}

void add(int qs, int qe, int u, int s, int e) {
	if(qe < s || qs > e)
		return;
	if(laz[u].first)
		push_down(u, s, e);
	if(s >= qs && e <= qe) {
		assert(laz[u].first == 0);
		assert(laz[u].second == 0);
		seg[u] += (s - qs + 1) * (e - s + 1ll) + (e - s + 1ll) * (e - s) / 2;
		laz[u] = {s - qs + 1, 1};
		return;
	}
	int M = (e - s) / 2 + s, l = 2 * u + 1, r = l + 1;
	add(qs, qe, l, s, M);
	add(qs, qe, r, M + 1, e);
	seg[u] = seg[l] + seg[r];
}

LL get(int qs, int qe, int u, int s, int e) {
	if(qe < s || qs > e)
		return 0;
	if(s >= qs && e <= qe)
		return seg[u];
	if(laz[u].first)
		push_down(u, s, e);
	int M = (e - s) / 2 + s, l = 2 * u + 1, r = l + 1;
	return get(qs, qe, l, s, M) + get(qs, qe, r, M + 1, e);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q;
	for(int u = 0; u < n; ++u)
		cin >> arr[u];
	buildTree(0, 0, n - 1);
	for(int op, a, b; _q--; ) {
		cin >> op >> a >> b;
		if(op == 1)
			add(a - 1, b - 1, 0, 0, n - 1);
		else
			cout << get(a - 1, b - 1, 0, 0, n - 1) << '\n';
	}
	cout.flush();
	return 0;
}
