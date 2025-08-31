#include <iostream>
#include <algorithm>
using namespace std;

const int N = 103;
int t[N], f[2][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> t[i];
	for(int i = 1; i <= n; ++i) {
		f[0][i] = 1;
		for(int j = 1; j < i; ++j)
			if(t[j] < t[i])
				f[0][i] = max(f[0][i], f[0][j] + 1);
	}
	for(int i = n; i; --i) {
		f[1][i] = 1;
		for(int j = n; j > i; --j)
			if(t[j] < t[i])
				f[1][i] = max(f[1][i], f[1][j] + 1);
	}
	for(int i = 1; i <= n; ++i)
		ans = max(ans, f[0][i] + f[1][i] - 1);
	cout << n - ans;
	cout.flush();
	return 0;
}