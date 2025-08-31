#include <iostream>
#include <algorithm>
using namespace std;

int a[103], f[10003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; ++i)
		cin >> a[i];
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j < k; ++j)
			if(a[j] <= i)
				f[i] = max(f[i], i - f[i - a[j]]);
	cout << f[n] << endl;
	return 0;
}