#include <iostream>
#include <algorithm>
using namespace std;

int a[1003][1003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q;
	char ch;
	for(int x1, y1, x2, y2; _q--; ) {
		cin >> x1 >> y1 >> x2 >> y2 >> ch;
		if(x1 > x2)
			swap(x1, x2);
		if(y1 > y2)
			swap(y1, y2);
		if(ch == 'w')
			for(int i = x1; i <= x2; ++i)
				for(int j = y1; j <= y2; ++j)
					a[i][j] = 0;
		else
			for(int i = x1; i <= x2; ++i)
				for(int j = y1; j <= y2; ++j)
					a[i][j] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(!a[i][j])
				++ans;
	cout << ans << endl;
	return 0;
}
