#include <iostream>
using namespace std;

constexpr const int N = 503;
char a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> (a[i] + 1);
	for(int i = 1, j = 1, cnt = 0; ; ++cnt)
		if(cnt > 1e7) {
			cout << "-1";
			break;
		} else if(a[i][j] == 'U' && i != 1)
			--i;
		else if(a[i][j] == 'D' && i != n)
			++i;
		else if(a[i][j] == 'L' && j != 1)
			--j;
		else if(a[i][j] == 'R' && j != m)
			++j;
		else {
			cout << i << ' ' << j;
			break;
		}
	cout << endl;
	return 0;
}