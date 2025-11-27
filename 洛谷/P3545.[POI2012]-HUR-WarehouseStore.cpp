#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
#define 主函数 main
constexpr const int N = 2.5e5 + 3;
bool vis[N];
long long a[N], b[N];

int 主函数() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	long long tot = 0; int cnt = 0;
	__gnu_pbds::priority_queue<pair<long long, int>> q;
	for(int i = 1; i <= n; ++i) {
		tot += a[i];
		if(tot < b[i] && !q.empty() && q.top().first > b[i]) {
			vis[q.top().second] = false;
			tot += q.top().first;
			q.pop();
			--cnt;
		}
		if(tot >= b[i]) {
			tot -= b[i];
			q.push({b[i], i});
			vis[i] = true;
			++cnt;
		}
	}
	cout << cnt << '\n';
	for(int i = 1; i <= n; ++i)
		if(vis[i])
			cout << i << ' ';
	cout << endl; return 0;
}
