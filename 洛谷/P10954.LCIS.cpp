#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 3'003;
int a[N], b[N], f[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	for(int i = 1; i <= n; ++i) {
		int maxn = 1;
		for(int j = 1; j <= n; ++j) {
			f[i][j] = f[i - 1][j];
			if(a[i] == b[j])
				f[i][j] = max(f[i][j], maxn);
			else if(a[i] > b[j])
				maxn = max(maxn, f[i - 1][j] + 1);
		}
	}
	cout << *max_element(f[n], f[n] + n + 1) << endl;
	return 0;
}