#include <bits/stdc++.h>
using namespace std;

pair<int, int> op[200003];
int t[200003], ans[200003];

inline int bit(const int &x, const int &i)
{ return (x >> i) & 1; }

int main()
{
	int n, c;
	scanf("%d%d", &n, &c);
	for(int i = 0; i < n; ++i)
		scanf("%d%d", &op[i].first, &op[i].second);
	for(int k = 0; k < 30; ++k)
	{
		int func[]{0, 1}, crr = bit(c, k);
		for(int i = 0; i < n; ++i)
		{
			int f[2], x = bit(op[i].second, k);
			if(op[i].first == 1)
			{
				f[0] = 0 & x;
				f[1] = 1 & x;
			}
			else if(op[i].first == 2)
			{
				f[0] = 0 | x;
				f[1] = 1 | x;
			}
			else
			{
				f[0] = 0 ^ x;
				f[1] = 1 ^ x;
			}
			func[0] = f[func[0]];
			func[1] = f[func[1]];
			crr = func[crr];
			ans[i] |= crr << k;
		}
	}
	for(int i = 0; i < n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}