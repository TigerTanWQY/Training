#include <iostream>
#include <string>
using namespace std;

string pre, mid;
int n;

void dfs(const int &L1, const int &R1, const int &L2, const int &R2)
{
	if(L1 >= R1)
	{
		if(L1 == R1)
			cout << pre[L1];
		return;
	}
	int x;
	for(int i = L2; i <= R2; ++i)
		if(mid[i] == pre[L1])
		{
			x = i;
			break;
		}
	dfs(L1 + 1, L1 + x - L2, L2, x - 1);
	dfs(L1 + x - L2 + 1, R1, x + 1, R2);
	cout << pre[L1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> pre >> mid;
	n = pre.length();
	pre.insert(pre.cbegin(), '!');
	mid.insert(mid.cbegin(), '!');
	dfs(1, n, 1, n);
	return 0;
}