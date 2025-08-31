#include <cstdio>
#include <deque>
using namespace std;

deque<int> d;
char op[9];

int main()
{
	int m;
	scanf("%d", &m);
	while(m--)
	{
		scanf("%s", op);
		if(op[0] == 'i')
		{
			int x, y;
			scanf("%d%d", &x, &y);
			d.insert(d.cbegin() + x, y);
		}
		else if(op[0] == 'd')
		{
			int x;
			scanf("%d", &x);
			d.erase(d.cbegin() + x - 1);
		}
		else
		{
			int k;
			scanf("%d", &k);
			printf("%d\n", d[k - 1]);
		}
	}
	return 0;
}