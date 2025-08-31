#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int q[N + 3];
int f = 1, r = N;

int main()
{
	int m;
	scanf("%d", &m);
	while(m--)
	{
		char op[8];
		scanf("%s", op);
		if(op[0] == 'q')
		{
			//query
			int k;
			scanf("%d", &k);/*
			if(N - f + 1 >= k)
				printf("%d\n", q[f + k - 1]);
			else
				printf("%d\n", q[k - N + f - 1]);*/
			printf("%d\n", q[(f + k - 2) % N + 1]);
		}
		else if(strlen(op) == 4)
		{
			//push
			int x;
			scanf("%d", &x);
			r = r % N + 1;
			q[r] = x;
		}
		else
			//pop
			f = f % N + 1;
	}
	return 0;
}