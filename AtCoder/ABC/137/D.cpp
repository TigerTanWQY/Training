#include <bits/stdc++.h>
using namespace std;
#define t first
#define w second
constexpr const int N = 1e5 + 3;
pair<int, int> a[N];
int f[N];
#include <ext/pb_ds/priority_queue.hpp>
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i].t >> a[i].w;
	sort(a, a + n);
	int ans = 0;
	__gnu_pbds::priority_queue<int> q;
	for(int i = 0, j = 0; i < m; ++i) {
		for(; a[j].t <= i + 1 && j < n; ++j)
			q.push(a[j].w);
		if(!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}
	cout << ans << endl;
	return 0;
}
