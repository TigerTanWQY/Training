#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr const int N = 503;
int a[N];
long long f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i][i + 1] = 0;
	}
	for(int len = 2; len < n; ++len)
		for(int L = 1; L + len <= n; ++L) {
			int R = L + len;
			for(int i = L + 1; i < R; ++i)
				f[L][R] = min(f[L][R], f[L][i] + f[i][R] + (long long)a[L] * a[R] * a[i]);
		}
	if(n == 1)
		cout.put('0');
	else
		cout << f[1][n];
	cout << endl;
	return 0;
}