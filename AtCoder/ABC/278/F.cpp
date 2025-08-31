#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<unsigned char, unsigned char>> info(n);
	for(auto &p: info)
	{
		string s;
		cin >> s;
		p.first = s.front() - 'a';
		p.second = s.back() - 'a';
	}
	vector<unsigned> dp(1UL << n);
	for(unsigned s = 1; s < 1UL << n; ++s)
		for(unsigned c = 0; c < n; ++c)
			if(1 & s >> c)
				dp[s] |= (1UL & ~dp[s ^ 1UL << c] >> info[c].second) << info[c].first;
	cout << (dp.back()? "First": "Second") << '\n';
	return 0;
}