#include <iostream>
#include <utility>
using namespace std;
#define c first
#define x second

const int N = 300003;
pair<int, int> a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].c;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].x;
	return 0;
}