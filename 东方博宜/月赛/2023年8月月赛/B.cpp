#include <cstdio>
#include <cmath>
using namespace std;

inline bool is_prime(const int &x)
{
	if(x < 2)
		return false;
	for(int i = 2; i <= sqrt(x); ++i)
		if(x % i == 0)
			return false;
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		long long n;
		scanf("%lld", &n);
		int x = sqrt(n);
		if(x * x == n && is_prime(x))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}