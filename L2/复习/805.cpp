#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int, vector<int>> a[103];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int id, op, x; q--; ) {
		cin >> id >> op;
		if(op == 1) {
			cin >> x;
			a[id].push(x);
		} else {
			if(a[id].empty())
				cout << "error";
			else {
				cout << a[id].top();
				a[id].pop();
			}
			cout.put('\n');
		}
	}
	cout.flush();
	return 0;
}