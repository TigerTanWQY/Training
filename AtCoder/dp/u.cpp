#include <bits/stdc++.h>
using namespace std;
using U = unsigned;
using LL = long long;

constexpr const int N = 16;
int a[N][N], n;
LL f[1<<N];

LL dfs(U i) {
	if(~f[i])
		return f[i];
	f[i] = 0;
	for(int j = 0; j < n; ++j)
		for(int k = j + 1; k < n; ++k)
			if((i >> j) & 1 && (i >> k) & 1)
				f[i] += a[j][k];
	for(U j = i; j = (j - 1) & i; )
		f[i] = max(f[i], dfs(j) + dfs(j ^ i));
	return f[i];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> a[i][j];
	memset(f, -1, sizeof f);
	cout << dfs((1U << n) - 1) << endl;
	return 0;
}
