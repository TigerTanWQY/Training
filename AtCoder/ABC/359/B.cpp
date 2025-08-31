#include <iostream>
#include <unordered_set>
using namespace std;

int a[203];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= 2 * n; ++i)
		cin >> a[i];
	unordered_set<int> ans;
	for(int i = 1; i <= 2 * n - 2; ++i)
		if(a[i] != a[i + 1] && a[i] == a[i + 2])
			ans.insert(a[i]);
	cout << ans.size();
	return 0;
}