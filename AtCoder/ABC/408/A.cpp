#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	bool flag = true;
	for(int x, lst = 0; n--; lst = x) {
		cin >> x;
		if(x - lst > m)
			flag = false;
	}
	cout << (flag? "Yes": "No") << endl;
	return 0;
}
