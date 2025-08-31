#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 5e5 + 3;
bitset<N> vis;
int a[N];

int main() {
	freopen("star.in", "r", stdin);
	freopen("star.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int op, x; q--; ) {
		cin >> op >> x;
		if(op == 1)
			swap(a[x], a[x + 1]);
		else {
			int ans = n;
			for(int L = 1; L + x - 1 <= n; ++L)
				for(int R = L + x - 1; R <= n; ++R) {
					vis.reset();
					for(int i = L; i <= R; ++i)
						vis[a[i]] = true;
					for(int i = 0; i <= n; ++i)
						if(!vis[i]) {
							ans = min(ans, i);
							break;
						}
				}
			cout << ans << '\n';
		}
	}
	cout.flush(); return 0;
}
