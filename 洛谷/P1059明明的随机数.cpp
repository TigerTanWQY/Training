#include <cstdio>
#include <set>
using namespace std;

set<int> s;

int main()
{
	int n;
	scanf("%d", &n);
	for(int x; n--; )
	{
		scanf("%d", &x);
		s.insert(x);
	}
	printf("%llu\n", s.size());
	for(const auto &p: s)
		printf("%d ", p);
	return 0;
}