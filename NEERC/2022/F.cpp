#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 103;
string q[N][N], s;
int f[N][N], n;

int chk(int L, int M, int R) {
	int len1 = M - L + 1, len2 = R - L + 1;
	if(len2 % len1)
		return -1;
	int res = len2 / len1;
	for(int i = 1; i <= res; ++i) {
		int k = L + (i - 1) * len1;
		for(int j = 0; j < len1; ++j)
			if(s[L + j - 1] != s[k + j - 1])
				return -1;
	}
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> s;
	memset(f, 0x3f, sizeof(f));
	n = s.size();
	for(int i = 1; i <= n; ++i) {
		f[i][i] = 1;
		q[i][i] = s[i - 1];
	}
	for(int len = 2; len <= n; ++len)
		for(int L = 1; L <= n - len + 1; ++L) {
			int R = L + len - 1;
			f[L][R] = len;
			q[L][R] = s.substr(L - 1, len);
			for(int k = L; k < R; ++k) {
				if(f[L][k] + f[k+ 1][R] < f[L][R]) {
					f[L][R] = f[L][k] + f[k + 1][R];
					q[L][R] = q[L][k] + q[k + 1][R];
				}
				int res = chk(L, k, R);
				if(res != -1) {
					int y = res, cnt = 0;
					for(; y; y /= 10)
						++cnt;
					if(cnt + 2 + f[L][k] < f[L][R]) {
						f[L][R] = cnt + 2 + f[L][k];
						stringstream op;
						op << res;
						string pp;
						op >> pp;
						q[L][R] = pp + '(' + q[L][k] + ')';
					}
				}
			}
		}
	cout << q[1][n] << endl;
	return 0;
}
