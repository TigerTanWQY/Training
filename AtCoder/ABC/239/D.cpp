#include <cstdio>
using namespace std;

const int prime[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	for(int i = a; i <= b; ++i)
	{
		bool flag = false;
		for(int j = 0; j < 46; ++j)
			if(c <= prime[j] - i && prime[j] - i <= d)
				flag = true;
		if(!flag)
		{
			printf("Takahashi");
			return 0;
		}
	}
	printf("Aoki");
	return 0;
}