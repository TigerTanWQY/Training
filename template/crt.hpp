#ifndef _TIGER_crt
# define _TIGER_crt 1
#endif // _TIGER_crt
#include "exgcd.hpp"

namespace tiger {
	/*
	LL a = 0, b = 1;
	for(int i = 0; i < n; ++i) { // x mod d = c
		int c, d;
		cin >> c >> d;
		mrge(a, b, c, d);
	}
	cout << a;
	*/
	using LL = long long;

	template<class _Tp>
	void mrge(_Tp& a, _Tp& b, const LL c, LL d) {
		if(a == -1 && b == -1)
			return;
		LL x, y, g = exgcd(b, d, x, y);
		if((c - a) % g != 0) {
			a = b = -1;
			return;
		}
		d /= g;
		LL t0 = ((c - a) / g) % d * x % d;
		if(t0 < 0)
			t0 += d;
		a = b * t0 + a;
		b = b * d;
	}
}