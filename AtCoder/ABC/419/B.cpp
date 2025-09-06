#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _q;
	cin >> _q;
	__gnu_pbds::priority_queue<int, greater<>> q;
	for(int op, x; _q--; ) {
		cin >> op;
		if(op == 1) {
			cin >> x;
			q.push(x);
		} else {
			cout << q.top() << '\n';
			q.pop();
		}
	}
	cout.flush(); return 0;
}
