#include <bits/stdc++.h>
using namespace std;

const int N = 13;
vector<int> hvec, wvec;
int a[N][N], b[N][N];

int main()
{
	int h1, w1, h2, w2;
	scanf("%d%d", &h1, &w1);
	for(int i = 1; i <= h1; ++i)
		for(int j = 1; j <= w1; ++j)
			scanf("%d", &a[i][j]);
	scanf("%d%d", &h2, &w2);
	for(int i = 1; i <= h2; ++i)
		for(int j = 1; j <= w2; ++j)
			scanf("%d", &b[i][j]);
	for(int i = 0; i < (1 << h1); ++i)
		for(int j = 0; j < (1 << w1); ++j)
		{
			hvec.clear();
			wvec.clear();
			for(int k = 1; k <= h1; ++k)
				if(!(i & (1 << (k - 1))))
					hvec.push_back(k);
			for(int k = 1; k <= w1; ++k)
				if(!(j & (1 << (k - 1))))
					wvec.push_back(k);
			if(hvec.size() != h2 || wvec.size() != w2)
				continue;
			bool flag = true;
			for(int k = 1; k <= h2 && flag; ++k)
				for(int l = 1; l <= w2 && flag; ++l)
					if(a[hvec[k - 1]][wvec[l - 1]] != b[k][l])
						flag = false;
			if(flag)
			{
				printf("Yes");
				return 0;
			}
		}
	printf("No");
	return 0;
}