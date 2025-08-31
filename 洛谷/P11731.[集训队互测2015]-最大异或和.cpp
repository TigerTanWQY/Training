#include <bits/stdc++.h>
using namespace std;
constexpr const int N = 2e3 + 3;
using BS = bitset<N>;

vector<pair<BS, int>> G[N];
int op[N], st[N], m;
BS a[N], s[N];

struct {
	int c[N];
	BS s[N];
	void ist(BS v, int x) {
		for(int i = m - 1; ~i; --i)
			if(v[i]) {
				if(!c[i]) {
					s[i] = v;
					c[i] = x;
					break;
				}
				if(x > c[i])
				{ swap(v, s[i]); swap(x, c[i]); }
				v ^= s[i];
			}
	}
	void del(int x) {
		for(int i = m - 1; ~i; --i)
			if(c[i] == x)
			{ s[i].reset(); c[i] = 0; }
	}
	BS qry() {
		BS res;
		for(int i = m - 1; ~i; --i)
			if(!res[i] && c[i])
				res ^= s[i];
		return res;
	}
} xxj;
void print(BS x) {
	for(int i = m - 1; ~i; --i)
		cout.put('0' + x[i]);
	cout.put('\n');
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = a[i - 1] ^ a[i];
	}
	for(int i = 1, L, R; i <= q; ++i) {
		cin >> op[i];
		BS w;
		if(op[i] <= 2)
			cin >> L >> R >> w;
		if(op[i] == 1)
			for(int j = L; j <= R; ++j)
				a[j] ^= w;
		if(op[i] == 2)
			for(int j = L; j <= R; ++j)
				a[j] = w;
		if(op[i] <= 2)
			for(int j = L; j <= min(R + 1, n); ++j) {
				w = a[j] ^ a[j-1];
				if(s[j] != w) {
					if(s[j].any())
						G[st[j]].push_back({s[j], i});
					s[j] = w;
					st[j] = i;
				}
			}
	}
	for(int i = 1; i <= n; ++i)
		if(s[i].any())
			G[st[i]].push_back({s[i], q + 1});
	for(int i = 0; i <= q; ++i) {
		xxj.del(i);
		for(const auto& [v, w]: G[i])
			xxj.ist(v, w);
		if(op[i] == 3)
			print(xxj.qry());
	}
	cout.flush(); return 0;
}
