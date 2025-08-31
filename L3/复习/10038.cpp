#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> odd, even;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		if(x & 1)
			odd.push_back(x);
		else
			even.push_back(x);
	}
	sort(odd.begin(), odd.end(), greater<int>());
	sort(even.begin(), even.end(), greater<int>());
	if(odd.size() >= 2 && even.size() >= 2)
		cout << max(odd[0] + odd[1], even[0] + even[1]);
	else if(odd.size() >= 2)
		cout << odd[0] + odd[1];
	else if(even.size() >= 2)
		cout << even[0] + even[1];
	else
		cout << "-1";
	cout << endl;
	return 0;
}