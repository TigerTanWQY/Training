#include <iostream>
#include <queue>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<LL, vector<LL>, greater<LL>> q;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		q.push(x);
	}
	LL ans = 0;
	while(q.size() > 1) {
		LL x = q.top();
		q.pop();
		LL y = q.top();
		q.pop();
		ans += x + y;
		q.push(x + y);
	}
	cout << ans;
	return 0;
}