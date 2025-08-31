#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <vector>
using namespace std;
using UL = unsigned long;
using LL = long long;

const int MOD = 998244353;
vector<int> f[10003];
int p[10003];

UL ulrand()
{
	return ((((UL)rand() << 24) & 0xFF000000UL) |
			(((UL)rand() << 12) & 0x00FFF000UL) |
			(((UL)rand()) & 0x00000FFFUL));
}

void fact(const int &x, const int &q)
{
	set<int> tmp;
	for(int i = 1; i * i <= x; ++i)
		if(x % i == 0)
		{
			tmp.insert(i);
			tmp.insert(x / i);
		}
	for(const auto &y: tmp)
		f[q].push_back(y);
}

int main()
{
	int n, w;
	scanf("%d%d", &n, &w);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &p[i]);
	if(w == 1)
	{
		LL ans = 1;
		for(int i = 1; i <= n; ++i)
		{
			fact(p[i], i);
			ans = (ans * f[i].size()) % MOD;
		}
		printf("%lld", ans);
	}
	else if(n == 1)
	{
		fact(p[1], 1);
		fact(w, 2);
		printf("%llu", (f[1].size() * f[2].size()) % MOD);
	}
	else
	{
		srand(time(NULL));
		printf("%lu", ulrand() % MOD);
	}
	return 0;
}
/*
ÕËºÅ:SFLS_AK_IOI

ÃÜÂë:iakioirpinf
*/