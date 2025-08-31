#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100003;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int k; q--; cout << '\n') {
		cin >> k;
		auto cit = lower_bound(a + 1, a + n + 1, k);
		if(*cit != k)
			cout << "-1 -1";
		else
			cout << cit - a - 1 << ' ' << upper_bound(a + 1, a + n + 1, k) - a - 2;
	}
	return 0;
}