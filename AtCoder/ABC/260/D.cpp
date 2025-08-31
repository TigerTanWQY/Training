#include <bits/stdc++.h>
using namespace std;

set<int> st;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> under(n + 5, -1), pile(n + 5, 0), res(n + 5, -1);
	for(int i = 1; i <= n; ++i)
	{
		int p;
		scanf("%d", &p);
		auto it = st.upper_bound(p);
		if(it == st.end())
		{
			pile[p] = 1;
			st.insert(p);
		}
		else
		{
			under[p] = *it;
			pile[p] = pile[*it] + 1;
			st.erase(it);
		}
		st.insert(p);
		if(pile[p] == k)
		{
			st.erase(p);
			int x = p;
			for(int j = 0; j < k; ++j)
			{
				res[x] = i;
				x = under[x];
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d\n", res[i]);
	return 0;
}