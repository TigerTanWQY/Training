#include <iostream>
#include <utility>
using namespace std;

pair<int, int> a[1000003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("g.in", "r", stdin);
	freopen("g.out", "w", stdout);
	int mx, my, nx, ny, n;
	cin >> mx >> my >> nx >> ny >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}