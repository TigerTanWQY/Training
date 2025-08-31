#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	set<int> st;
	for(int op, x; q--; ) {
		cin >> op >> x;
		if(op == 1)
			st.insert(x);
		else if(op == 2)
			st.erase(x);
		else if(op == 3)
			cout << *--st.lower_bound(x) << '\n';
		else if(op == 4)
			cout << *st.upper_bound(x) << '\n';
	}
	cout.flush();
	return 0;
}
