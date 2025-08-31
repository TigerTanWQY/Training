#include <cstdio>
using namespace std;

bool b[1003];
long long f[1003]{1};

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n / 2; ++i)
		if(!b[i])
			for(int j = 2; i * j <= n; ++j)
				b[i * j] = true;
	for(int i = 2; i <= n; ++i)
		if(!b[i])
			for(int j = i; j <= n; ++j)
				f[j] += f[j - i];
	printf("%lld", f[n]);
	return 0;
}