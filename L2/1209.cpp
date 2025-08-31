#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A, B, L;
	scanf("%d%d%d", &A, &B, &L);
	int ansA = -1, ansB = -1;
	for(int a = 1; a <= L; ++a)
		for(int b = 1; b <= L; ++b)
			if(a * B >= A * b && (a * ansB < ansA * b || ansA == -1))
				{
					ansA = a;
					ansB = b;
				}
	printf("%d %d", ansA, ansB);
	return 0;
}