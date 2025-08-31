#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(long long n, d, e; _T--; cout.put('\n')) {
		cin >> n >> d >> e;
		const long long y = n - e * d + 2, x = sqrt(y * y - n * 4), p = (x + y) / 2, q = y - p;
		if(p * q == n && e * d == (p - 1) * (q - 1) + 1 && p && q)
			cout << min(p, q) << ' ' << max(p, q);
		else
			cout << "NO";
	}
	return 0;
}