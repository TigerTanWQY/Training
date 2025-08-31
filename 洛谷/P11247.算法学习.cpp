#include <bits/stdc++.h>
using namespace std;
#define _tp second
#define _w first

constexpr const int N = 1e5 + 3;
pair<int, int> a[N];
deque<int> G[N];
bitset<N> ok;
int cnt[N];
long long tot[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n, k;
	cin >> m >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i]._tp;
	for(int i = 1; i <= n; ++i)
		cin >> a[i]._w;
	for(int i = 1; i <= n; ++i)
		G[a[i]._tp].push_back(a[i]._w);
	for(int i = 1; i <= m; ++i)
		if(!G[i].empty())
			sort(begin(G[i]), end(G[i]), greater<>());
	if(m == 1) {
		cout.put('0' + (G[1].front() >= k)); cout << endl;
		return 0;
	}
	for(int lst = 0; ; ) {
		int res = 0; bool flag = true;
		for(int i = 1; flag && i <= m; ++i)
			if(!G[i].empty()) {
				++cnt[i];
				tot[i] += G[i].front();
				G[i].pop_front();
				++res;
				if(tot[i] >= k)
					ok[i] = true;
				if(ok.count() == m)
					flag = false;
			}
		if(res == 1 && lst == 1) {
			cout << "-1" << endl;
			return 0;
		} else if(!flag) {
			int ans = 0;
			for(int j = 1; j <= m; ++j)
				ans += cnt[j];
			cout << ans << endl;
			return 0;
		} else if(res == 0 && lst == 0) {
			cout << "-1" << endl;
			return 0;
		} else
			lst = res;
	}
	return 0;
}
