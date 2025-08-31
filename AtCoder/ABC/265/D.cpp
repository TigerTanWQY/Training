#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long p, q, r, tot = 0;
	cin >> n >> p >> q >> r;
	set<long long> s;
	s.insert(tot);
	for(int i = 0, x; i < n; ++i)
	{
		cin >> x;
		s.insert(tot += x);
	}
	for(const auto &x: s)
		if(s.find(x + p) != s.cend() && s.find(x + p + q) != s.cend() && s.find(x + p + q + r) != s.cend())
		{
			cout << "Yes";
			return 0;
		}
	cout << "No";
	return 0;
}
