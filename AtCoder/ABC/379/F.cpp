#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<pair<int, int>> qs[N];
int a[N], ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0, L, R; i < q; ++i) {
		cin >> L >> R;
		qs[L - 1].push_back({R, i});
	}
	vector<int> st;
	for(int i = n; i--; ) {
		for(const auto& [R, qi]: qs[i]) {
			int bL = -1, bR = st.size();
			while(bL + 1 < bR) {
				int M = (bL + bR) >> 1;
				if(st[M] >= R)
					bL = M;
				else
					bR = M;
			}
			ans[qi] = bL + 1;
		}
		while(!st.empty() && a[st.back()] < a[i])
			st.pop_back();
		st.push_back(i);
	}
	for(int i = 0; i < q; ++i)
		cout << ans[i] << '\n';
	cout.flush();
	return 0;
}