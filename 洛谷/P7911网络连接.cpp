#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<pair<string, int>> S;

inline bool check(const string &ad)
{
	int a[5];
	sscanf(ad.c_str(), "%d.%d.%d.%d:%d", a, a + 1, a + 2, a + 3, a + 4);
	for(int i = 0; i < 4; ++i)
		if(0 > a[i] || a[i] > 255)
			return true;
	if(0 > a[4] || a[4] > 65535)
		return true;
	char add[23];
	sprintf(add, "%d.%d.%d.%d:%d", a[0], a[1], a[2], a[3], a[4]);
	return string(add) != ad;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		string op, ad;
		cin >> op >> ad;
		if(check(ad))
			cout << "ERR";
		else if(op == "Server")
		{
			bool flag = true;
			for(const auto &p: S)
				if(p.first == ad)
				{
					cout << "FAIL";
					flag = false;
					break;
				}
			if(flag)
			{
				S.push_back({ad, i});
				cout << "OK";
			}
		}
		else if(op == "Client")
		{
			bool flag = false;
			for(const auto &p: S)
				if(p.first == ad)
				{
					cout << p.second;
					flag = true;
					break;
				}
			if(!flag)
				cout << "FAIL";
		}
		cout << "\n";
	}
	return 0;
}