#include <iostream>
#include <functional>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int id, n; _T--; ) {
		cin >> id >> n;
		cout << id << ' ' << (n + 1) / 2 << '\n';
		__gnu_pbds::priority_queue<int> q1;            // 小根
		__gnu_pbds::priority_queue<int, greater<>> q2; // 大根
		for(int i = 1, x, cnt = 0; i <= n; ++i) {
			cin >> x;
			if(q1.empty())
				q1.push(x);
			else {
				if(x < q1.top())
					q1.push(x);
				else
					q2.push(x);
				while(q1.size() < q2.size()) {
					q1.push(q2.top());
					q2.pop();
				}
				while(q1.size() > q2.size() + 1) {
					q2.push(q1.top());
					q1.pop();
				}
			}
			if(i & 1) {
				++cnt;
				cout << q1.top() << ' ';
				if(cnt % 10 == 0)
					cout << '\n';
			}
		}
		if((n + 1) / 2 % 10 != 0)
			cout << '\n';
	}
	cout.flush();
	return 0;
}