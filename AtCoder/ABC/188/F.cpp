#include <bits/stdc++.h>
using namespace std;
using LL = long long;

unordered_map<LL, LL> f;

LL dfs(LL x, LL y) {
	if(x >= y)
		return x - y;
	else if(f.count(y))
		return f[y];
	f[y] = y - x;
	if(y & 1)
		f[y] = min({f[y], dfs(x, (y + 1) >> 1) + 2, dfs(x, (y - 1) >> 1) + 2});
	else
		f[y] = min(f[y], dfs(x, y >> 1) + 1);
	return f[y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL x, y;
	cin >> x >> y;
	cout << dfs(x, y) << endl;
	return 0;
}
