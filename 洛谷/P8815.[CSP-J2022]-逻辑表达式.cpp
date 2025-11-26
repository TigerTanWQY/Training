#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1e6 + 3;
char s[N];
int a1[N], a2[N], d1[N], d2[N], c1, c2;

bool dfs(int L, int R) {
	if(d1[R] >= L) {
		int res = dfs(L, d1[R]-1);
		if(res == 1) {
			++c1;
			return 1;
		}
		return res | dfs(d1[R]+1, R);
	} else if(d2[R] >= L) {
		int res = dfs(L, d2[R]-1);
		if(res == 0) {
			++c2;
			return 0;
		}
		return res & dfs(d2[R]+1, R);
	} else if(s[L] == '(' && s[R] == ')')
		return dfs(L+1, R-1);
	else
		return s[L] - '0';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> s;
	int n = strlen(s);
	for(int i = n; i; --i)
		swap(s[i], s[i-1]);
	for(int i = 1, x = 0; i <= n; ++i) {
		if(s[i] == '(')
			++x;
		else if(s[i] == ')')
			--x;
		else if(s[i] == '|')
			a1[x] = i;
		else if(s[i] == '&')
			a2[x] = i;
		d1[i] = a1[x];
		d2[i] = a2[x];
	}
	int res = dfs(1, n);
	cout << res << '\n' << c2 << ' ' << c1 << endl;
	return 0;
}
