#include <iostream>
using namespace std;
// When your dreams come alive, you're unstoppable.
long long f[11];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	f[0] = f[1] = 1;
	for(int i = 2; i < 11; ++i)
		f[i] = f[i-1] * i;
	int n, k;
	cin >> n >> k;
	if(n < k)
		cout.put('0');
	else
		cout << f[k] * (f[n] / f[k] / f[n-k]) * (f[n] / f[k] / f[n-k]);
	cout << endl; return 0;
}
