#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unordered_set<int> ans;
	for(int x; n--; ) {
		cin >> x;
		ans.insert(x);
	}
	cout << ans.size();
	return 0;
}