#include <bits/stdc++.h>
using namespace std;

string s, t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> t;
	for(int i = 0; i < s.size(); ++i)
		if(s[i] != t[i])
		{
			cout << i + 1;
			return 0;
		}
	cout << s.size() + 1;
	return 0;
}