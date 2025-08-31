#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define _L first
#define _R second

constexpr const int N = 1e6 + 3;
pair<int, int> T[N];
int w[N], sz[N];

void get_sz(const int u) {
	sz[u] = 1;
	if(~T[u]._L) {
		get_sz(T[u]._L);
		sz[u] += sz[T[u]._L];
	}
	if(~T[u]._R) {
		get_sz(T[u]._R);
		sz[u] += sz[T[u]._R];
	}
}

bool check(const int u, const int v) {
	if(!~u || !~v)
		return u == v;
	else if(w[u] != w[v])
		return false;
	else
		return check(T[u]._L, T[v]._R) && check(T[v]._L, T[u]._R);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> w[i];
	for(int i = 1; i <= n; ++i)
		cin >> T[i]._L >> T[i]._R;
	get_sz(1);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(check(T[i]._L, T[i]._R))
			ans = max(ans, sz[i]);
	cout << ans << endl;
	return 0;
}