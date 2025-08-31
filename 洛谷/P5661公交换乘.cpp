#include <cstdio>
#include <queue>
using namespace std;
using LL = long long;

struct Ticket
{ int type, price, t; };
queue<Ticket> q, rcc;

int main()
{
	int n;
	LL ans = 0;
	scanf("%d", &n);
	while(n--)
	{
		Ticket tmp;
		scanf("%d%d%d", &tmp.type, &tmp.price, &tmp.t);
		if(tmp.type) //公交车
		{
			while(!q.empty() && tmp.t - q.front().t > 45)
				q.pop();
			while(!q.empty() && tmp.price > q.front().price)
			{
				rcc.push(q.front());
				q.pop();
			}
			if(!q.empty() && tmp.price <= q.front().price)
				q.pop();
			else
				ans += tmp.price;
			while(!q.empty())
			{
				rcc.push(q.front());
				q.pop();
			}
			while(!rcc.empty())
			{
				q.push(rcc.front());
				rcc.pop();
			}
		}
		else //地铁
		{
			ans += tmp.price;
			q.push(tmp);
		}
	}
	printf("%lld", ans);
	return 0;
}