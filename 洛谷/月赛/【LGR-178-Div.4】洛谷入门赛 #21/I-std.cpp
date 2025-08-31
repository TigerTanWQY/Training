#include <iostream>
using namespace std;

const int N = 7;
const int K = 100;
long long f[N + 3][2][K + 3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	f[0][0][0] = 1;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < 2; ++j)
			for(int s = 0; s <= K; ++s)
				for(int d = 0; d < 10; ++d)
					if(s + d <= K)
						if(!j && d)
							f[i + 1][1][s + d] += f[i][j][s];
						else if(j || (!j && !d))
							f[i + 1][j][s + d] += f[i][j][s];
	int T;
	cin >> T;
	for(int n, k; T--; ) {
		cin >> n >> k;
		long long ans = 0;
		for(int j = 0; j < 2; ++j)
			for(int s = 0; s <= k; ++s)
				ans += f[n][j][s];
		cout << ans - 1 << '\n';
	}
	return 0;
}