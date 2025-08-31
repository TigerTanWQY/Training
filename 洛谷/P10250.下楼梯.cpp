#include <iostream>
using namespace std;

constexpr const int N = 63;
long long f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	f[1] = 1;
	f[2] = 2;
	f[3] = 4;
	for(int i = 4; i <= n; ++i)
		f[i] = f[i - 1] + f[i - 2] + f[i - 3];
	cout << f[n] << endl;
	return 0;
}