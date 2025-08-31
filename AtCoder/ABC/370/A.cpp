#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L, R;
	cin >> L >> R;
	if(L == R)
		cout << "Invalid";
	else if(L)
		cout << "Yes";
	else
		cout << "No";
	cout.flush();
	return 0;
}