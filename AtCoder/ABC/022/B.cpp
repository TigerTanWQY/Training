#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 100003;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unordered_map<int, int> id;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(!id.count(a[i]))
			id[a[i]] = i;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(id[a[i]] < i)
			++ans;
	cout << ans << '\n';
	return 0;
}