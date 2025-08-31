#include <bits/stdc++.h>
using namespace std;

const int N = 30003;
int prime[N]{0}, pipe_prime[N], cell_prime[N], minn = INT_MAX, sum_prime = 0;

bool is_prime(const int &x)
{
	if(x < 2)
		return false;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return false;
	return true;
}

int main()
{
	bool flag = false;
	int n, m1, m2;
	scanf("%d%d%d", &n, &m1, &m2);
	for(int i = 2; i < N; ++i)
	{
		if(is_prime(i))
		{
			++sum_prime;
			prime[sum_prime] = i;
		}
	}
	for(int i = 1; m1 != 1; ++i)
		if(m1 % prime[i] == 0)
			while(m1 % prime[i] == 0)
			{
				pipe_prime[i] += m2;
				m1 /= prime[i];
			}
	for(int i = 1; i <= n; ++i)
	{
		int cell, now = 0;
		scanf("%d", &cell);
		bool here = true;
		memset(cell_prime, 0, sizeof(cell_prime));
		for(int j = 1; j <= sum_prime; ++j)
		{
			if(cell % prime[j] == 0)
				while(cell % prime[j] == 0)
				{
					++cell_prime[j];
					cell /= prime[j];
				}
		}
		for(int j = 1; j <= sum_prime; ++j)
		{
			if(pipe_prime[j] != 0 && cell_prime[j] == 0)
				here = false;
			if(pipe_prime[j] != 0 && cell_prime[j] != 0)
				if(pipe_prime[j] % cell_prime[j] == 0)
					now = max(now, pipe_prime[j] / cell_prime[j]);
				else
					now = max(now, pipe_prime[j] / cell_prime[j] + 1);
		}
		if(here)
		{
			flag = true;
			if(now < minn)
				minn = now;
		}
	}
	if(flag)
		printf("%d", minn);
	else
		printf("-1");
	return 0;
}