#include <cstdio>
#include <bitset>
using namespace std;

bitset<500003> f{true};

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while(n--)
	{
		int k, a;
		scanf("%d%d", &k, &a);
		for(int i = 1; a >= i; i *= 2)
		{
			f |= f << i * k;
			a -= i;
		}
		if(a * k)
			f |= f << a * k;
	}
	while(m--)
	{
		int k;
		scanf("%d", &k);
		printf(f[k]? "Yes\n": "No\n");
	}
	return 0;
}