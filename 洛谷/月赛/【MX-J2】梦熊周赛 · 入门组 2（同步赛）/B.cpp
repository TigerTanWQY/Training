#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, p;
	cin >> n >> p;
	int m = --n, cnt = 0;
	for(int x; n--; p = x) {
		cin >> x;
		cnt += (x == p);
	}
	if(m == cnt)
		cout << '0';
	else
		cout << m;
	cout.flush();
	return 0;
}