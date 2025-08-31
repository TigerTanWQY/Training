#include <iostream>
#include <cstring>
using namespace std;

constexpr const int P = 10000, N = 1e6 + 3;
char s[N];
int f[N], g[N];

int dfs(const int L, const int R) {
	if(f[R] >= L)
		return (dfs(L, f[R] - 1) + dfs(f[R] + 1, R)) % P;
	else if(g[R] >= L)
		return dfs(L, g[R] - 1) * dfs(g[R] + 1, R) % P;
	int x = 0;
	for(int i = L; i <= R; ++i)
		x = x * 10 + s[i] - '0';
	return x % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (s + 1);
	const int n = strlen(s + 1);
	for(int i = 1; i <= n; ++i) {
		f[i] = f[i - 1];
		g[i] = g[i - 1];
		if(s[i] == '+')
			f[i] = i;
		else if(s[i] == '*')
			g[i] = i;
	}
	cout << dfs(1, n) << endl;
	return 0;
}