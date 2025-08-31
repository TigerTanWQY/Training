#include <iostream>
#include <string>
using namespace std;

string stdd[11], sht;
int len;

inline void solve(const int &m)
{
	int p = sht.find("::");
	string ans;
	for(int i = 0; i <= m; ++i)
	{
//		if(p < len && 4 * i >= p)
//			for(int _ = 0; _ < 8 - m; ++_)
//				ans += "0000:";
//		else
//		{
			if(stdd[i].size() < 4)
				for(int _ = 0; _ < 4 - stdd[i].size(); ++_)
					ans += "0";
			ans += stdd[i] + ":";
//		}
	}
	ans.pop_back();
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int _ = 0; _ < n; ++_)
	{
		cin >> sht;
		len = sht.size();
		int j = 0;
		for(int i = 0; i < len; ++i)
			if(sht[i] != ':')
				stdd[j] += sht[i];
			else if(sht[i] == ':' && i + 1 < len && sht[i + 1] != ':')
				++j;
		solve(j);
		for(int i = 0; i < 8; ++i)
			stdd[i].clear();
	}
	return 0;
}