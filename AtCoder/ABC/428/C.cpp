#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _q;
	cin >> _q;
	stack<pair<int, int>> st;
	st.push({0, 0});
	for(int op; _q--; cout.put('\n')) {
		cin >> op;
		if(op == 1) {
			char c;
			cin >> c;
			auto [b, mn] = st.top();
			int nb = b + (c == '('? 1: -1),
				nmn = min(mn, nb);
			st.push({nb, nmn});
			cout << (nb == 0 && nmn >= 0? "Yes": "No");
		} else {
			st.pop();
			auto [b, mn] = st.top();
			cout << (b == 0 && mn >= 0? "Yes": "No");
		}
	}
	cout.flush(); return 0;
}
