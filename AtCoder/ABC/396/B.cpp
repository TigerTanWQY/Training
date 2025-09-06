#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _q;
	cin >> _q;
	stack<int> stk;
	for(int _ = 100; _--; )
		stk.push(0);
	for(int op, x; _q--; ) {
		cin >> op;
		if(op == 1) {
			cin >> x;
			stk.push(x);
		} else {
			cout << stk.top() << '\n';
			stk.pop();
		}
	}
	cout.flush();
	return 0;
}
