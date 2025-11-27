#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

pair<int, int> a[100003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a+1, a+n+1);
	long long ans = 0;
	__gnu_pbds::priority_queue<int, greater<>> q;
	for(int i = 1; i <= n; ++i)
		if(a[i].first <= q.size()) {
			if(a[i].second > q.top()) {
				ans -= q.top();
				q.pop();
				q.push(a[i].second);
				ans += a[i].second;
			}
		} else {
			q.push(a[i].second);
			ans += a[i].second;
		}
	cout << ans << endl;
	return 0;
}
