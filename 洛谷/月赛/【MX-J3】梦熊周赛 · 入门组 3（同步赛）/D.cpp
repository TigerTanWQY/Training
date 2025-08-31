#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
using tpIII = tuple<int, int, int>;

constexpr const int N = 2'003, M = 50'003;
tpIII a[M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		a[i] = {u, v, w};
	}
	sort(a + 1, a + m + 1);
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			for(int k = j + 1; k <= n; ++k)
				for(int L = k + 1; L <= n; ++L) {
					auto cit1 = lower_bound(a + 1, a + m + 1, tpIII{i, j, k}),
						cit2 = lower_bound(a + 1, a + m + 1, tpIII{i, j, L}),
						cit3 = lower_bound(a + 1, a + m + 1, tpIII{i, k, L}),
						cit4 = lower_bound(a + 1, a + m + 1, tpIII{j, k, L});
					if(cit1 != a + m + 1 && *cit1 == tpIII{i, j, k} &&
							cit2 != a + m + 1 && *cit2 == tpIII{i, j, L} &&
							cit3 != a + m + 1 && *cit3 == tpIII{i, k, L} &&
							cit4 != a + m + 1 && *cit4 == tpIII{j, k, L})
						++ans;
				}
	cout << ans << endl;
	return 0;
}