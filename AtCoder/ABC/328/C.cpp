#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
char s[300003];

int main()
{
	int n, q;
	scanf("%d%d%s", &n, &q, s + 1);
	for(int i = 1; i < n; ++i)
		if(s[i] == s[i + 1])
			a.push_back(i);
	while(q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		auto cit1 = lower_bound(a.cbegin(), a.cend(), l), cit2 = lower_bound(a.cbegin(), a.cend(), r - 1);
		if(cit2 == a.cend() || (*cit2) + 1 > r)
			--cit2;
		if(cit1 == a.cend() || cit2 < cit1)
			printf("0\n");
		else
			printf("%lld\n", cit2 - cit1 + 1);
	}
	return 0;
}