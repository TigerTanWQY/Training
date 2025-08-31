#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr const int N = 2003;
int a[N];
long long f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(f, -0x3f, sizeof(f));
	f[0] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = m; j; --j)
			f[j] = max(f[j], f[j - 1] + (long long)a[i] * j);
	cout << f[m] << endl;
	return 0;
}