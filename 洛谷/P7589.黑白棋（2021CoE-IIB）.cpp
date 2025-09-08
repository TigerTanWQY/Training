#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n, k, d; _T--; cout.put('\n')) {
		cin >> n >> k >> d;
		int tot = 0;
		for(int y, b, w; n--; ) {
			cin >> y >> b >> w;
			tot ^= abs(b - w) - 1;
		}
		cout << (tot? "Yes": "No");
	}
	cout.flush();
	return 0;
}
