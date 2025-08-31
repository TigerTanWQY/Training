#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
vector<pair<int, int>> a;
char str[1000003];

int main()
{
	bool flag;
	scanf("%s%d", str + 1, &flag);
	int n = strlen(str + 1), d = 0;
	for(int i = 1; i <= n; ++i)
		if(s.empty())
			s.push(i);
		else if(str[s.top()] == '(')
			if(str[i] == '(')
				s.push(i);
			else
			{
				if(!a.empty())
					for(; !a.empty() && s.top() <= a.back().first; a.pop_back());
				a.push_back(make_pair(s.top(), i));
				s.pop();
			}
		else
			s.push(i);
	for(const auto &p: a)
		d += p.second - p.first + 1;
	printf("%d", n - d);
	if(flag)
	{
		if(a.empty())
		{
			printf(" 0");
			return 0;
		}
		int ans = 1;
		for(auto cit = a.cbegin(), nxt = ++a.cbegin(); nxt != a.cend(); ++cit, ++nxt)
			if(cit->second + 1 != nxt->first)
				++ans;
		printf(" %d", ans);
	}
	return 0;
}