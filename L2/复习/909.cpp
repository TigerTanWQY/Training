#include <iostream>
using namespace std;

constexpr const int N = 1003;
int q[N];

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
			r = (r + 1) % N;
			q[r] = x;
		} else if(op == "pop")
			f = (f + 1) % N;
		else {
			int k;
			cin >> k;
			cout << q[(f + k - 1) % N] << '\n';
		}
	}
	cout.flush();
	return 0;
}