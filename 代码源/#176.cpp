#include <iostream>
#include <map>
using namespace std;

map<string, int> server;

inline bool check(const string &ip)
{
	int t[8]{};
	int cnt = sscanf(ip.c_str(), "%d.%d.%d.%d:%d", t + 1, t + 2, t + 3, t + 4, t + 5);
	if(cnt != 5)
		return false;
	for(int i = 1; i < 5; ++i)
		if(t[i] < 0 || t[i] > 255)
			return false;
	if(t[5] < 0 || t[5] > 65535)
		return false;
	char now[23];
	sprintf(now, "%d.%d.%d.%d:%d", t[1], t[2], t[3], t[4], t[5]);
	if(string(now) != ip)
		return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		string op, ad;
		cin >> op >> ad;
		if(!check(ad))
		{
			cout << "ERR\n";
			continue;
		}
		if(op == "Server")
			if(!server[ad])
			{
				server[ad] = i;
				cout << "OK\n";
			}
			else
				cout << "FAIL\n";
		else if(op == "Client")
			if(server[ad] > 0)
				cout << server[ad] << "\n";
			else
				cout << "FAIL\n";

	}
	return 0;
}