#include <iostream>
using namespace std;

constexpr const int N = 1e3 + 3;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	a[n + 1] = 0x3f3f3f3f;
	for(int i = 1; i <= n + 1; ++i) {
		f[i] = 1;
		for(int j = 1; j < i; ++j)
			if(a[i] > a[j] && f[j] + 1 > f[i])
				f[i] = f[j] + 1;
	}
	cout << f[n + 1] - 1 << endl;
	return 0;
}