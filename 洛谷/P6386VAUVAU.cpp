#include <cstdio>
using namespace std;

int main()
{
	int a, b, c, d, p, m, g;
	scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &p, &m, &g);
	int x1 = p % (a + b), y1 = p % (c + d), x2 = m % (a + b), y2 = m % (c + d), x3 = g % (a + b), y3 = g % (c + d);
	if(!x1)
		x1 = a + b;
	if(!y1)
		y1 = c + d;
	if(!x2)
		x2 = a + b;
	if(!y2)
		y2 = c + d;
	if(!x3)
		x3 = a + b;
	if(!y3)
		y3 = c + d;
	if(1 <= x1 && x1 <= a && 1 <= y1 && y1 <= c)
		printf("both\n");
	else if((1 <= x1 && x1 <= a) || (1 <= y1 && y1 <= c))
		printf("one\n");
	else
		printf("none\n");
	if(1 <= x2 && x2 <= a && 1 <= y2 && y2 <= c)
		printf("both\n");
	else if((1 <= x2 && x2 <= a) || (1 <= y2 && y2 <= c))
		printf("one\n");
	else
		printf("none\n");
	if(1 <= x3 && x3 <= a && 1 <= y3 && y3 <= c)
		printf("both\n");
	else if((1 <= x3 && x3 <= a) || (1 <= y3 && y3 <= c))
		printf("one\n");
	else
		printf("none\n");
	return 0;
}