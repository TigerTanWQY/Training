#include <iostream>
using namespace std;

char q[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin >> m;
	int f = 1, r = 0;
	for(int op; m--; ) {
		cin >> op;
		if(op == 1) {
			string name;
			cin >> name;
			q[++r] = name.front();
		} else {
			for(int _ = 0; f <= r && _ < 10; ++f, ++_) {
				cout.put(q[f]);
				cout.put(' ');
			}
			cout.put('\n');
		}
	}
	cout.flush();
	return 0;
}