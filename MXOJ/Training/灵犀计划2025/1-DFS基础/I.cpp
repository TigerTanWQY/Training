#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(m);
	for(int i = 0; i < m; ++i) {
		int c;
		cin >> c;
		a[i].resize(c);
		for(auto& x: a[i])
			cin >> x;
	}
	int ans = 0;
	for(int S = 0; S < (1 << m); ++S) {
		unordered_set<int> st;
		for(int i = 0; i < m; ++i)
			if((S >> i) & 1)
				for(auto& x: a[i])
					st.insert(x);
		ans += (int)st.size() == n;
	}
	cout << ans << endl;
	return 0;
}
