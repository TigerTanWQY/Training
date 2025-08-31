#include <iostream>
using namespace std;

const int P = 998244353;
int a[200003];
long long s[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	long long ans = 0;
	for(int i = n; i; --i) {
		ans = (ans + (s[i + 1] + i - 1 + P) % P * a[i] % P) % P;
		long long k = 1;
		for(; a[i]; a[i] /= 10)
			k *= 10;
		s[i] = (s[i + 1] + k) % P;
	}
	cout << ans;
	return 0;
}