#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<pair<int, int>> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int t, a, b; q--; )
	{
		cin >> t >> a >> b;
		if(t == 1)
			s.insert({a, b});
		else if(t == 2)
			s.erase({a, b});
		else
			cout << (s.count({a, b}) && s.count({b, a})? "Yes": "No") << '\n';
	}
	return 0;
}