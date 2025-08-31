#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

int a[100003], n;
LL k;

LL check(LL x) {
	LL res = 0;
	for(int i = 1; i <= n; ++i) {
		res += max(0LL, x - a[i]);
		if(res > k)
			return res;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	LL L = 0, R = 10000100000001LL;
	while(L + 1 < R) {
		LL M = (L + R) >> 1;
		if(check(M) <= k)
			L = M;
		else
			R = M;
	}
	cout << L << endl;
	return 0;
}