#include <bits/stdc++.h>
using namespace std;

int cnt[500003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	set<pair<int, int>> st;
	for(int i = 0; i < n; ++i) {
		st.insert({i, i});
		cnt[i] = 1;
	}
	st.insert({-1, 2e9});
	st.insert({n, 2e9});
	for(int op, x, c; q--; ) {
		cin >> op;
		if(op == 1) {
			cin >> x >> c;
			--x; --c;
			auto cit = st.lower_bound({x, 2e9});
			auto [R, Rc] = *cit;
			auto [L, Mc] = *--cit;
			auto [_, Lc] = *--cit;
			cnt[Mc] -= R - L;
			cnt[c] += R - L;
			cit = st.erase(++cit);
			if(c == Rc)
				cit = st.erase(cit);
			if(c != Lc)
				st.insert({L, c});
		} else {
			cin >> c;
			cout << cnt[--c] << '\n';
		}
	}
	cout.flush();
	return 0;
}
