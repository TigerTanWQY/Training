#include <bits/stdc++.h>
using namespace std;

int a[34], b[34];

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int ans = 0;
		for(int i = n; i >= 1; --i) //��b[i]�Ӵ�С����
			scanf("%d%d", &a[i], &b[i]);
		a[n + 1] = INT_MAX; //��n+1�ֱ�ʯ
		b[n + 1] = 1;
		for(int i = 1; i <= n + 1; ++i) //����װb[i]�ϴ��
		{
			int x = min(a[i], m / b[i]); //�����a[i]��
			ans += x;
			m -= b[i] * x;
		}
		printf("%d\n", ans);
	}
	return 0;
}