#include <iostream>
using namespace std;

constexpr const int g[]{0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888,10888,18888};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; cout.put('\n')) {
		cin >> n;
		if(n <= 30) {
			cout << g[n];
			continue;
		}
		int d = n / 7, r = n % 7;
		if(r == 1) {
			--d;
			cout << "10";
		} else if(r == 3) {
			d -= 2;
			cout << "200";
		} else if(r == 4) {
			--d;
			cout << "20";
		} else if(r)
			cout << g[r];
		while(d--)
			cout.put('8');
	}
	cout.flush();
	return 0;
}