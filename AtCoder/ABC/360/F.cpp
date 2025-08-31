#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define _L first
#define _R second

const int N = 100003;
pair<int, int> a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i]._L >> a[i]._R;
	sort(a + 1, a + n + 1);
	;
	return 0;
}