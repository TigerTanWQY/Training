#include <iostream>
#include <bitset>
using namespace std;

const int N = 1003;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	bitset<N> a;
	for(int x; q--; ) {
		cin >> x;
		a[x] = !a[x];
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(!a[i])
			++ans;
	cout << ans;
	return 0;
}