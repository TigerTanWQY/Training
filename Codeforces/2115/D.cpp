#include <bits/stdc++.h>
using namespace std;
using U = unsigned;
using ULL = unsigned long long;

constexpr const int N = 1e5 + 3;
char s[N];
ULL a[N], b[N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	U _T;
	cin >> _T;
	for(U n; _T--; cout.put('\n')) {
		cin >> n;
		for(U i = 0; i < n; ++i)
			cin >> a[i];
		for(U i = 0; i < n; ++i)
			cin >> b[i];
		cin >> s;
		ULL ans = 0;
		for(U i = 0; i < n; ++i) {
			a[i] ^= b[i];
			ans ^= b[i];
		}
		for(U j = 59; ~j; --j) {
			ULL x = 0, y = 0;
			for(U i = n - 1; ~i; --i)
				if(a[i] >> j & 1)
					a[i] ^= (x? x: (y = s[i], x = a[i]));
			ans ^= ((ans >> j & 1) ^ (y - '0')) * x;
		}
		cout << ans;
	}
	cout.flush(); return 0;
}
