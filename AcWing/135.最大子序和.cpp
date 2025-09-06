#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL s[300003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] += s[i - 1];
	}
	LL ans = -1e18;
	deque<LL> q;
	q.push_back(0);
	for(int i = 1; i <= n; ++i) {
		for(; !q.empty() && i - q.front() > m; q.pop_front());
		ans = max(ans, s[i] - s[q.front()]);
		for(; !q.empty() && s[q.back()] >= s[i]; q.pop_back());
		q.push_back(i);
	}
	cout << ans << endl;
	return 0;
}
