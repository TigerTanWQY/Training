#include <cstdio>
#include <set>
using namespace std;

set<int, greater<int>> S;
int a[27];

int pow(const int &base, const int &x)
{
	if(a[x])
		return a[x];
	return a[x] = base * pow(base, x - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	if(n & 1)
	{
		printf("-1");
		return 0;
	}
	for(int i = 1; n; ++i, n >>= 1)
		if(n & 1)
			S.insert(i);
	a[1] = 1;
	pow(2, *S.cbegin());
	for(const auto &p: S)
		printf("%d ", a[p]);
	return 0;
}