#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

constexpr const int N = 1003;
int x[N], c[N];

int main() {
	freopen("mushroom.in", "r", stdin);
	freopen("mushroom.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> x[i];
	for(int i = 0; i < n; ++i)
		cin >> c[i];
	int g = x[0];
	for(int i = 1; i < n; ++i)
		g = __gcd(g, x[i]);
	if(g != 1) {
		cout << "imposib1e" << endl;
		return 0;
	}
	map<int, int> e;
	for(int i = 0; i < n; ++i)
		if(e.find(x[i]) == e.cend() || c[i] < e[x[i]])
			e[x[i]] = c[i];
	__gnu_pbds::priority_queue<pair<LL, int>, greater<pair<LL, int>>> q;
	unordered_map<int, LL> f;
	for(const auto& tmp: e) {
		int xi = tmp.first, ci = tmp.second;
		if(f.find(xi) == f.cend() || ci < f[xi]) {
			f[xi] = ci;
			q.push({ci, xi});
		}
	}
	LL ans = -1;
	while(!q.empty()) {
		LL ct = q.top().first; int st = q.top().second;
		q.pop();
		if(f[st] != ct)
			continue;
		if(st == 1) {
			ans = ct;
			break;
		}
		for(const auto& tmp: e) {
			int xi = tmp.first, ci = tmp.second,
				tst = __gcd(st, xi);
			if(tst == st)
				continue;
			LL tct = ct + ci;
			if(f.find(tst) == f.cend() || tct < f[tst]) {
				f[tst] = tct;
				q.push({tct, tst});
			}
		}
	}
	if(ans == -1 && f.find(1) != f.cend())
		ans = f[1];
	if(!~ans)
		cout << "imposib1e";
	else
		cout << ans;
	cout << endl; return 0;
}
