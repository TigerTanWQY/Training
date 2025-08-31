#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	set<pair<int, int>> st;
	for(int op, x, y; q--; ) {
		cin >> op >> x >> y;
		if(op == 1)
			st.insert({x, y});
		else if(op == 2)
			st.erase({x, y});
		else {
			if(st.count({x, y}) && st.count({y, x}))
				cout << "Yes";
			else
				cout << "No";
			cout.put('\n');
		}
	}
	cout.flush();
	return 0;
}