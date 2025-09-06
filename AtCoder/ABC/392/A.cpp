#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	auto chk = [&a](void)
	{ return a[0] * a[1] == a[2]; };
	sort(a, a + 3);
	do
		if(chk()) {
			cout << "Yes" << endl;
			return 0;
		}
	while(next_permutation(a, a + 3));
	cout << "No" << endl;
	return 0;
}
