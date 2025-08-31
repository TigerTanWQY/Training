#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int L1, R1, L2, R2;
	cin >> L1 >> R1 >> L2 >> R2;
	if(L1 > L2) {
		swap(L1, L2);
		swap(R1, R2);
	}
	if(R1 <= L2)
		cout << '0';
	else if(R1 <= R2)
		cout << R1 - L2;
	else
		cout << R2 - L2;
	return 0;
}