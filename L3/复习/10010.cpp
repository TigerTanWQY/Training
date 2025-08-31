#include <iostream>
#include <cstring>
#include <set>
using namespace std;

constexpr const int N = 2e5 + 3;
int nxt[N], f[N], ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	memset(nxt, -1, sizeof(nxt));
	memset(f, 0, sizeof(f));
	memset(ans, -1, sizeof(ans));
	set<int> st;
	for(int i = 1, w; i <= n; ++i) {
		cin >> w;
		auto cit = st.upper_bound(w);
		if(cit == st.cend()) {
			f[w] = 1;
			st.insert(w);
		} else {
			nxt[w] = *cit;
			f[w] = f[*cit] + 1;
			st.erase(cit);
			st.insert(w);
		}
		if(f[w] == k) {
			st.erase(w);
			for(int j = 0, x = w; j < k; ++j) {
				ans[x] = i;
				x = nxt[x];
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << '\n';
	cout.flush();
	return 0;
}