#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000003;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int x = *min_element(a + 1, a + n + 1), cnt = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i] >= x)
			++cnt;
	if(cnt > n / 2)
		cout << "Bob";
	else
		cout << "Alice";
	cout.flush();
	return 0;
}