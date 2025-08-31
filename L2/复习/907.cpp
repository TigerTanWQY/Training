#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> m;
	queue<int> q;
	for(int op, x; m--; ) {
		cin >> op >> x;
		if(op == 1)
			q.push(x);
		else {
			int ans = 0;
			for(; !q.empty() && q.front() != x; q.pop())
				++ans;
			if(!q.empty()) {
				q.pop();
				++ans;
			}
			cout << ans << '\n';
		}
	}
	cout.flush();
	return 0;
}