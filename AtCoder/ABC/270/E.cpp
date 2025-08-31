#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

int n;
LL a[200003], k;

inline bool func(const LL &m) {
	LL tot = 0;
	for(int i = 0; i < n; ++i)
		tot += min(m, a[i]);
	return tot <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	LL L = 0, R = 1e12 + 2;
	while(L + 1 < R) {
		LL M = L + R >> 1;
		if(func(M))
			L = M;
		else
			R = M;
	}
	for(int i = 0; i < n; ++i) {
		LL x = min(L, a[i]);
		a[i] -= x;
		k -= x;
	}
	for(int i = 0; k; ++i)
		if(a[i]) {
			--a[i];
			--k;
		}
	for(int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	return 0;
}
