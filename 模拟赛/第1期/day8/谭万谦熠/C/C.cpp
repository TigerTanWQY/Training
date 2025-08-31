#include <cstdio>
#include <set>
using namespace std;

set<pair<int, int>> s;
bool r[500003], c[500003];

int main()
{
	int n, m, q, cntr = 0, cntc = 0;
	scanf("%d%d%d", &n, &m, &q);
	while(q--)
	{
		char op;
		scanf("%*c%c", &op);
		switch(op)
		{
			case 'r':
			{
				int x;
				scanf("%d", &x);
				r[x] = !r[x];
				if(r[x])
					++cntr;
				else
					--cntr;
				break;
			}
			case 'c':
			{
				int y;
				scanf("%d", &y);
				c[y] = !c[y];
				if(c[y])
					++cntc;
				else
					--cntc;
				break;
			}
			case 's':
			{
				int x, y;
				scanf("%d%d", &x, &y);
				if(s.find(make_pair(x, y)) != s.cend())
					s.erase(make_pair(x, y));
				else
					s.insert(make_pair(x, y));
				break;
			}
		}
	}
	long long ans = 1LL * cntr * m + 1LL * cntc * n - 2LL * cntr * cntc;
	for(const auto &p: s)
		if(!(r[p.first] ^ c[p.second]))
			++ans;
		else
			--ans;
	printf("%lld", ans);
	return 0;
}