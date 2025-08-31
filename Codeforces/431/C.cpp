#include <iostream>
#include <algorithm>
using namespace std;

const int P = 1e9 + 7;
const int N = 103;
int f[2][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, d;
	cin >> n >> k >> d;
	f[0][0] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= min(i, k); ++j) {
			if(j < d)
				f[0][i] = (f[0][i] + f[0][i - j]) % P;
			f[1][i] = (f[1][i] + f[1][i - j]) % P;
			if(j >= d)
				f[1][i] = (f[1][i] + f[0][i - j]) % P;
		}
	cout << f[1][n];
	return 0;
}