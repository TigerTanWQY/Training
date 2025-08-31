#include <cstdio>
#include <algorithm>
using namespace std;

struct TreeNode
{ int l, r; }
a[53];
char pre[53], mid[53];
int maxd = 0;

int pre_mid(const int &L1, const int &R1, const int &L2, const int &R2)
{
	if(L1 >= R1)
	{
		if(L1 == R1)
			return L1;
		return 0;
	}
	int x = 0;
	for(int i = L2; i <= R2; ++i)
		if(mid[i] == pre[L1])
		{
			x = i;
			break;
		}
	a[L1].l = pre_mid(L1 + 1, L1 + x - L2, L2, x - 1);
	a[L1].r = pre_mid(L1 + x - L2 + 1, R1, x + 1, R2);
	return L1;
}

void getd(const int &p, const int &d)
{
	maxd = max(maxd, d);
	if(a[p].l)
		getd(a[p].l, d + 1);
	if(a[p].r)
		getd(a[p].r, d + 1);
}

int main()
{
	int n;
	scanf("%d%s%s", &n, pre + 1, mid + 1);
	pre_mid(1, n, 1, n);
	getd(1, 1);
	printf("%d", maxd);
	return 0;
}