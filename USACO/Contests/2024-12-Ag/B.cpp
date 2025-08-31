#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

constexpr const int N = 3e5 + 3;
tuple<int, int, int> lmts[N];
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n, k; _T--; cout.put('\n')) {
		cin >> n >> k;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0, L, R, w; i < k; ++i) {
			cin >> L >> R >> w;
			lmts[i] = {R, L, w};
		}
		if(n > 1000)
			assert(false);
		sort(a, a + n);
		sort(lmts, lmts + k);
		tree<pair<int, int>, null_type, less<pair<int, int>>,
			rb_tree_tag, tree_order_statistics_node_update> T;
		stack<pair<int, int>> stk;
		int id = 0;
		for(const auto& [R, L, w]: lmts) {
			for(; id < n && a[id] <= R; ++id)
				stk.push({a[id], id});
			for(int cur = T.order_of_key({R, 0x3f3f3f3f}) -
				T.order_of_key({L, 0}); cur < w; ++cur) {
				T.insert(stk.top()); stk.pop();
			}
		}
		cout << n - size(T);
	}
	cout.flush();
	return 0;
}
