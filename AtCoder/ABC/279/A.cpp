#include <cstdio>
using namespace std;

int main()
{
	int cnt = 0;
	for(char ch = getchar(); ch != EOF; ch = getchar())
	{
		++cnt;
		if(ch == 'w')
			++cnt;
	}
	printf("%d", cnt - 1);
	return 0;
}
