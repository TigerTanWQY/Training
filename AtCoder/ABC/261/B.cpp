#include <iostream>
using namespace std;

const int N = 1003;
char a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> (a[i] + 1);
	bool flag = true;
	for(int i = 1; flag && i <= n; ++i)
		for(int j = 1; flag && j <= n; ++j)
			if(a[i][j] == 'W' && a[j][i] != 'L')
				flag = false;
			else if(a[i][j] == 'L' && a[j][i] != 'W')
				flag = false;
			else if(a[i][j] == 'D' && a[j][i] != 'D')
				flag = false;
	if(flag)
		cout << "correct";
	else
		cout << "incorrect";
	return 0;
}