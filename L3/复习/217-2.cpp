#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<>> s;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		s.push(x);
	}
	int ans = 0;
	while(s.size() > 1) {
		int x = s.top();
		s.pop();
		int y = s.top();
		s.pop();
		s.push(x + y);
		ans += x + y;
	}
	cout << ans;
	return 0;
}