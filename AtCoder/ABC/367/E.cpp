#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 200'003, M = 60 + 1;
int p[M][N], a[N], b[N], q[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	LL k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> p[0][i];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int j = 1; j < M; ++j)
		for(int i = 1; i <= n; ++i)
			p[j][i] = p[j - 1][p[j - 1][i]];
	for(int i = 1; i <= n; ++i)
		q[i] = i;
	for(int j = 0; j < M; k >>= 1, ++j)
		if(k & 1)
			for(int i = 1; i <= n; ++i)
				q[i] = p[j][q[i]];
	for(int i = 1; i <= n; ++i)
		cout << a[q[i]] << ' ';
	cout.flush();
	return 0;
}