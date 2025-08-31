#include <bits/stdc++.h>
using namespace std;

struct Stu
{
	int id;
	double score;
} a[103];

bool cmp(const Stu& x, const Stu& y) noexcept
{ return x.score > y.score; }

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for(register auto i = 1; i <= n; ++i)
		cin >> a[i].id >> a[i].score;
	sort(a + 1, a + n + 1, cmp);
	cout << a[k].id << ' ' << a[k].score;
	return 0;
}