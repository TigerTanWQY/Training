#include <iostream>
#include <string>
//#include <utility>
//#include <vector>
//#include <algorithm>
using namespace std;
// https://www.luogu.com.cn/problem/solution/P1950
string a[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
//	vector<pair<int, int>> point;
	for(int i = 1; i <= n; ++i) {
		string t;
		cin >> t;
		a[i] = '$' + t;
//		for(int j = 1; j <= m; ++j)
//			if(a[i][j] == '*')
//				point.push_back({i, j});
	}
//	sort(point.begin(), point.end());
	int ans = 0;
	for(int di = 1; di <= n; ++di)
		for(int dj = 1; dj <= m; ++dj)
			for(int Li = 1; Li <= n - di + 1; ++Li)
				for(int Lj = 1; Lj <= m - dj + 1; ++Lj) {
					const int& Ri = Li + di - 1, Rj = Lj + dj - 1;
					bool flag = true;
					for(int i = Li; flag && i <= Ri; ++i)
						for(int j = Lj; flag && j <= Rj; ++j)
							if(a[i][j] != '.')
								flag = false;
					ans += flag;
//					auto cit = lower_bound(point.cbegin(), point.cend(), make_pair(Li, Lj));
//					if(cit->first > Ri || cit->second > Rj) {
//						++ans; // 这就是膈肌吧
//						cout << Li << ' ' << Lj << ' ' << Ri << ' ' << Rj << '\n';
//					}
				}
	cout << ans;
	return 0;
}