#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int s, t, x;
	cin >> s >> t >> x;
	if(s > t)
		t += 24;
	if(s > x)
		x += 24;
	if(s <= x && x < t)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}