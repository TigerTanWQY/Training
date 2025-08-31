#include <bits/stdc++.h>
using namespace std;

constexpr const auto N = 100 + 3;
char s[N];
int a[N], b[N], c[N], d[2 * N], e[3 * N];

void change(const char* const str, int* const arr, int& len) noexcept
{
	len = strlen(str + 1);
	for(register auto i = 1; i <= len; ++i)
		arr[i] = str[len - i + 1] - '0';
}

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int la, lb, lc;
	cin >> (s + 1);
	change(s, a, la);
	cin >> (s + 1);
	change(s, b, lb);
	cin >> (s + 1);
	change(s, c, lc);
	register auto ld = la + lb;
	for(register auto i = 1; i <= la; ++i)
		for(register auto j = 1; j <= lb; ++j)
			d[i + j - 1] += a[i] * b[j];
	for(register auto i = 1; i <= ld; ++i)
	{
		d[i + 1] += d[i] / 8;
		d[i] %= 8;
	}
	if(d[ld] == 0)
		--ld;
	register auto le = lc + ld;
	for(register auto i = 1; i <= lc; ++i)
		for(register auto j = 1; j <= ld; ++j)
			e[i + j - 1] += c[i] * d[j];
	for(register auto i = 1; i <= le; ++i)
	{
		e[i + 1] += e[i] / 8;
		e[i] %= 8;
	}
	if(e[le] == 0)
		--le;
	for(register auto i = le; i >= 1; --i)
		cout << e[i];
	return 0;
}