#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;
#define x first
#define t second

pair<LL, int> a[100003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; LL m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].t;
	sort(a+1, a+n+1);
	LL t = 0; int ans = 0, cnt = 0;
	__gnu_pbds::priority_queue<LL> q;
	for(int i = 1; i <= n; ++i) {
		t += a[i].x - a[i-1].x + a[i].t;
		q.push(a[i].t); ++cnt;
		while(!q.empty() && t > m) {
			t -= q.top();
			--cnt; q.pop();
		}
		if(t > m)
			break;
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
