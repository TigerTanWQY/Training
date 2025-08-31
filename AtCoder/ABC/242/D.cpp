#include <iostream>
#include <string>
using namespace std;
using LL = long long;

inline LL count1(LL x)
{
	LL ret = 0;
	while(x)
	{
		if(x % 2)
			++ret;
		x >>= 1;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string S;
	int Q;
	cin >> S >> Q;
	while(Q--)
	{
		LL t, k, p = 0;
		cin >> t >> k;
		--k;
		if(t < 60)
		{
			p = k >> t;
			k %= 1LL << t;
		}
		cout << char((S[p] - 'A' + (t + count1(k))) % 3 + 'A') << "\n";
	}
	return 0;
}