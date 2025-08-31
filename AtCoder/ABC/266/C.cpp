#include <iostream>
using namespace std;

int x[11], y[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i = 0; i < 4; ++i) {
		cin >> x[i] >> y[i];
		x[i + 4] = x[i];
		y[i + 4] = y[i];
	}
	for(int i = 0; i < 4; ++i)
		if((x[i + 1] - x[i]) * (y[i + 2] - y[i + 1]) - (x[i + 2] - x[i + 1]) * (y[i + 1] - y[i]) <= 0) {
			cout << "No";
			return 0;
		}
	cout << "Yes";
	return 0;
}
