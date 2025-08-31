#include <iostream>
#include <algorithm>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

pair<int, int> a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n, k; _T--; cout.put('\n')) {
		cin >> n >> k;
		for(int i = 1; i <= n; ++i)
			cin >> a[i].first;
		for(int i = 1; i <= n; ++i)
			cin >> a[i].second;
		sort(a + 1, a + n + 1);
		__gnu_pbds::priority_queue<int> q;
		LL tot = 0, ans = 0x3f3f3f3f3f3f3f3f;
		for(int i = 1; i <= n; ++i) {
			q.push(a[i].second);
			tot += a[i].second;
			if(q.size() > k) {
				tot -= q.top();
				q.pop();
			}
			if(q.size() == k)
				ans = min(ans, a[i].first * tot);
		}
		cout << ans;
	}
	cout.flush();
	return 0;
}