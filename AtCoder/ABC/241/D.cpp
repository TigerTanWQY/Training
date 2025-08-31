#include <cstdio>
#include <set>
using namespace std;
using LL = long long;

multiset<LL> s;

int main()
{
	int Q;
	scanf("%d", &Q);
	s.insert(-1);
	while(Q--)
	{
		int op;
		LL x;
		scanf("%d%lld", &op, &x);
		if(op == 1)
			s.insert(x);
		else
		{
			int k;
			scanf("%d", &k);
			if(op == 2)
			{
				auto it = s.upper_bound(x);
				while(k-- && it != s.begin())
					--it;
				if(it == s.begin())
					printf("-1");
				else
					printf("%lld", *it);
				printf("\n");
			}
			else
			{
				auto it = s.lower_bound(x);
				while(k-- > 1 && it != s.end())
					++it;
				if(it == s.end())
					printf("-1");
				else
					printf("%lld", *it);
				printf("\n");
			}
		}
	}
	return 0;
}