#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

inline void print(int q1, int q2)
{
	int g = abs(__gcd(q1, q2));
	q1 /= g;
	q2 /= g;
	if(q2 == 1)
		printf("%d", q1);
	else
		printf("%d/%d", q1, q2);
}

int main()
{
	int T;
	scanf("%d%*d", &T);
	while(T--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int d = b * b - 4 * a * c;
		if(d < 0)
			printf("NO");
		else
		{
			int x = 0, q1, q2;
			for(int i = 1; i * i <= d; ++i)
				if(d % (i * i) == 0)
					x = i;
			if(x * x == d)
			{
				if(a > 0)
				{
					q1 = -b + x;
					q2 = 2 * a;
				}
				else
				{
					q1 = b + x;
					q2 = -2 * a;
				}
				print(q1, q2);
			}
			else
			{
				if(a > 0)
				{
					q1 = -b;
					q2 = 2 * a;
				}
				else
				{
					q1 = b;
					q2 = -2 * a;
				}
				if(q1 != 0)
				{
					print(q1, q2);
					putchar('+');
				}
				int r = d / (x * x);
				if(a > 0)
				{
					q1 = x;
					q2 = 2 * a;
				}
				else
				{
					q1 = x;
					q2 = -2 * a;
				}
				int g = __gcd(q1, q2);
				q1 /= g;
				q2 /= g;
				if(q2 == 1)
					if(q1 == 1)
						printf("sqrt(%d)", r);
					else
						printf("%d*sqrt(%d)", q1, r);
				else if(q1 == 1)
					printf("sqrt(%d)/%d", r, q2);
				else
					printf("%d*sqrt(%d)/%d", q1, r, q2);
			}
		}
		putchar('\n');
	}
	return 0;
}