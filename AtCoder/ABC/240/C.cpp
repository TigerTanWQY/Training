#include <iostream>
#include <bitset>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	bitset<10003> a;
	a[0] = true;
	for(int u, v; n--; ) {
		cin >> u >> v;
		a = (a << u) | (a << v);
	}
	if(a[x])
		cout << "Yes";
	else
		cout << "No";
	return 0;
}