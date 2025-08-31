#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int n = s.size();
	for(bool flag = false; n; flag = false)
	{
		for(int i = 0; i <= n - 3; n = s.size(), ++i)
			if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
			{
				s.erase(i, 3);
				flag = true;
			}
		if(!flag)
			break;
	}
	cout << s;
	return 0;
}