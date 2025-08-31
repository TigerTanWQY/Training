#include <iostream>
#include <map>
using namespace std;
using LL = unsigned long long;

map<LL, LL> a;

LL pow(const LL &base, LL exp)
{
	LL ret = 1;
	for(; exp--; ret *= base);
	return ret;
}

void fact(const LL &x)
{
	for(LL i = 1; i * i <= x; ++i)
		if(x % i == 0)
		{
			++a[i];
			if(i * i != x)
				++a[x / i];
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	LL b;
	cin >> b;
	fact(b);
	for(const auto &x: a)
		if(x.first == x.second && pow(x.first, x.first) == b)
		{
			cout << x.first;
			return 0;
		}
	cout << "-1";
	return 0;
}