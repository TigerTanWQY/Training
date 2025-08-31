#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{ int l, r; }
a[1003];
string s[1003], t;
int c[1003], top = 0;

void postOrder(const int &p)
{
	if(a[p].l)
		postOrder(a[p].l);
	if(a[p].r)
		postOrder(a[p].r);
	printf("%s ", s[p].c_str());
}

int main()
{
	int n = 0;
	while(cin >> t)
		s[++n] = t;
	for(int i = n; i; --i)
		if('0' <= s[i][0] && s[i][0] <= '9')
			c[++top] = i;
		else
		{
			int x = c[top--], y = c[top--];
			a[i].l = x;
			a[i].r = y;
			c[++top] = i;
		}
	postOrder(1);
	return 0;
}