#include <iostream>
using namespace std;

int q[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> m;
	int f = 1, r = 0;
	for(string op; m--; ) {
		cin >> op;
		if(op == "push") {
			int x;
			cin >> x;
			q[++r] = x;
		} else if(op == "pop")
			++f;
		else {
			int k;
			cin >> k;
			cout << q[f + k - 1] << '\n';
		}
	}
	cout.flush();
	return 0;
}