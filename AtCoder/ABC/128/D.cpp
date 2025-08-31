#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/priority_queue.hpp>

int a[53];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	__gnu_pbds::priority_queue<int, greater<>> q;
	int ans = 0;
	for(int i = 0; i <= k; ++i)
		for(int j = 0; i + j <= k && i + j <= n; ++j) {
			for(int x = 1; x <= i; ++x)
				q.push(a[x]);
			for(int x = n; x >= n - j + 1; --x)
				q.push(a[x]);
			for(int c = k - i - j; !q.empty() && c-- && q.top() < 0; q.pop());
			int res = 0;
			for(; !q.empty(); q.pop())
				res += q.top();
			ans = max(ans, res);
		}
	cout << ans << endl;
	return 0;
}
