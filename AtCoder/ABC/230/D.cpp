#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using PII = pair<int, int>;

vector<PII> a;

bool cmp(const PII &x, const PII &y)
{ return x.second != y.second? x.second < y.second: x.first < y.first; }

int main()
{
	int n, d, ans = 0, x = -2147483648;
	scanf("%d%d", &n, &d);
	for(int i = 0; i < n; ++i)
	{
		int L, R;
		scanf("%d%d", &L, &R);
		a.push_back(make_pair(L, R));
	}
	sort(a.begin(), a.end(), cmp);
	for(const auto &p: a)
		if(x + d - 1 < p.first)
		{
			++ans;
			x = p.second;
		}
	printf("%d", ans);
	return 0;
}