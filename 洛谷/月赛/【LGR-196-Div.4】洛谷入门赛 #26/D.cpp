#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int ans = 0;
	for(int i = 1, l; i <= m; ++i) {
		cin >> l;
		bool visa = false;
		for(int j = 1, x; j <= l; ++j) {
			cin >> x;
			if(x == a)
				visa = true;
			if(x == b)
				if(visa)
					++ans;
		}
	}
	cout << ans;
	cout.flush();
	return 0;
}