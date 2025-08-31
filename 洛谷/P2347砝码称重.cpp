#include <cstdio>
#include <bitset>
using namespace std;

const int w[6]{1, 2, 3, 5, 10, 20};
bitset<1001> b{true};

int main()
{
	for(int i = 0, n; i < 6; ++i)
	{
		scanf("%d", &n);
		for(int j = 0; j < n; ++j)
			b |= b << w[i];
	}
	printf("Total=%llu", b.count() - 1);
	return 0;
}