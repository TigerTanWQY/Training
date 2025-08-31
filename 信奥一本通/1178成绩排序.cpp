#include <bits/stdc++.h>
using namespace std;

struct Stu
{
	char name[23];
	int score;
} a[22];

bool cmp(const Stu& x, const Stu& y) noexcept
{
	if(x.score != y.score)
		return x.score > y.score;
	else
		return strcmp(x.name, y.name) < 0;
}

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for(register auto i = 1; i <= n; ++i)
		cin >> a[i].name >> a[i].score;
	sort(a + 1, a + n + 1, cmp);
	for(register auto i = 1; i <= n; ++i)
		cout << a[i].name << ' ' << a[i].score << '\n';
	return 0;
}