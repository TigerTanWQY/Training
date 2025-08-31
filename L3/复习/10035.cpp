#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

LL a[200003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	LL k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	LL L = 0, R = 1e12;
	auto chk = [&](const LL& x) {
		LL tot = 0;
		for(int i = 0; i < n; ++i)
			tot += min(x, a[i]);
		return tot <= k;
	};
	while(L + 1 < R) {
		LL M = (L + R) >> 1;
		if(chk(M))
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
	cout << endl;
	return 0;
}