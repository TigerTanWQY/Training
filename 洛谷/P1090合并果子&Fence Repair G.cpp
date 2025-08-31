#include <cstdio>
#include <algorithm>
using namespace std;
/** ÊÖÐ´¶Ñ **/
int a[10003], top = 0;

void up(const int &u)
{
	if(u / 2 && a[u / 2] > a[u])
		swap(a[u], a[u / 2]);
	if(u / 2) //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		up(u / 2);
}

inline void push(const int &x)
{
	a[++top] = x;
	up(top);
}

void down(const int &u)
{
	int v = u;
	if(u * 2 <= top && a[u * 2] < a[u])
		v = u * 2;
	if(u * 2 + 1 <= top && a[u * 2 + 1] < a[u] && a[u * 2 + 1] < a[u * 2])
		v = u * 2 + 1;
	if(u != v)
	{
		swap(a[u], a[v]);
		down(v);
	}
}

inline void pop()
{
	a[1] = a[top--];
	down(1);
}

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		push(x);
	}
	while(top > 1)
	{
		int f1 = a[1];
		pop();
		int f2 = a[1];
		pop();
		ans += f1 + f2;
		push(f1 + f2);
	}
	printf("%d", ans);
	return 0;
}