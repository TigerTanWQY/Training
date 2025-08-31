#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _q;
	cin >> _q;
	queue<int> q;
	for(int op, x; _q--; ) {
		cin >> op;
		if(op == 1) {
			cin >> x;
			q.push(x);
		} else {
			cout << q.front() << '\n';
			q.pop();
		}
	}
	cout.flush(); return 0;
}
