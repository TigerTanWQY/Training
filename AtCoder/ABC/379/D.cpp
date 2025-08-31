#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	vector<LL> st;
	LL t = 0;
	for(int op, k; q--; ) {
		cin >> op;
		if(op == 1)
			st.push_back(t);
		else if(op == 2) {
			cin >> k;
			t += k;
		} else {
			cin >> k;
			auto cit = upper_bound(st.cbegin(), st.cend(), t - k);
			cout << cit - st.cbegin();
			st.erase(st.cbegin(), cit);
			cout.put('\n');
		}
	}
	cout.flush();
	return 0;
}