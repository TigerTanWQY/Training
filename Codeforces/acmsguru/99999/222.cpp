#include <iostream>
using namespace std;

constexpr const int N = 10 + 1;
long long f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	f[0] = f[1] = 1;
	for(int i = 2; i < N; ++i)
		f[i] = f[i - 1] * i;
	int n, k;
	cin >> n >> k;
	if(n < k)
		cout << '0';
	else
		cout << f[k] * (f[n] / f[k] / f[n - k]) * (f[n] / f[k] / f[n - k]);
	cout.flush();
	return 0;
}