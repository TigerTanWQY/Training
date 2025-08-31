#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, long long> mp;
int a[200003];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> q;
	for(int j = 1, all = -1; j <= q; ++j)
	{
		int id;
		cin >> id;
		if(id == 1)
		{
			int x;
			cin >> x;
			all = x;
			mp.clear();
		}
		else if(id == 2)
		{
			int i, x;
			cin >> i >> x;
			if(mp.count(i))
				mp[i] += x;
			else if(all != -1)
				mp[i] = all + x;
			else
				mp[i] = a[i] + x;
		}
		else
		{
			int i;
			cin >> i;
			if(mp.count(i))
				cout << mp[i];
			else if(all != -1)
				cout << all;
			else
				cout << a[i];
			cout << '\n';
		}
	}
	return 0;
}