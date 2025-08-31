#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string n;
	cin >> n;
	for(int i = 0; i < 10; ++i)
	{
		string t = string(i, '0') + n, rt = t;
		reverse(t.begin(), t.end());
		if(rt == t)
		{
			printf("Yes");
			return 0;
		}
	}
	printf("No");
	return 0;
}