#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int V, n;
	cin >> V >> n;
	multiset<int> st;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		st.insert(x);
	}
	int ans = 0;
	while(!st.empty()) {
		auto now = st.cbegin();
		int x = *now;
		st.erase(now);
		auto fnd = st.upper_bound(V - x);
		if(fnd != st.cbegin())
			st.erase(--fnd);
		++ans;
	}
	cout << ans << endl;
	return 0;
}