#include <iostream>
#include <vector>
using namespace std;

const int N = 1'003;
int a[N], fa[N], sz[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int n, rt; cin >> n >> rt && (n || rt); cout << '\n') {
		long long ans = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			ans += a[i];
			sz[i] = 1;
		}
		for(int _ = 1, u, v; _ < n; ++_) {
			cin >> u >> v;
			fa[v] = u;
		}
		for(int _ = 1; _ < n; ++_) {
			int u = 0;
			for(int i = 1; i <= n; ++i)
				if((i != rt) && (u == 0 || a[u] * sz[i] < a[i] * sz[u]))
					u = i;
			int v = fa[u];
			ans += sz[v] * a[u];
			for(int i = 1; i <= n; ++i)
				if(fa[i] == u)
					fa[i] = v;
			fa[u] = v;
			a[v] += a[u];
			a[u] = 0;
			sz[v] += sz[u];
		}
		cout << ans;
	}
	cout.flush();
	return 0;
}