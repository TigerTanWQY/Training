#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using PII = pair<int, int>;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	stack<PII> a;
	for(int op; q--; ) {
		cin >> op;
		if(op == 1) {
			PII x;
			cin >> x.first >> x.second;
			a.push(x);
		} else {
			if(a.empty())
				cout << "error";
			else {
				cout << a.top().first << ' ' << a.top().second;
				a.pop();
			}
			cout.put('\n');
		}
	}
	cout.flush();
	return 0;
}