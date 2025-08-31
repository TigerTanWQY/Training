#include <iostream>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	__gnu_pbds::priority_queue<int, greater<>> q1;
	__gnu_pbds::priority_queue<int> q2;
	LL tot1 = 0, tot2 = 0, totw = 0;
	for(int i = 1, op, k, w; i <= n; ++i) {
		cin >> op;
		if(op == 1) {
			cin >> k >> w;
			q2.push(k); tot2 += k; totw += w;
			if(q2.size() - 1 > q1.size()) {
				int x = q2.top();
				q1.push(x); q2.pop();
				tot1 += x; tot2 -= x;
			}
			if(!q1.empty() && q2.top() > q1.top()) {
				int x = q2.top(), y = q1.top();
				q1.pop(); q2.pop();
				q1.push(x); q2.push(y);
				tot1 += x - y; tot2 += y - x;
			}
		} else {
			int x = q2.top();
			cout << x << ' ' << ((LL)q2.size() * x) - tot2 + (tot1 - (LL)q1.size() * x) + totw << '\n';
		}
	}
	cout.flush();
	return 0;
}