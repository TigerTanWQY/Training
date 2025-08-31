#include <bits/stdc++.h>
using namespace std;

constexpr const auto N = 1000003;
constexpr const auto M = N;
char s[N], p[M];
int nxt[M], f[N];
int n, m;

void kmp() noexcept
{
	n = strlen(s + 1);
	m = strlen(p + 1);
	register auto j = 0;
	nxt[1] = 0;
	for(register auto i = 2; i <= m; ++i)
	{
		while(j > 0 && p[j + 1] != p[i])
			j = nxt[j];
		if(p[j + 1] == p[i])
			++j;
		nxt[i] = j;
	}
	j = 0;
	for(register auto i = 1; i <= n; ++i)
	{
		while((j == m) || (j > 0 && p[j + 1] != s[i]))
			j = nxt[j];
		if(p[j + 1] == s[i])
			++j;
		f[i] = j;
	}
	for(register auto i = 1; i <= n; ++i)
		if(f[i] == m)
			cout << i - m + 1 << '\n';
}

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> (s + 1) >> (p + 1);
	kmp();
	return 0;
}