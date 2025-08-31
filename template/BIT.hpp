#ifndef __TIGER_BIT_HPP
# define __TIGER_BIT_HPP
#endif // __TIGER_BIT_HPP
#include <cassert>
#include <array>
using LL = long long;

namespace tiger {
	template<typename _Tp, size_t n = 1'000'003>
	class BIT {
	private:
		array<_Tp, n + 1> c{};
		int lowbit(const int x)
		{ return x & -x; }
	public:
		void resize(const int m) {
			c.resize(m);
			c.fill({});
		}
		_Tp query(int x) {
			assert(x > 0 && x <= n);
			_Tp res = 0;
			for(; x; x -= lowbit(x))
				res += c[x];
			return res;
		}
		void modify(int x, const _Tp w) {
			assert(x > 0); //!
			for(; x <= n; x += lowbit(x))
				c[x] += w;
		}
	};
}