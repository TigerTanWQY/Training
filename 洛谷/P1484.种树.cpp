#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

constexpr const int N = 6e5 + 3;
bool vis[N];
int L[N], R[N];
long long a[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	__gnu_pbds::priority_queue<pair<long long, int>> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		q.push({a[i], i});
		L[i] = i-1; R[i] = i+1;
	}
	long long ans = 0;
	for(int i = 1; i <= k; ++i) {
		while(!q.empty() && vis[q.top().second])
			q.pop();
		if(q.empty() || q.top().first < 0)
			break;
		auto [v, id] = q.top(); q.pop();
		ans += v;
		vis[id] = vis[L[id]] = vis[R[id]] = true;
		a[++n] = a[L[id]] + a[R[id]] - a[id];
		L[n] = L[L[id]]; R[n] = R[R[id]];
		R[L[n]] = L[R[n]] = n;
		q.push({a[n], n});
	}
	cout << ans << endl;
	return 0;
}
