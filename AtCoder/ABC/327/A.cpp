#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	bool flag = false;
	for(int i = 1; i < n && !flag; ++i)
		if(s[i] == 'a' && s[i - 1] == 'b')
			flag = true;
		else if(s[i] == 'b' && s[i - 1] == 'a')
			flag = true;
	if(flag)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}