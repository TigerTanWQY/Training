#include <iostream>
using namespace std;

const int MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n;
	cin >> n;
	n %= MOD;
	if(n < 0)
		n += MOD;
	cout << n;
	return 0;
}
