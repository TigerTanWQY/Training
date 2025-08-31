#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ans = 0;
	for(int _ = 0; _ < 8; ++_)
	{
		char op;
		scanf("%c", &op);
		if(op == '1')
			++ans;
	}
	printf("%d", ans);
	return 0;
}