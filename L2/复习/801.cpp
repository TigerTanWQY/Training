#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	stack<int> stk;
	for(string op; q--; ) {
		cin >> op;
		if(op == "push") {
			int x;
			cin >> x;
			stk.push(x);
		} else if(op == "pop")
			stk.pop();
		else
			cout << stk.top() << '\n';
	}
	cout.flush();
	return 0;
}