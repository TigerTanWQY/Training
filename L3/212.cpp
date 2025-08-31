#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{ int l, r; }
a[1003];
string s[1003], t;
int c[1003], top = 0;

void preOrder(const int &p)
{
	printf("%s ", s[p].c_str());
	if(a[p].l)
		preOrder(a[p].l);
	if(a[p].r)
		preOrder(a[p].r);
}

int main()
{
	int n = 0;
	while(cin >> t)
		s[++n] = t;
	for(int i = 1; i <= n; ++i)
		if('0' <= s[i][0] && s[i][0] <= '9')
			c[++top] = i;
		else
		{
			int x = c[top--], y = c[top--];
			a[i].l = y;
			a[i].r = x;
			c[++top] = i;
		}
	preOrder(n);
	return 0;
}