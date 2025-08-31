#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> ads;
int a[5];

bool check(const string &ad)
{
	sscanf(ad.c_str(), "%d.%d.%d.%d:%d", a, a + 1, a + 2, a + 3, a + 4);
	if(!(0 <= a[0] && a[0] <= 255 && 0 <= a[1] && a[1] <= 255 && 0 <= a[2] && a[2] <= 255 && 0 <= a[3] && a[3] <= 255 && 0 <= a[4] && a[4] <= 65535))
		return false;
	string str = to_string(a[0]) + '.' + to_string(a[1]) + '.' + to_string(a[2]) + '.' + to_string(a[3]) + ':' + to_string(a[4]);
	return str == ad;
}

int main()
{
	int n;
	cin >> n;
	for(int j = 1; j <= n; ++j)
	{
		string op, ad;
		cin >> op >> ad;
		if(!check(ad))
		{
			cout << "ERR\n";
			continue;
		}
		bool flag = false;
		if(op[0] == 'S')
		{
			int m = ads.size();
			for(int i = 0; i < m; ++i)
				if(ads[i].first == ad)
				{
					cout << "FAIL\n";
					flag = true;
					break;
				}
			if(flag)
				continue;
			ads.push_back(make_pair(ad, j));
			cout << "OK\n";
		}
		else
		{
			int m = ads.size();
			for(int i = 0; i < m; ++i)
				if(ads[i].first == ad)
				{
					cout << ads[i].second << '\n';
					flag = true;
					break;
				}
			if(!flag)
				cout << "FAIL\n";
		}
	}
	return 0;
}