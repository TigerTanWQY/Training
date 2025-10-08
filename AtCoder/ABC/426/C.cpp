#include <bits/stdc++.h>
using namespace std;

long long cnt[1000003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cnt[i] = 1;
	set<int> st;
	for(int i = 1; i <= n; ++i)
		st.insert(i);
	for(int x, y; m--; cout.put('\n')) {
		cin >> x >> y;
		long long ans = 0;
		for(auto it = st.cbegin(); it != st.cend() && *it <= x; ) {
			int w = *it;
			if(w != y) {
				ans += cnt[w];
				cnt[y] += cnt[w];
				cnt[w] = 0;
				it = st.erase(it);
			} else
				++it;
		}
		if(cnt[y])
			st.insert(y);
		cout << ans;
	}
	cout.flush(); return 0;
}
