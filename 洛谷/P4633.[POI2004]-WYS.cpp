#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 4e4 + 3, K = 2e5 + 3;
struct O_WYS {
	int id, x, y, f;
	bool operator<(const O_WYS& oth) const
	{ return x == oth.x? y < oth.y: x < oth.x; }
} sq[K];
map<int, int> mp;
int d[N], vis[N], cnt;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1, k, in[2]; i <= n; i++) {
		cin >> k >> in[0];
		int tmp = in[0];
		for(int j = 1; j < k; ++j) {
			cin >> in[j & 1];
			sq[++cnt] = {i, in[0], in[1], (j & 1)};
		}
		sq[++cnt] = {i, tmp, in[1], (k & 1)};
	}
	sort(sq + 1, sq + cnt + 1);
	for(int i = 1; i <= cnt; ++i) {
		int y = sq[i].y, id = sq[i].id;
		auto it = mp.find(y);
		if(it != mp.cend())
			mp.erase(it);
		else {
			mp[y] = i;
			if(!vis[id]) {
				it = mp.upper_bound(y);
				if(it != mp.cend())
					if(sq[it->second].f)
						vis[id] = vis[sq[it->second].id];
					else
						vis[id] = vis[sq[it->second].id] + 1;
				else
					vis[id] = 1;
			}
		}
	}
	cout << *max_element(vis + 1, vis + n + 1) << endl;
	return 0;
}
