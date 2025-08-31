#include <bits/stdc++.h>
using namespace std;

struct Stu
{
	int id;
	double score;
	bool operator<(const Stu& x) const noexcept
	{ return score < x.score; }
	bool operator>(const Stu& x) const noexcept
	{ return score > x.score; }
} a[103];

Stu qsort(const int& l, const int& r, const int& k) noexcept
{
	swap(a[l], a[l + rand() % (r - l + 1)]);
	auto x = a[l];
	register auto i = l, j = r;
	while(i < j)
	{
		while(i < j && a[j] > x)
			--j;
		if(i < j)
			a[i++] = a[j];
		while(i < j && a[i] < x)
			++i;
		if(i < j)
			a[j--] = a[i];
	}
	a[i] = x;
	if(i == k)
		return x;
	else if(k < i)
		return qsort(l, i - 1, k);
	else
		return qsort(i + 1, r, k);
}

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	srand(time(nullptr));
	int n, k;
	cin >> n >> k;
	for(register auto i = 1; i <= n; ++i)
		cin >> a[i].id >> a[i].score;
	register auto ans = qsort(1, n, k);
	cout << ans.id << ' ' << ans.score;
	return 0;
}