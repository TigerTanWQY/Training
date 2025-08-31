#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	stack<int> a;
	for(int op, x; q--; ) {
		cin >> op >> x;
		if(op == 1)
			a.push(x);
		else {
			int ans = 0;
			for(; !a.empty() && a.top() != x; a.pop())
				++ans;
			if(!a.empty()) {
				a.pop();
				++ans;
			}
			cout << ans << '\n';
		}
	}
	cout.flush();
	return 0;
}