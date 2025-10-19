#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int dig(LL n) {
	if(n == 0)
		return 1;
	int res = 0;
	for(; n; n /= 10)
		++res;
	return res;
}

LL pow10(int k) {
	LL res = 1;
	while(k--)
		res *= 10;
	return res;
}

LL sqrt_floor(LL n) {
	if(n == 0)
		return 0;
	LL res = sqrtl(n);
	while((res + 1) * (res + 1) <= n)
		++res;
	while(res * res > n)
		--res;
	return res;
}

LL sqrt_ceil(LL n) {
	if(n == 0)
		return 0;
	LL res = sqrtl(n);
	while(res * res < n)
		++res;
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int _T;
	cin >> _T;
	for(LL C, D; _T--; cout.put('\n')) {
		cin >> C >> D;
		LL nmn = C + 1, nmx = C + D, ans = 0;
		int kmn = dig(nmn), kmx = dig(nmx);
		for(int k = kmn; k <= kmx; ++k) {
			LL nlow = max(nmn, pow10(k - 1)),
				nhigh = min(nmx, pow10(k) - 1);
			if(nlow > nhigh)
				continue;
			LL vlow = C * pow10(k) + nlow,
				vhigh = C * pow10(k) + nhigh,
				ylow = sqrt_ceil(vlow),
				yhigh = sqrt_floor(vhigh);
			if(ylow <= yhigh)
				ans += (yhigh - ylow + 1);
		}
		cout << ans;
	}
	cout.flush(); return 0;
}
