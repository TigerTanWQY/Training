#include <cstdio>
#include <cmath>
using namespace std;

bool mp[1003];
int a[1003];
int m = 0;

void preOrder(const int &p)
{
	printf("%d ", a[p]);
	if(p * 2 <= m)
		preOrder(p * 2);
	if(p * 2 + 1 <= m)
		preOrder(p * 2 + 1);
}

void midOrder(const int &p)
{
	if(p * 2 <= m)
		midOrder(p * 2);
	printf("%d ", a[p]);
	if(p * 2 + 1 <= m)
		midOrder(p * 2 + 1);
}

void postOrder(const int &p)
{
	if(p * 2 <= m)
		postOrder(p * 2);
	if(p * 2 + 1 <= m)
		postOrder(p * 2 + 1);
	printf("%d ", a[p]);
}

int main()
{
	int h, p;
	scanf("%d%d", &h, &p);
	int x;
	while(scanf("%d", &x) != EOF)
		if(!mp[x])
		{
			mp[x] = true;
			a[++m] = x;
		}
	m = pow(2, h) - 1;
	if(p == 1)
		preOrder(1);
	else if(p == 2)
		midOrder(1);
	else
		postOrder(1);
	return 0;
}