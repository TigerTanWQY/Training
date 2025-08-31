#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 1e5 + 3;
unsigned a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		LL k;
		cin >> n >> k;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		for(int p = 0, x, y; p < 32; ++p) {
			x = y = 0;
			for(int i = 1; i <= n; ++i)
				a[i] >> p & 1? ++x: ++y;
			if(n & 1)
				for(int i = 1; i <= n; ++i)
					a[i] ^= (x & 1) << p;
			else if(x & 1)
				for(int i = 1; i <= n; ++i)
					a[i] ^= (k & 1) << p;
		}
		for(int i = 1; i <= n; ++i)
			cout << a[i] << ' ';
	}
	cout.flush();
	return 0;
}