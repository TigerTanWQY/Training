#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 103;
int sg[N];

int SG(const int& x) {
	if(~sg[x])
		return sg[x];
	unordered_set<int> s;
	for(int i = 0; i < x; ++i)
		for(int j = 0; j <= i; ++j)
			s.insert(SG(i) ^ SG(j));
	for(int i = 0; ; ++i)
		if(!s.count(i)) {
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
	cin >> n;
	int ans = 0;
	for(int x; n--; ) {
		cin >> x;
		ans ^= SG(x);
	}
	if(ans)
		cout << "Yes";
	else
		cout << "No";
	cout.flush();
	return 0;
}