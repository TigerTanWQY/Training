#include <iostream>
#include <string>
using namespace std;

const int P = 23;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	unsigned int ha1 = 0, ha2 = 0, p = 1;
	string str;
	cin >> n >> str;
	int ans = n;
	for(int i = 0; i < n - 1; ++i)
	{
		ha1 += str[i] * p;
		ha2 = ha2 * P + str[n - i - 1];
		if(ha1 == ha2)
			ans = n - i - 1;
		p *= P;
	}
	cout << ans;
	return 0;
}