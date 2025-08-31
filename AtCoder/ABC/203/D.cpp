#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 803;
int a[N][N], s[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> a[i][j];
	auto chk = [&n, &k](const int M) {
		s[0][0] = s[0][1] = s[1][0] = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + (a[i][j] > M);
		for(int i = 0; i <= n - k; ++i)
			for(int j = 0; j <= n - k; ++j)
				if(s[i + k][j + k] + s[i][j] - s[i][j + k] - s[i + k][j] <= k * k / 2)
					return false;
		return true;
	};
	int R = 1e9 + 1;
	for(int L = -1, M; L + 1 < R; ) {
		M = (L + R) >> 1;
		if(chk(M))
			L = M;
		else
			R = M;
	}
	cout << R << endl;
	return 0;
}
