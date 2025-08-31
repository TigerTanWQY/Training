#include <bits/stdc++.h>
using namespace std;

vector<int> bit(10), a{-1};
map<char, int> mp;

inline int sum(int i)
{
	int s = 0;
	while(i > 0)
	{
		s += bit[i];
		i -= i & (-i);
	}
	return s;
}

inline void add(int i, const int &x)
{
	while(i < bit.size())
	{
		bit[i] += x;
		i += i & (-i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s, atc = "*atcoder";
	cin >> s;
	for(int i = 1; i <= 7; ++i)
		mp[atc[i]] = i;
	for(int i = 0; i < 7; ++i)
		a.push_back(mp[s[i]]);
	int res = 0;
	for(int i = 1; i <= 7; ++i)
	{
		res += i - 1 - sum(a[i]);
		add(a[i], 1);
	}
	printf("%d", res);
	return 0;
}