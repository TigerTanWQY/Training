#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 103;
int s[N], a[N], sg[10003], k;

int SG(const int& x) {
	if(~sg[x])
		return sg[x];
	unordered_set<int> vis;
	for(int i = 1; i <= k; ++i)
		if(x - s[i] >= 0)
			vis.insert(SG(x - s[i]));
	for(int i = 0; ; ++i)
		if(!vis.count(i)) {
			sg[x] = i;
			break;
		}
	return sg[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(sg, -1, sizeof(sg));
	int n;
	cin >> k;
	for(int i = 1; i <= k; ++i)
		cin >> s[i];
	cin >> n;
	int ans = 0;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		ans ^= SG(x);
	}
	cout << (ans? "Yes": "No");
	cout.flush();
	return 0;
}