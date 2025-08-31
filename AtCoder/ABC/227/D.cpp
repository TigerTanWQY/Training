#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

LL a[200003];
int n, k;

bool check(const LL& x) {
	LL tot = 0;
	for(int i = 1; i <= n; ++i)
		tot += min(a[i], x);
	return tot >= x * k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	LL L = 0, R = 1e18 / k;
	for(LL M = (L + R) >> 1; L + 1 < R; M = (L + R) >> 1) {
		if(check(M))
			L = M;
		else
			R = M;
	}
	cout << L;
	return 0;
}