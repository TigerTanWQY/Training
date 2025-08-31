#include <iostream>
using namespace std;
/*
总结：
时间复杂度：O(n^3)
空间复杂度：O(n^2)
错误原因：初始化
（未完
*/
const int N = 9;
const int n = 12;
int a[n][n];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= N; ++j)
			cin >> a[i][j];
	bool flag = true;
	for(int i = 1; i <= N && flag; ++i)
	{
		bool f[n]{};
		for(int j = 1; j <= N; ++j)
			f[a[i][j]] = true;
		if(!(f[1] && f[2] && f[3] && f[4] && f[5] && f[6] && f[7] && f[8] && f[9]))
			flag = false;
	}
	for(int j = 1; j <= N && flag; ++j)
	{
		bool f[n]{};
		for(int i = 1; i <= N; ++i)
			f[a[i][j]] = true;
		if(!(f[1] && f[2] && f[3] && f[4] && f[5] && f[6] && f[7] && f[8] && f[9]))
			flag = false;
	}
	for(int k = 1; k <= N && flag; ++k)
	{
		bool f[n]{};
		for(int i = (k - 1) / 3 * 3 + 1; i <= (k - 1) / 3 * 3 + 3; ++i)
			for(int j = 3 * (k % 3? k % 3: 3) - 2; j <= 3 * (k % 3? k % 3: 3); ++j)
				f[a[i][j]] = true;
		if(!(f[1] && f[2] && f[3] && f[4] && f[5] && f[6] && f[7] && f[8] && f[9]))
			flag = false;
	}
	if(flag)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}