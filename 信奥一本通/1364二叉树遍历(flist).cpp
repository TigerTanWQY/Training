#include <iostream>
#include <climits>
#include <string>
using namespace std;

string mid, cen;
int flag[1003];

void dfs(const int &L1, const int &R1)
{
	int pos, minn = INT_MAX;
	for(int k = L1; k <= R1; ++k)
		if(flag[mid[k] - 'A' + 1] < minn)
		{
			minn = flag[mid[k] - 'A' + 1];
			pos = k;
		}
	cout << mid[pos];
	if(pos > L1)
		dfs(L1, pos - 1);
	if(pos < R1)
		dfs(pos + 1, R1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> mid >> cen;
	int len = cen.length();
	for(int i = 0; i < len; ++i)
		flag[cen[i] - 'A' + 1] = i;
	dfs(0, len - 1);
	return 0;
}