#include <iostream>
#include <string>
using namespace std;

int stk[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	int top = 0;
	for(string op; q--; ) {
		cin >> op;
		if(op == "push") {
			int x;
			cin >> x;
			stk[++top] = x;
		} else if(op == "pop")
			--top;
		else {
			int k;
			cin >> k;
			cout << stk[top - k + 1] << '\n';
		}
	}
	cout.flush();
	return 0;
}