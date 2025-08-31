#include <cstdio>
using namespace std;

int main()
{
	int n, cnto = 0, cnte = 0;
	scanf("%d", &n);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		if(x % 2)
			++cnto;
		else
			++cnte;
	}
	printf("%d", cnto - cnto % 2 + cnte);
	return 0;
}