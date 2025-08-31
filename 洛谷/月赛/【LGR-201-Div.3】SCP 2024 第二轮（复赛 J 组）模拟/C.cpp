#include <iostream>
#include <string>
using namespace std;

constexpr const int N = 1.3e6 + 3;
string s;
int f[N][3], g[N], X;

int dfs(const int L, const int R) {
	if(s[L] == 'x') {
//		int x = 0, y = 0, z = 0;
//		for(int i = L + 2; !y && i <= R; ++i)
//			if(s[i] == '?')
//				y = i;
//		for(int i = L + 2; !z && i <= R; ++i)
//			if(s[i] == '?')
//				++x;
//			else if(s[i] == ':') {
//				--x;
//				if(x == 0)
//					z = i;
//			}
		const int y = f[L][0], z = f[L][1];
		if(s[L + 1] == '<')
			if(X < stoi(s.substr(L + 2, y - L - 2)))
				return dfs(y + 1, z - 1);
			else
				return dfs(z + 1, R);
		else
			if(X > stoi(s.substr(L + 2, y - L - 2)))
				return dfs(y + 1, z - 1);
			else
				return dfs(z + 1, R);
	} else
		return stoi(s.substr(L, R - L + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q >> s;
	n = s.size();
	for(int i = n - 1, x = 0; i >= 0; --i) {
		f[i][0] = f[i + 1][0]; f[i][1] = f[i + 1][1];
		if(s[i] == '?') {
			f[i][0] = i;
			++x;
		} else if(s[i] == ':') {
			--x;
			g[x] = i;
		}
		f[i][1] = g[x];
	}
	for(; q--; cout.put('\n')) {
		cin >> X;
		cout << dfs(0, n - 1);
	}
	cout.flush();
	return 0;
}