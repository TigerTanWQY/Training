#include <iostream>
#include <cstring>
using namespace std;

constexpr const int N = 503;
int s[N], f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		f[i][i] = 0;
		s[i] += s[i - 1];
	}
	for(int len = 2; len <= n; ++len)
		for(int L = 1; L + len - 1 <= n; ++L) {
			int R = L + len - 1;
			for(int i = L; i < R; ++i)
				f[L][R] = min(f[L][R], f[L][i] + f[i + 1][R]);
			f[L][R] += s[R] - s[L - 1];
		}
	cout << f[1][n] << endl;
	return 0;
}