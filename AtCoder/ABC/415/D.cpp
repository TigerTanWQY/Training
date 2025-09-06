#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	LL n; int m;
	cin >> n >> m;
	vector<pair<LL, LL>> a;
	for(int i = 0; i < m; ++i) {
		LL x, y;
		cin >> x >> y;
		if(x <= n)
			a.push_back({x, y});
	}
	__gnu_pbds::priority_queue<pair<LL, LL>, greater<>> q;
	for(const auto& [x, y]: a)
		q.push({x - y, x});
	LL cnt = n, ans = 0;
	while(!q.empty()) {
		while(!q.empty() && q.top().second > cnt)
			q.pop();
		if(q.empty())
			break;
		const auto& [nt, x] = q.top();
		LL t = (cnt - x) / nt + 1;
		ans += t;
		cnt -= t * nt;
	}
	cout << ans << endl;
	return 0;
}
