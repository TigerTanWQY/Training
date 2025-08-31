#include <iostream>
using namespace std;

const int N = 1003;
int v1[N], v2[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int V1, V2, n;
	cin >> V1 >> V2 >> n;
	for(int i = 1; i <= n; ++i)
		cin >> v1[i] >> v2[i];
	cout.flush();
	return 0;
}