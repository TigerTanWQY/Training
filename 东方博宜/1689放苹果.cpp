#include <bits/stdc++.h>
using namespace std;

const int MOD = 55555;
//���������1~N��ÿ����λ����� 1 ��ƻ����
//!������������ 3 ����λ�϶���ƻ����
int main()
{
	int n;
	scanf("%d", &n);
	int ans = 1;
	for(int _ = 1; _ <= n; ++_)
		ans = ans * 2 % MOD;
	ans -= (n - 2 + 1) * (n - 2) / 2;
	while(ans < 0)
		ans += MOD;
	printf("%d", ans);
	return 0;
}