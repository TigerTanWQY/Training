#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 503;
char s[N];
int f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> (s + 1);
	for(int len = 2; len <= n; ++len)
		for(int L = 1; L + len - 1 <= n; ++L) {
			int R = L + len - 1;
			if((s[L] == '(' && s[R] == ')') || (s[L] == '[' && s[R] == ']'))
				f[L][R] = max(f[L][R], f[L + 1][R - 1] + 2);
			for(int i = L; i < R; ++i)
				f[L][R] = max(f[L][R], f[L][i] + f[i + 1][R]);
		}
	cout << f[1][n] << endl;
	return 0;
}