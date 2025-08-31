#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;

const int N = 200003;
int a[3][N];
LL f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i)
		cin >> a[0][i] >> a[1][i] >> a[2][i];
	memset(f, 0x3f, sizeof(f));
	f[1] = 0;
	for(int i = 1, e; i <= k; ++i) {
		cin >> e;
		f[a[1][e]] = min(f[a[1][e]], f[a[0][e]] + a[2][e]);
	}
	if(f[n] != 0x3f3f3f3f3f3f3f3f)
		cout << f[n];
	else
		cout << -1;
	return 0;
}
