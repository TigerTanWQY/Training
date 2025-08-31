#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> a[103];
bool b[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].second;
	sort(a + 1, a + n + 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
	long long ans = 0;
	for(int t = 0; t <= 4000000; ++t) {
		for(int i = 1; i <= n; ++i)
			if(!b[i] && t >= a[i].first) {
				q.push({a[i].second, i});
				b[i] = true;
			}
		if(q.empty())
			continue;
		int d = q.top().first, i = q.top().second;
		q.pop();
		if(!--d)
			ans += t + 1;
		else
			q.push({d, i});
	}
	cout << ans;
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}