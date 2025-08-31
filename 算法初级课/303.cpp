#include <bits/stdc++.h>
using namespace std;

constexpr const auto N = 100003;
char s[2 * N];
int nxt[2 * N];

void kmp(void) noexcept
{
	register auto n = static_cast<int>(strlen(s + 1));
	s[n + 1] = '#';
	for(register auto i = n + 2, j = n; j != 0; --j, ++i)
		s[i] = s[j];
	register auto j = 0;
	nxt[0] = 1;
	for(register auto i = 2; i <= 2 * n + 1; ++i)
	{
		while(j > 0 && s[j + 1] != s[i])
			j = nxt[j];
		if(s[j + 1] == s[i])
			++j;
		nxt[i] = j;
	}
	auto x = 0;
	for(register auto i = n + 1; i <= 2 * n + 1; ++i)
		x = max(x, nxt[i]);
	for(register auto i = x; i >= 1; --i)
		cout << s[i];
}

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> (s + 1);
	kmp();
	return 0;
}