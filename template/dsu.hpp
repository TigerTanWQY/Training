#ifndef _TIGER_DSU
# define _TIGER_DSU 1
#endif // _TIGER_DSU
#include <vector>

namespace tiger {
	using namespace std;
	class Dsu {
	private:
		size_t n;
		vector<int> fa;
	public:
		void init(void) noexcept {
			for(size_t i = 0; i <= n; ++i)
				fa[i] = i;
		}

		Dsu(const size_t _n = -1) noexcept
		: n(_n), fa(vector<int>(_n + 1))
		{ init(); }

		void resize(const size_t _n) noexcept {
			n = _n;
			init();
		}

		int fnd(const int x) noexcept {
			if(fa[x] != x)
				fa[x] = fnd(fa[x]);
			return fa[x];
		}

		void mrge(int x, int y) {
			x = fnd(x); y = fnd(y);
			if(x == y)
				return;
			fa[y] = x;
		}

		bool same(const int x, const int y)
		{ return fnd(x) == fnd(y); }
	} dsu;
}