#include <bits/stdc++.h>
using namespace std;

constexpr const auto N = 100000003;
int a[N];

void qsort(const int& l, const int& r) noexcept
{
	if(l >= r)
		return;
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
	qsort(l, i - 1);
	qsort(i + 1, r);
}

int main(void) noexcept
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	srand(time(nullptr));
	int n;
	cin >> n;
	for(register auto i = 1; i <= n; ++i)
		cin >> a[i];
	qsort(1, n);
	for(register auto i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	return 0;
}