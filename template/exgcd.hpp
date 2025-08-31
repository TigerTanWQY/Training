#ifndef _TIGER_exgcd
# define _TIGER_exgcd 1
#endif // _TIGER_exgcd

namespace tiger {
	using LL = long long;

	template<class _Tp>
	LL exgcd(const LL a, const LL b, _Tp &x, _Tp &y) noexcept {
		if(b == 0) {
			x = 1;
			y = 0;
			return a;
		}
		LL g = exgcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}