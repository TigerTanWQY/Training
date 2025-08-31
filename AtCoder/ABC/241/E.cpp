#include <cstdio>
using namespace std;
using LL = long long;

const int N = 200003;
int a[N], pre[N];
LL s[N];

int main()
{
	int n, l = 0, r = 0;
	LL k;
	scanf("%d%lld", &n, &k);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		pre[i] = -1;
	}
	pre[0] = 0;
	for(int i = 0; i < n; i++)
	{
		s[i + 1] = s[i] + a[s[i] % n];
		if(pre[s[i + 1] % n] != -1)
		{
			l = pre[s[i + 1] % n];
			r = i + 1;
			break;
		}
		pre[s[i + 1] % n] = i + 1;
	}
	if(k <= l)
		printf("%lld", s[k]);
	else
	{
		int p = r - l, c = (k - l - 1) % p;
		LL x = s[r] - s[l], b = (k - l - 1) / p;
		printf("%lld", s[l + c + 1] + (b * x));
	}
	return 0;
}