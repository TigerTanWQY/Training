#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 1e9 + 7;
int f[1003][(1<<10)+3], n, m;

void gen(int S, int i, int T, vector<int>& c) {
	if(i == n + 1) {
		c.push_back(T);
		return;
	}
	if(S >> i & 1)
		gen(S, i + 1, T, c);
	if(i != n && !(S >> i & 1) && !(S >> (i+1) & 1))
		gen(S, i + 2, T, c);
	if(!(S >> i & 1))
		gen(S, i + 1, T + (1 << i), c);
}

int solve(int x, int S) {
	if(x == m + 1)
		return !S;
	if(~f[x][S])
		return f[x][S];
	int res = 0;
	vector<int> T;
	gen(S, 1, 0, T);
	for(const auto& t: T)
		res = (res + solve(x + 1, t) % P) % P;
	return f[x][S] = res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	memset(f, -1, sizeof f);
	cout << solve(1, 0) << endl;
	return 0;
}
