#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define _x first
#define _y second

pair<int, int> a[3];

int dis(const int& i, const int& j)
{ return (a[i]._x - a[j]._x) * (a[i]._x - a[j]._x) + (a[i]._y - a[j]._y) * (a[i]._y - a[j]._y); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < 3; ++i)
		cin >> a[i]._x >> a[i]._y;
	sort(a, a + 3);
	do {
		int la = dis(0, 1), lb = dis(1, 2), lc = dis(2, 0);
		if(la + lb == lc || la + lc == lb || lb + lc == la) {
			cout << "Yes";
			cout << endl;
			return 0;
		}
	} while(next_permutation(a, a + 3));
	cout << "No";
	cout << endl;
	return 0;
}