#include <iostream>
using namespace std;

int f[10003];

int main () {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	f[0] = 1;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		for(int j = m; j >= x; --j)
			f[j] += f[j - x];
	}
	cout << f[m] << endl;
	return 0;
}
