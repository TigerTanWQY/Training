#include<bits/stdc++.h>
using namespace std;

int Son[100010][50];
long long Ans[100010][50];
int Min[100010][50];

long long Solve1(int Cur, long long k){
	if(k == 0)
		return 0;
	int xx = 0;
	long long x = 1;
	while(x <= k)
		xx++, x <<= 1;
	xx--;
	x >>= 1;
	return Ans[Cur][xx] + Solve1(Son[Cur][xx], k - x);
}

int Solve2(int Cur, long long k){
	if(k == 0)
		return 2147483647;
	int xx = 0;
	long long x = 1;
	while(x <= k)
		xx++, x <<= 1;
	xx--;
	x >>= 1;
	return min(Min[Cur][xx], Solve2(Son[Cur][xx], k - x));
}

int main(){
	int n;
	long long k;
	scanf("%d %lld", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &Son[i][0]);
	for(int i = 0; i < n; i++)
		scanf("%lld", &Ans[i][0]), Min[i][0] = Ans[i][0];
	for(int t = 1; t <= 40; t++)
		for(int i = 0; i < n; i++)
			Son[i][t] = Son[Son[i][t-1]][t-1];
	for(int t = 1; t <= 40; t++)
		for(int i = 0; i < n; i++)
			Ans[i][t] = Ans[i][t-1] + Ans[Son[i][t-1]][t-1];
	for(int t = 1; t <= 40; t++)
		for(int i = 0; i < n; i++)
			Min[i][t] = min(Min[i][t-1], Min[Son[i][t-1]][t-1]);
	for(int i = 0; i < n; i++)
		printf("%lld %d\n", Solve1(i, k), Solve2(i, k));
	return 0;
}
