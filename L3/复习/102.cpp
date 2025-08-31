#include <iostream>
using namespace std;

int f[23];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	f[0] = f[1] = 1;
	for(int i = 2; i <= n; ++i)
		f[i] = f[i - 1] + f[i - 2];
	cout << f[n] << endl;
	return 0;
}