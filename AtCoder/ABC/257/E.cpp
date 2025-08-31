#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int c[12];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 9; ++i)
		scanf("%d", &c[i]);
	int me = *min_element(c + 1, c + 10), len = n / me;
	string ans;
	for(int i = 0; i < len; ++i)
		for(int j = 9; j >= 1; --j)
			if(1LL * me * (len - i - 1) + c[j] <= n)
			{
				n -= c[j];
				ans.push_back('0' + j);
				break;
			}
	printf("%s", ans.c_str());
	return 0;
}