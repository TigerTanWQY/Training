#include <iostream>
using namespace std;

const int P = 722733748;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k, a, q, ans = 1;
	cin >> k >> a >> q;
	for(int x = a; k--; x = 1LL * x * q % P)
		ans = ans * 1LL * x % P;
	cout << ans;
	return 0;
}