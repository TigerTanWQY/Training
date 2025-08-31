#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
using LL = long long;
#define _L first
#define _R second

const int N = 200003;
pair<int, int> a[N];
LL res[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	LL sL = 0, sR = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i]._L >> a[i]._R;
		sL += a[i]._L;
		sR += a[i]._R;
	}
	if(sL <= 0 && 0 <= sR) {
		for(int i = 1; i <= n; ++i)
			res[i] = a[i]._L;
		LL tmp = -sL;
		for(int i = 1; i <= n; ++i) {
			if(tmp < 0)
				break;
			res[i] += min(tmp, 0LL + a[i]._R - a[i]._L);
			tmp -= min(tmp, 0LL + a[i]._R - a[i]._L);
		}
		cout << "Yes\n";
		for(int i = 1; i <= n; ++i)
			cout << res[i] << ' ';
	} else
		cout << "No";
	cout << endl;
	return 0;
}