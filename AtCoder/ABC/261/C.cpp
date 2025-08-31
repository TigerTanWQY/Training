#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while(n--)
	{
		string str;
		cin >> str;
		++m[str];
		cout << str;
		if(m[str] > 1)
			cout << "(" << m[str] - 1 << ")";
		cout << "\n";
	}
	return 0;
}