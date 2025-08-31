#include <cstdio>
#include <climits>
#include <vector>
#include <set>
using namespace std;
using ULL = unsigned long long;

set<ULL> s;

bool check(int x)
{
	for(; x; x /= 10)
		if(x % 10 != 1)
			return false;
	return true;
}

int main()
{
	vector<ULL> a;
	for(ULL i = 1; i <= 112222222233ULL; i = i * 10 + 1)
		a.push_back(i);
	for(const auto &x: a)
		for(const auto &y: a)
			for(const auto &z: a)
				s.insert(x + y + z);
	printf("%llu\n", s.size());
	int cnt = 0;
	for(const auto &p: s)
	{
		if(++cnt > 333)
			break;
		printf("%lld", p);
		if(p >= INT_MAX)
			printf("ULL");
		putchar(',');
	}
	printf("\n%llu", ULLONG_MAX);
	return 0;
}
