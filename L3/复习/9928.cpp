#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

constexpr const int N = 1e6 + 3;
pair<int, int> a[N], ans;
char s[N];
int c[N], f[N][3];

bool dfs(const int L, const int R) {
	int x = 0, y = 0, z = 0;
	for(int i = L; i <= R; ++i)
		if(s[i] == '(')
			++x;
		else if(s[i] == ')')
			--x;
		else if(!x)
			if(s[i] == '|')
				y = i;
			else if(s[i] == '&')
				z = i;
	if(y) {
		const bool tmp = dfs(L, y - 1);
		if(tmp) {
			++ans.second;
			return true;
		} else
			return tmp | dfs(y + 1, R);
	} else if(z) {
		const bool tmp = dfs(L, z - 1);
		if(tmp)
			return tmp & dfs(z + 1, R);
		else {
			++ans.first;
			return false;
		}
	} else if(s[L] == '(' && s[R] == ')')
		return dfs(L + 1, R - 1);
	else
		return s[L] - '0';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> (s + 1);
	const int n = strlen(s + 1);
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= n; ++i) {
		c[i] += c[i - 1];
		if(s[i] == '(')
			++c[i];
		else if(s[i] == ')')
			--c[i + 1];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < i; ++j)
			if(c[j] == c[i]) {
				f[i][0] = f[j][0];
				f[i][1] = f[j][1];
				break;
			}
		if(s[i] == '&')
			f[i][0] = i;
		else if(s[i] == '|')
			f[i][1] = i;
	}
	cout << dfs(1, n) << '\n' << ans.first << ' ' << ans.second << endl;
	return 0;
}