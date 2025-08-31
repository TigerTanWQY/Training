#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int ans = 0;
	deque<pair<int, int>> q;
	for(int op, x, t; n--; ) {
		cin >> op >> x >> t;
		if(op) { // bus
			while(!q.empty()) // 清理过期票
				if(t - q.front().second > 45)
					q.pop_front();
				else
					break;
			bool flag = true;
			for(int i = 0; flag && i < q.size(); ++i) // 查找
				if(q[i].first >= x) {
					q.erase(q.cbegin() + i);
					flag = false;
				}
			if(flag)
				ans += x;
		} else { // metro
			ans += x;
			q.push_back({x, t});
		}
	}
	cout << ans << endl;
	return 0;
}