#include <cstdio>
#include <set>
using namespace std;

multiset<int> s;

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		s.insert(x);
	}
	while(s.size() > 1)
	{
		int x = *s.cbegin();
		s.erase(s.cbegin());
		int y = *s.cbegin();
		s.erase(s.cbegin());
		s.insert(x + y);
		ans += x + y;
	}
	printf("%d", ans);
	return 0;
}