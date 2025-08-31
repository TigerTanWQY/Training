#include <cstdio>
#include <deque>
using namespace std;

deque<int> d;
char s[500003];

int main()
{
	int n;
	scanf("%d%s", &n, s);
	d.push_back(n);
	for(int i = n - 1; i >= 0; --i)
		if(s[i] == 'L')
			d.push_back(i);
		else
			d.push_front(i);
	for(int i = 0; i <= n; ++i)
		printf("%d ", d[i]);
	return 0;
}