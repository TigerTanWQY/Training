#include <iostream>
#include <queue>
using namespace std;

queue<int> q[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int id, op, x; m--; ) {
		cin >> id >> op;
		if(op == 1) {
			cin >> x;
			q[id].push(x);
		} else {
			if(q[id].empty())
				cout << "error";
			else {
				cout << q[id].front();
				q[id].pop();
			}
			cout.put('\n');
		}
	}
	cout.flush();
	return 0;
}