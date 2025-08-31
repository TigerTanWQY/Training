#include <iostream>
#include <utility>
#include <queue>
using namespace std;
using PII = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> m;
	queue<PII> q;
	for(int op; m--; ) {
		cin >> op;
		if(op == 1) {
			PII x;
			cin >> x.first >> x.second;
			q.push(x);
		} else {
			if(q.empty())
				cout << "error";
			else {
				cout << q.front().first << ' ' << q.front().second;
				q.pop();
			}
			cout.put('\n');
		}
	}
	cout.flush();
	return 0;
}