#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define L first
#define R second

constexpr const int N = 200'003;
pair<int, int> a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n, s, m; _T--; ) {
		cin >> n >> s >> m;
		for(int i = 1; i <= n; ++i)
			cin >> a[i].L >> a[i].R;
		sort(a + 1, a + n + 1);
		bool flag = false;
		for(int i = 1; !flag && i < n; ++i)
			if(a[i + 1].L - a[i].R >= s)
				flag = true;
		if(!flag && a[1].L >= s)
			flag = true;
		if(!flag && m - a[n].R >= s)
			flag = true;
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	cout.flush();
	return 0;
}