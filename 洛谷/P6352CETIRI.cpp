#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(b < a)
		swap(a, b);
	if(c < a)
		swap(a, c);
	if(c < b)
		swap(b, c);
	int x = b - a, y = c - b;
	if(x == y)
		printf("%d", c + y);
	else if(x == 2 * y)
		printf("%d", a + y);
	else if(x * 2 == y)
		printf("%d", b + x);
	return 0;
}