#include <iostream>
using namespace std;

const int N = 200003;
int a[N], b[N], pos[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		b[i] = i;
	for(int i = 1; i <= m; ++i)
		swap(b[a[i]], b[a[i] + 1]);
	for(int i = 1; i <= n; ++i)
		pos[b[i]] = i;
	for(int i = 1; i <= n; ++i)
		b[i] = i;
	for(int i = 1; i <= m; ++i) {
		if(b[a[i]] == 1)
			cout << pos[b[a[i] + 1]] << '\n';
		else if(b[a[i] + 1] == 1)
			cout << pos[b[a[i]]] << '\n';
		else
			cout << pos[1] << '\n';;
		swap(b[a[i]], b[a[i] + 1]);
	}
	return 0;
}
