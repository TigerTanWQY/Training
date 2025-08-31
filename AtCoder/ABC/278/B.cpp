#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h, m;
	cin >> h >> m;
	for(int i = h; ; )
		for(int j = m; ; )
		{
			if(0 <= i / 10 * 10 + j / 10 && i / 10 * 10 + j / 10 < 24 && 0 <= i % 10 * 10 + j % 10 && i % 10 * 10 + j % 10 < 60)
			{
				cout << i << ' ' << j;
				return 0;
			}
			++j;
			if(j == 60)
			{
				++i;
				j = 0;
			}
			if(i == 24)
				i = 0;
		}
	return 0;
}